//
// Created by Cedric De Schepper on 13/11/17.
//

#ifndef GRADIUS_MOVINGENTITY_H
#define GRADIUS_MOVINGENTITY_H

#include "Entity.h"

class MovingEntity: public Entity  {
private:
    int speed;

public:

    MovingEntity(int length, int height, int x_position, int y_position, int speed);

    void move_right();

    void move_left();

    void move_up();

    void move_down();
};


#endif //GRADIUS_MOVINGENTITY_H
