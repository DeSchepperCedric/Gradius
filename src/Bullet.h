//
// Created by Cedric De Schepper on 26/11/17.
//

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

        void update(const double& time) override;

        const std::string get_name() const override;

    };
}


#endif //GRADIUS_BULLET_H
