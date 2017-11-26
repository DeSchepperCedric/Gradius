//
// Created by Cedric De Schepper on 13/11/17.
//

#ifndef GRADIUS_PLAYERSHIP_H
#define GRADIUS_PLAYERSHIP_H

#include "Ship.h"

namespace model {

    class PlayerShip : public Ship {
    public:

        PlayerShip(float length, float height, float x_position, float y_position, float speed,
                   double time_before_shot);


    };

}

#endif //GRADIUS_PLAYERSHIP_H
