//
// Created by Cedric De Schepper on 13/11/17.
//

#include "PlayerShip.h"

namespace model {


    PlayerShip::PlayerShip(float length, float height, float x_position, float y_position, float max_speed,
                           float acceleration) : MovingEntity(length, height, x_position, y_position, max_speed,
                                                              acceleration) {}
}
