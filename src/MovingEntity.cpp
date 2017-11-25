//
// Created by Cedric De Schepper on 13/11/17.
//

#include "MovingEntity.h"
#include "Notification.h"

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
        horizontal_speed = 0.0;
    }

    void MovingEntity::stop_vertical_movement() {
        vertical_speed = 0.0;
    }

    void MovingEntity::move(bool up, bool down, bool left, bool right) {
        bool change = false;
        // vertical movement
        if(!up and !down){
            stop_vertical_movement();
        }
        else if(up and !down){
            move_up();
            change = true;
        }
        else if(down and !up){
            move_down();
            change = true;
        }

        // horizontal movement
        if(!left and !right){
            stop_horizontal_movement();
        }
        else if(left and !right){
            move_left();
            change = true;
        }
        else if(right and !left){
            move_right();
            change = true;
        }

        // keeps speed below maximum speed
        check_speed();

        x_position += horizontal_speed;
        y_position += vertical_speed;

        // keeps entity between window borders
        check_borders();

        // notify observers of movement change
        if(change){
            notify(observer::MovementNotification());
        }
    }


    void MovingEntity::update() {
    }




}