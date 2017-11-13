//
// Created by Cedric De Schepper on 13/11/17.
//

#include "MovingEntity.h"

MovingEntity::MovingEntity(int length, int height, int x_position, int y_position, int speed) : Entity(
        length, height, x_position, y_position), speed(speed) {}

void MovingEntity::move_down() {
    if(y_position - 1 >= min_y_position){
        y_position -= 1;
    }
}

void MovingEntity::move_up() {
    if(y_position + 1 <= max_y_position){
        y_position += 1;
    }
}

void MovingEntity::move_right(){
    if(x_position + 1 <= max_x_position){
        x_position += 1;
    }
}

void MovingEntity::move_left(){
    if(x_position - 1 >= min_x_position){
        x_position -= 1;
    }
}