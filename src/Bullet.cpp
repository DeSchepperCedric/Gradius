//
// Created by Cedric De Schepper on 26/11/17.
//

#include "Bullet.h"

#include <iostream>

namespace model {
    Bullet::Bullet(float x_position, float y_position, float speed,
                          model::Direction direction) :
            Entity(0.40f, 0.20f, x_position + 0.08f, (y_position + 0.10f), speed, 1,1),
                                                        direction(direction) {
        name = "Bullet";

    }

    void Bullet::update(double time) {

        switch(direction){
            case DOWN:
                move(false, true, false, false, time);
                break;

            case UP:
                move(true, false, false, false, time);
                break;

            case LEFT:
                move(false, false, true, false, time);
                break;

            case RIGHT:
                move(false, false, false, true, time);

                break;

            case NONE:
                break;
        }

    }

}
