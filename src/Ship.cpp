//
// Created by Cedric De Schepper on 26/11/17.
//

#include "Ship.h"
#include "Bullet.h"

namespace model {


    Co Ship::get_gun_position() {
        Co gun;
        gun.x = x_position + length;
        gun.y = y_position - (height / 2);
        return gun;
    }

    bool Ship::shoot() {
        if(remaining_time_before_shot == 0.0){
            remaining_time_before_shot = time_before_shot;

            return true;

        }
        return false;
    }

    void Ship::update(const double& time) {
        remaining_time_before_shot -= time;
        if(remaining_time_before_shot < 0) remaining_time_before_shot = 0.0;
    }

    Ship::Ship(float length, float height, float x_position, float y_position, float speed, int health, int damage,
               double time_before_shot) : Entity(length, height, x_position, y_position, speed, health, damage),
                                          time_before_shot(time_before_shot) {}


}
