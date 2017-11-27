//
// Created by Cedric De Schepper on 27/11/17.
//

#include "Obstacle.h"

namespace model{


    Obstacle::Obstacle(float length, float height, float x_position, float y_position, float speed) : Entity(length,
                                                                                                             height,
                                                                                                             x_position,
                                                                                                             y_position,
                                                                                                             speed) {
        name = "Obstacle";
    }

    void Obstacle::update(const double time) {
        move(false, false, true, false, time);

    }
}