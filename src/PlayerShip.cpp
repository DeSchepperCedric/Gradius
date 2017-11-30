//
// Created by Cedric De Schepper on 13/11/17.
//

#include "PlayerShip.h"

namespace model {


    void PlayerShip::check_borders() {



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

    PlayerShip::PlayerShip(float length, float height, float x_position, float y_position, float speed, int health,
                           int damage, double time_before_shot) : Ship(length, height, x_position, y_position, speed,
                                                                       health, damage, time_before_shot) {}

    const std::string PlayerShip::get_name() const {
        return "PlayerShip";
    }

    void PlayerShip::update(const double time) {
        remaining_time_before_shot -= time;
        if(remaining_time_before_shot < 0) remaining_time_before_shot = 0.0;

        remaining_invicibility_after_colission = std::max(0.0, remaining_invicibility_after_colission - time);
    }

    double PlayerShip::get_remaining_invicibility_after_colission() const {
        return remaining_invicibility_after_colission;
    }

    void PlayerShip::reset_remaining_invicibility() {
        remaining_invicibility_after_colission = invicibility_after_colission;
    }
}
