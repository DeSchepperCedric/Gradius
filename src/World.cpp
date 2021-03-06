

#include "World.h"

namespace model {

    World::World(float length, float height, float x_position, float y_position, float speed, int health,
                        int damage)
            : Entity(length, height, x_position, y_position, speed, health, damage){}

    const std::string World::get_name() const {
        return "World";
    }

    void World::update(double time) {
        Moves actions;
        actions.move_left = true;

        move(actions, time);

    }

}