/**
 * @class model::Bullet
 *
 * @brief Bullet entity : fired by ships
 *
 * @author Cedric De Schepper
 *
 */

#ifndef GRADIUS_BULLET_H
#define GRADIUS_BULLET_H

#include "Entity.h"

namespace model {

    enum Direction {LEFT, RIGHT, UP, DOWN, NONE};

    class Bullet : public Entity {
    private:
        Direction direction;

    public:

        Bullet(float x_position, float y_position, float speed, Direction direction);

        /**
         * @brief move bullet in the right direction
         * @param time determines movement distance
         */
        void update(double time) override;

        /**
         * @brief get name
         * @return "Bullet"
         */
        const std::string get_name() const override;

    };
}


#endif //GRADIUS_BULLET_H
