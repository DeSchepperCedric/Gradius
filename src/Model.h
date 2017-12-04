/**
 * @class model::Model
 *
 * @brief Model of MVC that contains all game data
 */

#ifndef GRADIUS_MODEL_H
#define GRADIUS_MODEL_H

#include <memory>
#include <vector>

#include "Entity.h"
#include "PlayerShip.h"
#include "Subject.h"
#include "World.h"
#include "Bullet.h"

namespace model  {


    class Model: public observer::Subject{
    private:

        std::vector<std::shared_ptr<Entity>> entities;

        std::shared_ptr<PlayerShip> player;

        void check_for_collisions();

        /**
         *
         * @param ship
         * @return Bullet when ship can fire, otherwise null_ptr
         */
        Bullet::Shared ship_shoots(const Ship::Shared& ship);

        /**
         * @brief remove all destroyed entities from the model
         */
        void remove_destroyed_entities();

        /**
         * @brief handle collision between two entities
         * @param ent1 first entity
         * @param ent2 second entity
         */
        void collision(const Entity::Shared& ent1, const Entity::Shared& ent2);

        /**
         * @brief check if an entity collides with a world entity. If so, handle the colission
         * @param world world entity
         * @param other other entity
         */
        void check_colission_with_world(const Entity::Shared& world, const Entity::Shared& other);

        /**
         * @brief check if an entity collides with a non-world entity. If so, handle the colission
         * @param entity first entity
         * @param other  second entity
         */
        void check_colission_with_non_world_entities(const Entity::Shared& entity, const Entity::Shared& other);

    public:
        typedef std::shared_ptr<Model> Shared;

        /**
         * @brief add an entity to the model
         * @param entity entity to be addd
         */
        void add_entity(const Entity::Shared& entity);

        /**
         * @ brief set the PlayerShip
         */
        void set_player(std::shared_ptr<PlayerShip> player);

        /**
         * @brief process user input. Shoot/Move when needed
         * @param up
         * @param down
         * @param left
         * @param right
         * @param shoot
         * @param time
         */
        void update_player(const Actions& actions, double time);

        void update_entities(double time);

        /**
         * @brief create the world entities (upper and lower border)
         */
        void create_all_world_entities();

    };

}


#endif //GRADIUS_MODEL_H
