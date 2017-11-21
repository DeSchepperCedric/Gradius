//
// Created by Cedric De Schepper on 13/11/17.
//

#ifndef GRADIUS_PLAYERSHIP_H
#define GRADIUS_PLAYERSHIP_H

#include "MovingEntity.h"

namespace model {

    class PlayerShip : public MovingEntity {
    public:

        PlayerShip(float length, float height, float x_position, float y_position, float max_speed, float acceleration);

    };

}

#endif //GRADIUS_PLAYERSHIP_H
