//
// Created by Cedric De Schepper on 26/11/17.
//

#include "Ship.h"
#include "Bullet.h"

namespace model {

    bool Ship::shoot() {
        if(remaining_time_before_shot == 0.0){
            remaining_time_before_shot = time_before_shot;

            return true;

        }
        return false;
    }

    Ship::Ship(float length, float height, float x_position, float y_position, float speed, int health, int damage,
               double time_before_shot) : Entity(length, height, x_position, y_position, speed, health, damage),
                                          time_before_shot(time_before_shot) {}

    void Ship::update_gun_timer(double time) {
        remaining_time_before_shot -= time;
        if(remaining_time_before_shot < 0) remaining_time_before_shot = 0.0;
    }


}
