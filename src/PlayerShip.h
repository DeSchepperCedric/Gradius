//
// Created by Cedric De Schepper on 13/11/17.
//

#ifndef GRADIUS_PLAYERSHIP_H
#define GRADIUS_PLAYERSHIP_H

#include "MovingEntity.h"

namespace model {

    class PlayerShip : public MovingEntity {
    public:
        PlayerShip(double length, double height, double x_position, double y_position, double speed);

    };

}

#endif //GRADIUS_PLAYERSHIP_H
