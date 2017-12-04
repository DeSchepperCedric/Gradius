//
// Created by Cedric De Schepper on 3/12/17.
//

#include "EnemyShip.h"


namespace model {
    EnemyShip::EnemyShip(float length, float height, float x_position, float y_position, float speed, int health,
                         int damage, double time_before_shot) : Ship(length, height, x_position, y_position, speed,
                                                                     health, damage, time_before_shot) {}

    const std::string EnemyShip::get_name() const {
        return "EnemyShip";
    }

    Co EnemyShip::get_gun_position() {
        Co gun;
        gun.x = x_position - 0.55f;
        gun.y = y_position - (height / 2) + 0.10f;
        return gun;
    }

    void EnemyShip::update(double time) {
        update_gun_timer(time);

        move(false,false,true,false,time);
    }
}