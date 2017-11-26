//
// Created by Cedric De Schepper on 26/11/17.
//

#include "Ship.h"


model::Ship::Ship(float length, float height, float x_position, float y_position, float speed, double time_before_shot)
        : Entity(length, height, x_position, y_position, speed), time_before_shot(time_before_shot) {
    name = "Ship";
}
