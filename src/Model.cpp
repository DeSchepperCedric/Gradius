

#include "Model.h"
#include "Bullet.h"
#include "World.h"
#include "EnemyShip.h"

#include <iostream>
#include <math.h>
#include "vector"

using std::endl;
using std::cout;

namespace model{

    void Model::set_player(std::shared_ptr<PlayerShip> player) {
        Model::player = player;

        std::weak_ptr<const Entity> weak_entity(player);
        notify(observer::CreationNotification(player));
    }

    void Model::add_entity(const Entity::Shared& entity) {
        std::weak_ptr<Entity> weak_entity(entity);
        entities.push_back(entity);

        // notify observers of entity creation
        notify(observer::CreationNotification(weak_entity));
    }

    void Model::update_player(const Moves& actions, bool shoot, double time) {
        if(game_done) return;
        player->move(actions, time);
        if(shoot){
            Bullet::Shared bullet = ship_shoots(player);
            if(bullet != nullptr){
                add_entity(bullet);
            }

        }
    }

    Bullet::Shared Model::ship_shoots(const Ship::Shared& ship) {
        if(ship->shoot()){
            Co pos = ship->get_gun_position();

            if(ship->get_name() == "PlayerShip"){
                Bullet::Shared bullet = std::make_shared<Bullet>(pos.x, pos.y, (ship->get_speed() * 2), RIGHT);
                return std::move(bullet);
               // add_entity(std::move(bullet));
            }
            else{
                Bullet::Shared bullet = std::make_shared<Bullet>(pos.x, pos.y, (ship->get_speed() * 2), LEFT);
                return std::move(bullet);
                //add_entity(std::move(bullet));
            }


        }
        return nullptr;

    }

    void Model::update_entities(double time) {
        if(game_done){
            return;
        }
        wave_timer += time;

        int old_health = player->get_health();
        // temporarily store bullet to avoid pushing bullets while looping through entities
        std::vector<Bullet::Shared> bullets;
        for(const Entity::Shared& entity: entities){
            if(entity->is_destroyed()) continue;

            entity->update(time);

            if(entity->get_name() == "EnemyShip"){
                auto enemy = std::static_pointer_cast<Ship>(entity);
                bullets.push_back(ship_shoots(enemy));
            }
        }
        // process bullets
        for(const Bullet::Shared& bullet : bullets) {
            if (bullet != nullptr) {
                add_entity(bullet);
            }
        }


        player->update(time);

        check_for_collisions();

        if(player->get_health() == 0){
            return game_over(false);
        }
        if(levels.empty() and entities.size() == 4){
            return game_over(true);
        }

        while(player->get_health() < old_health){
            const observer::LoseLifeNotification notification;
            notify(notification);
            old_health--;
        }

        remove_destroyed_entities();

        spawn_wave();
    }

    void Model::collision(const Entity::Shared& ent1, const Entity::Shared& ent2) {
        // reduce lives
        cout << "colission between " << ent1->get_name() <<" and "<< ent2->get_name()<<endl;
        if(ent1->get_name() == "PlayerShip" and ent2->get_name() == "World"){

            std::shared_ptr<PlayerShip> player = std::dynamic_pointer_cast<PlayerShip>(ent1);
            if(player->get_remaining_invicibility_after_colission() > 0.0) return;
            else{
                player->reset_remaining_invicibility();
            }
        }

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
            cout << "remaining lives : "<<ent1->get_health()<<endl;
        }
        if(ent2->get_name() == "PlayerShip"){
            cout << "remaining lives : "<<ent2->get_health()<<endl;
        }

    }

    void Model::check_for_collisions() {
        // check colissions between entities
        for(auto it1 = entities.begin(); it1 != entities.end(); it1++){

            if((*it1)->is_destroyed()) continue;

            for(auto it2 = (it1 + 1); it2 != entities.end(); it2++){
                if((*it2)->is_destroyed()) continue;

                // two world entities don't collide
                if(((*it1)->get_name() == "World") and ((*it2)->get_name() == "World")){
                    continue;
                }

                else if((*it1)->get_name() == "World"){
                    check_colission_with_world((*it1), (*it2));
                }
                else {
                    check_colission_with_non_world_entities((*it2), (*it1));
                }

            }

            // check colissions between the player and entities
            if((*it1)->get_name() == "World"){
                check_colission_with_world((*it1), player);
            }

            else{
                // player as first argument to make functions shorter
                check_colission_with_non_world_entities(player, (*it1));
            }
        }

    }

    void Model::remove_destroyed_entities() {

        for(auto it = entities.begin(); it != entities.end();){
            if((*it)->is_destroyed()){

                if((*it)->get_name() == "World"){
                   // std::shared_ptr<World> upper = std::make_shared<World>(8.0,0.25, 3.9, 3.0, 2.0, -1,2);
                  //  add_entity(std::move(upper));
                    (*it)->set_x_position(4.0f);
                    (*it)->set_destroyed(false);
                    it++;
                }
                else{
                    it = entities.erase(it);
                    const observer::DestructionNotification notification;

                    notify(notification);
                }



            }
            else{
                it++;
            }
        }
    }

    void Model::create_all_world_entities() {
        std::shared_ptr<World> upper1 = std::make_shared<World>(8.0f,0.25f, -4.0f, 3.0f, 2.0, -1,2);
        add_entity(std::move(upper1));
        std::shared_ptr<World> upper2 = std::make_shared<World>(8.0f,0.25f, 4.0f, 3.0f, 2.0, -1,2);
        add_entity(std::move(upper2));

        std::shared_ptr<World> lower1 = std::make_shared<World>(8.0f,0.25f, -4.0f, -3.0f + 0.25f, 2.0, -1,2);
        add_entity(std::move(lower1));
        std::shared_ptr<World> lower2 = std::make_shared<World>(8.0f,0.25f, 4.0f, -3.0f + 0.25f, 2.0, -1,2);
        add_entity(std::move(lower2));
    }

    void Model::check_colission_with_world(const Entity::Shared &world, const Entity::Shared &other) {

        Hitbox world_hitbox = world->get_hitbox();

        Hitbox other_hitbox = other->get_hitbox();

        if((other_hitbox.max_y > world_hitbox.min_y) and(world_hitbox.max_y == world->get_max_y_position())){
            collision(other, world);
            // move entity down so it doesnt touch hitbox again
            bool colission = true;
            while(colission){
                double time = 0.01;

                Moves actions;
                actions.move_down = true;

                other->move(actions,time);
                other_hitbox = other->get_hitbox();
                if(other_hitbox.max_y < world_hitbox.min_y){
                    colission = false;
                }
            }
        }
        else if((other_hitbox.min_y < world_hitbox.max_y)and (world_hitbox.min_y == world->get_min_y_position())){
            collision(other, world);
            // move entity up so it doesnt touch hitbox again
            bool colission = true;
            while(colission){
                double time = 0.01;
                Moves actions;
                actions.move_up = true;

                other->move(actions,time);

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

    void Model::add_level(const Level::Shared &level) {
        levels.push(level);
    }

    void Model::spawn_wave() {
        // if no more levels, game is over
        if(levels.empty()){
            return;
            // game done
        }
        // if no more waves, level is done
        if(levels.front()->level_done()){
            levels.pop();

            // if no more levels, game is over
            if(levels.empty()){
                return;
            }
        }
        Wave::Shared wave = levels.front()->deploy_wave();
        if(wave->get_time()> wave_timer) {

            return;
        }
        std::vector<Entity::Shared> test = wave->get_entities();

        for(const Entity::Shared& entity : wave->get_entities()){
            add_entity(entity);
        }
        levels.front()->pop_wave();
        reset_wave_timer();

    }

    void Model::reset_wave_timer() {
        wave_timer = 0.0;
    }

    void Model::game_over(bool win) {

        game_done = true;

        while(!entities.empty()){
            entities.pop_back();

        }

        while(!entities.empty()){
            levels.pop();
        }
        player.reset();

        observer::GameDoneNotification notification(win);
        notify(notification);
    }


}

