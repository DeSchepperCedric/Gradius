//
// Created by Cedric De Schepper on 15/11/17.
//

#include "Model.h"
#include "Bullet.h"

#include <iostream>
#include <math.h>

using std::endl;
using std::cout;

namespace model{

    void Model::set_player(std::shared_ptr<PlayerShip> player) {
        Model::player = player;

        std::weak_ptr<const Entity> weak_entity(player);
        notify(observer::CreationNotification(player));
    }

    void Model::add_entity(Entity::Shared entity) {
        std::weak_ptr<Entity> weak_entity(entity);
        entities.push_back(std::move(entity));

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
        for(const Entity::Shared& entity: entities){

            if(entity->is_destroyed()) continue;

            entity->update(time);
            check_for_collisions(entity);
        }




        player->update(time);
        check_for_collisions(player);

        remove_destroyed_entities();
    }



    void Model::collision(const Entity::Shared& ent1, const Entity::Shared& ent2) {
        // reduce lives

        ent1->lose_lives(ent2->get_damage());

        ent2->lose_lives(ent1->get_damage());

        ent1->check_lives();

        ent2->check_lives();

    }

    void Model::check_for_collisions(const Entity::Shared &entity) {
        if(entity.use_count() == 0) return;

        Co c1 = entity->get_center();
        Co c2;
        float distance;

        // check colission with player
        if(entity != player){

            c2 = player->get_center();



            distance = powf((powf((c2.x - c1.x), 2.0f) +  powf((c2.y - c1.y), 2.0f)), (0.5f));

            if(distance < (player->get_radius() + entity -> get_radius())){
                collision(player, entity);
            };
        }

        // check colission with other entities
        for(const Entity::Shared& other: entities){
            if((entity == other) or other->is_destroyed()) continue;


            c2 = other->get_center();

            distance = powf((powf((c2.x - c1.x), 2.0f) +  powf((c2.y - c1.y), 2.0f)), (0.5f));

            if(distance < (other->get_radius() + entity->get_radius())){

                collision(entity, other);
            };

        }

    }

    void Model::remove_destroyed_entities() {
        for(auto it = entities.begin(); it != entities.end();){
            if((*it)->is_destroyed()){
                entities.erase(it);

                std::weak_ptr<const Entity> weak(*it);
                const observer::DestructionNotification notification(weak);

                notify(notification);
            }
            else{
                it++;
            }
        }
    }


}

