/**
 * @class model::World
 *
 * @brief World entity : entities at the upper and lower border of the game that the player may not  hit
 *
 * @author Cedric De Schepper
 *
 */
#ifndef GRADIUS_WORLD_H
#define GRADIUS_WORLD_H


#include "Entity.h"

namespace model {
    class World : public Entity{
    public:
        typedef std::shared_ptr<World> Shared;

        World(float length, float height, float x_position, float y_position, float speed, int health, int damage);


        /**
         * @brief get name
         * @return "Bullet"
         */
        const std::string get_name() const override;

        /**
         * @brief move obstacle to the left
         * @param time determines movement distance
         */
        void update(double time) override;


    };
}


#endif //GRADIUS_WORLD_H
