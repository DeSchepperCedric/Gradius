//
// Created by Cedric De Schepper on 15/11/17.
//

#include "Model.h"
#include "Bullet.h"
#include <iostream>

using std::endl;
using std::cout;

namespace model{

    void Model::set_player(std::shared_ptr<PlayerShip> player) {
        Model::player = player;

        std::weak_ptr<const Entity> weak_entity(player);
        notify(observer::CreationNotification(player));
    }

    void Model::add_entity(std::shared_ptr<Entity> entity) {
        std::weak_ptr<Model> temp(this->shared_from_this());

        entity->register_observer(temp);
        std::weak_ptr<Entity> weak_entity(entity);
        entity->set_weak_entity(weak_entity);


        entities.push_back(std::move(entity));
        std::cout << entities.size()<<endl;

        // notify observers of entity creation
        notify(observer::CreationNotification(weak_entity));
    }

    void Model::remove_entity(std::weak_ptr<const Entity> entity) {

        for(auto it = entities.begin(); it != entities.end(); it++){
            if((*it) == entity.lock()){

                // remove the entity from enties ==> lower reference count to 0
                entities.erase(it);

                std::weak_ptr<const Entity> weak(*it);
                const observer::DestructionNotification notification(weak);
                notify(notification);

                return;
            }
        }

    }

    void Model::update_player(bool up, bool down, bool left, bool right,bool shoot, double time) {

        player->move(up, down, left, right, time);
        if(shoot){
            player_shoots();
        }
    }

    void Model::player_shoots() {
        if(player->shoot()){
            Co pos = player->get_gun_position();

            std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(pos.x, pos.y, (player->get_speed() * 2), RIGHT);
            add_entity(std::move(bullet));
        }

    }

    void Model::update_entities(double time) {
        std::cout << entities.size();
        for(auto &entity : entities){
            entity->update(time);
        }

        player->update(time);
    }



    void Model::on_notification(const observer::Notification &notification) {
        if(auto destruction = dynamic_cast<const observer::DestructionNotification*>(&notification)){
            remove_entity(destruction->get_weak_entity());
        }
    }


}

