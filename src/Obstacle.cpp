//
// Created by Cedric De Schepper on 27/11/17.
//

#include "Obstacle.h"

namespace model{

    void Obstacle::update(const double time) {
        move(false, false, true, false, time);

    }

    Obstacle::Obstacle(float length, float height, float x_position, float y_position, float speed, int health,
                       int damage) : Entity(length, height, x_position, y_position, speed, health, damage) {
    }

    const std::string Obstacle::get_name() const {
        return ((health < 0) ? "IndestructableObstacle" : "DestructableObstacle");
    }
}