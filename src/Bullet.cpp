
#include "Bullet.h"
#include "Entity.h"
#include "Utilities.h"

#include <iostream>

namespace model {
    Bullet::Bullet(float x_position, float y_position, float speed,
                          model::Direction direction) :
            Entity(0.40f, 0.20f, x_position, y_position, speed, 1,1),
                                                        direction(direction) {}

    void Bullet::update(double time) {
        Moves actions;
        switch(direction){
            case DOWN:
                actions.move_down = true;
                break;

            case UP:
                actions.move_up = true;
                break;

            case LEFT:
                actions.move_left = true;
                break;

            case RIGHT:
                actions.move_right = true;
                break;

            case NONE:
                break;
        }
        move(actions, time);

    }

    const std::string Bullet::get_name() const {
        return "Bullet";
    }

}
