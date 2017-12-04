/**
 * @class model::Obstacle
 *
 * @brief Obstacle entity : obstacles that the player needs to navigate around or destroy if possible
 *
 * @author Cedric De Schepper
 *
 */

#ifndef GRADIUS_OBSTACLE_H
#define GRADIUS_OBSTACLE_H

#include "Entity.h"

namespace model {
    class Obstacle : public Entity{
    public:
        Obstacle(float length, float height, float x_position, float y_position, float speed, int health, int damage);

        /**
         * @brief move obstacle to the left
         * @param time determines movement distance
         */
        void update(double time) override;

        /**
         * @brief simple getter : get name
         * @return "DestructableObstacle" if it can be destroyed by bullets, else "IndestructableObstacle"
         */
        const std::string get_name() const override;
    };

}


#endif //GRADIUS_OBSTACLE_H
