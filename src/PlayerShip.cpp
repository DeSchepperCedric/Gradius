//
// Created by Cedric De Schepper on 13/11/17.
//

#include "PlayerShip.h"

namespace model {



    PlayerShip::PlayerShip(float length, float height, float x_position, float y_position, float speed,
                           double time_before_shot) : Ship(length, height, x_position, y_position, speed,
                                                           time_before_shot) {
        name = "PlayerShip";
    }
}
