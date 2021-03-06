

#include "Obstacle.h"

namespace model{

    void Obstacle::update(double time) {
        Moves actions;
        actions.move_left = true;
        move(actions, time);

    }

    Obstacle::Obstacle(float length, float height, float x_position, float y_position, float speed, int health,
                       int damage) : Entity(length, height, x_position, y_position, speed, health, damage) {
    }

    const std::string Obstacle::get_name() const {
        // if health is negative : the obstacle is indestructable
        return ((health < 0) ? "IndestructableObstacle" : "DestructableObstacle");
    }
}