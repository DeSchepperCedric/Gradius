//
// Created by Cedric De Schepper on 13/11/17.
//

#include "MovingEntity.h"
#include <iostream>
#include <math.h>
using std::cout;
using std::endl;

namespace model {



    void MovingEntity::move_down() {
        vertical_speed -= acceleration;
    }

    void MovingEntity::move_up() {
        vertical_speed += acceleration;
    }

    void MovingEntity::move_right() {
        horizontal_speed += acceleration;
    }

    void MovingEntity::move_left() {
        horizontal_speed -= acceleration;
    }

    MovingEntity::MovingEntity(float length, float height, float x_position, float y_position, float max_speed,
                               float acceleration) : Entity(length, height, x_position, y_position),
                                                     max_speed(max_speed), acceleration(acceleration) {}

    void MovingEntity::check_speed() {
        if(horizontal_speed >= max_speed){
            horizontal_speed = max_speed;
        }
        if(-horizontal_speed >= max_speed){
            horizontal_speed = -max_speed;
        }

        if(vertical_speed >= max_speed){
            vertical_speed = max_speed;
        }
        if(-vertical_speed >= max_speed){
            vertical_speed = -max_speed;
        }
    }

    void MovingEntity::check_borders() {
        if(x_position  < min_x_position){
            x_position = min_x_position;
        }
        else if(x_position +length > max_x_position){
            x_position = max_x_position - length;
        }

        if(y_position > max_y_position){
            y_position = max_y_position;
        }
        else if(y_position - height < min_y_position){
            y_position = min_y_position + height;
        }
    }


    void MovingEntity::stop_horizontal_movement() {
        if(horizontal_speed > 0){

            horizontal_speed = 0.00;
        }
        if(horizontal_speed < 0){

            horizontal_speed = 0.00;
        }

        if(fabsf(horizontal_speed) <= 0.005 and fabsf(horizontal_speed) > 0){
            horizontal_speed = 0;
        }
    }

    void MovingEntity::stop_vertical_movement() {
        if(vertical_speed > 0){

            vertical_speed = 0.00;
        }
        if(vertical_speed < 0){

            vertical_speed = 0.00;
        }

        if(fabsf(vertical_speed) <= 0.005 and fabsf(vertical_speed) > 0){
            vertical_speed = 0;
        }
    }


    void MovingEntity::update() {
        check_speed();

        x_position += horizontal_speed;
        y_position += vertical_speed;

        check_borders();
    }




}