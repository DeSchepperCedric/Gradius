//
// Created by Cedric De Schepper on 13/11/17.
//

#include "MovingEntity.h"
#include <iostream>
using std::cout;
using std::endl;

MovingEntity::MovingEntity(double length, double height, double x_position, double y_position, double speed) : Entity(
        length, height, x_position, y_position), speed(speed) {

}

void MovingEntity::move_down() {
    if((y_position - speed < (min_y_position + height))){
        // reached floor
        y_position = min_y_position + height;
    }
    else{

        y_position -= speed;}

}

void MovingEntity::move_up() {
    if(y_position- speed <= max_y_position){
        y_position += speed;
    }
    else{
        y_position = max_y_position;
    }
}

void MovingEntity::move_right(){
    if(x_position + 2 * length <= max_x_position){
        x_position += length;
    }
    else{
        x_position = max_x_position - length;
    }

}

void MovingEntity::move_left(){
    if(x_position - length >= min_x_position){
        x_position -= length;
    }
    else{
        x_position = min_x_position;
    }
}