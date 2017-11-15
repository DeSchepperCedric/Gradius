//
// Created by Cedric De Schepper on 13/11/17.
//

#ifndef GRADIUS_MOVINGENTITY_H
#define GRADIUS_MOVINGENTITY_H

#include "Entity.h"

class MovingEntity: public Entity  {
protected:
    double speed;

public:

    MovingEntity(double length, double height, double x_position, double y_position, double speed);

    void move_right();

    void move_left();

    void move_up();

    void move_down(float time);
};


#endif //GRADIUS_MOVINGENTITY_H
