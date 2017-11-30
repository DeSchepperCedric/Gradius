//
// Created by Cedric De Schepper on 15/11/17.
//

#include "Model.h"
#include "Bullet.h"
#include "World.h"

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

        if(ent1->get_name() == "PlayerShip" and ent2->get_name() == "World"){
            cout << "lives: "<<ent1->get_health()<<endl;
            std::shared_ptr<PlayerShip> player = std::dynamic_pointer_cast<PlayerShip>(ent1);
            if(player->get_remaining_invicibility_after_colission() > 0.0) return;
            else{
                player->reset_remaining_invicibility();
            }
        }


        cout << "collision with "<< ent1->get_name() << " and "<<ent2->get_name()<<endl;
        ent1->lose_lives(ent2->get_damage());

        ent2->lose_lives(ent1->get_damage());

        ent1->check_lives();

        ent2->check_lives();
        // only ent1 can be the Playership
        // Player gets passed in check_for_collisions as first argument
        // Player destroys every entity on impact except world entities
        if((ent1->get_name() == "PlayerShip") and (ent2->get_name() != "World")){
            ent2->set_destroyed(true);
        }
        if(ent1->get_name() == "PlayerShip"){
            cout << "okay lives : "<<ent1->get_health()<<endl;
        }
        if(ent2->get_name() == "PlayerShip"){
            cout << "okay lives : "<<ent2->get_health()<<endl;
        }

    }

    void Model::check_for_collisions(const Entity::Shared &entity) {
        if(entity.use_count() == 0) return;
        //  world entities dont 'change' position so only have to check colission with non-world entities
        if(entity->get_name() == "World") return;

        if(entity->get_name() != "PlayerShip"){
            check_colission_with_non_world_entities(entity, player);
        }


        // check colission with other entities
        for(const Entity::Shared& other: entities){
            if((entity == other) or other->is_destroyed()) continue;

            // colission with world means moving out of its way
            if(other->get_name() == "World"){
                check_colission_with_world(other, entity);
            }
            else{
                check_colission_with_non_world_entities(entity, other);
            }
        }
    }

    void Model::remove_destroyed_entities() {
        for(auto it = entities.begin(); it != entities.end();){
            if((*it)->is_destroyed()){
               if((*it)->get_name() == "World" and (*it)->get_y_position() == (*it)->get_max_y_position()){
                    //World::Shared world = std::dynamic_pointer_cast<World>((*it));
                    //respawn_world_entity(world);
                   std::shared_ptr<World> upper1 = std::make_shared<World>(8.0,0.25, 4.0, 3.0, 2.0, -1,2);
                   add_entity(std::move(upper1));
                   //std::shared_ptr<World> upper2 = std::make_shared<World>(8.0,0.25, 3.9, 3.0, 2.0, -1,2);
                   //add_entity(std::move(upper2));


                }
                else if((*it)->get_name() == "World"){
                   std::shared_ptr<World> lower = std::make_shared<World>(8.0,0.25, 4.0, -3.0 + 0.25, 2.0, -1,2);
                   add_entity(std::move(lower));
               }


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

    void Model::create_all_world_entities() {
        std::shared_ptr<World> upper1 = std::make_shared<World>(8.0,0.25, -4.0, 3.0, 2.0, -1,2);
        add_entity(std::move(upper1));
        std::shared_ptr<World> upper2 = std::make_shared<World>(8.0,0.25, 4.0, 3.0, 2.0, -1,2);
        add_entity(std::move(upper2));

        std::shared_ptr<World> lower1 = std::make_shared<World>(8.0,0.25, -4.0, -3.0 + 0.25, 2.0, -1,2);
        add_entity(std::move(lower1));
        std::shared_ptr<World> lower2 = std::make_shared<World>(8.0,0.25, 4.0, -3.0 + 0.25, 2.0, -1,2);
        add_entity(std::move(lower2));
    }

    void Model::check_colission_with_world(const Entity::Shared &world, const Entity::Shared &other) {

        if(other->get_name() == "world") return;



        Hitbox world_hitbox = world->get_hitbox();


        Hitbox other_hitbox = other->get_hitbox();


        if((other_hitbox.max_y > world_hitbox.min_y) and(world_hitbox.max_y == world->get_max_y_position())){
            collision(other, world);
            // move entity down so it doesnt touch hitbox again
            bool colission = true;
            while(colission){
                double time = 0.01;
                other->move(false, true,false,false,time);
                other_hitbox = other->get_hitbox();
                if(other_hitbox.max_y < world_hitbox.min_y){
                    colission = false;
                }
            }
        }
        else if((other_hitbox.min_y < world_hitbox.max_y)and(world_hitbox.min_y == world->get_min_y_position())){
            collision(other, world);
            cout << "or here"<<endl;
            // move entity down so it doesnt touch hitbox again
            bool colission = true;
            while(colission){

                double time = 0.01;
                other->move(true,false,false,false,time);
                other_hitbox = other->get_hitbox();
                if(other_hitbox.min_y > world_hitbox.max_y){
                    colission = false;
                }
            }
        }


    }

    void Model::check_colission_with_non_world_entities(const Entity::Shared &entity, const Entity::Shared &other) {
        Co c1 = entity->get_center();
        Co c2 = other->get_center();

        float distance = powf((powf((c2.x - c1.x), 2.0f) +  powf((c2.y - c1.y), 2.0f)), (0.5f));

        if(distance < (other->get_radius() + entity->get_radius())){
            collision(entity, other);
        };


    }




}

