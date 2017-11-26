//
// Created by Cedric De Schepper on 26/11/17.
//

#ifndef GRADIUS_SHIP_H
#define GRADIUS_SHIP_H

#include "Entity.h"

namespace model {
    class Ship : public Entity {
    protected:
        double time_before_shot = 0.0;
    public:

        Ship(float length, float height, float x_position, float y_position, float speed, double time_before_shot);

    };

}


#endif //GRADIUS_SHIP_H
