//
// Created by Cedric De Schepper on 13/11/17.
//

#include "Entity.h"

#include <iostream>
namespace model {

    Entity::Entity(float length, float height, float x_position, float y_position, float speed) :
            length(length),
            height(height),
            x_position(x_position),
            y_position(y_position),
            speed(speed) {}



    const float Entity::get_length() const {
        return length;
    }

    const float Entity::get_height() const {
        return height;
    }

    float Entity::get_x_position() const {
        return x_position;
    }

    float Entity::get_y_position() const {
        return y_position;
    }

    float Entity::get_max_x_position() const {
        return max_x_position;
    }

    float Entity::get_min_x_position() const {
        return min_x_position;
    }

    float Entity::get_max_y_position() const {
        return max_y_position;
    }

    float Entity::get_min_y_position() const {
        return min_y_position;
    }

    void Entity::move_down(const double time) {
        y_position -= (speed * time);
    }

    void Entity::move_up(const double time) {
        y_position += (speed * time);
    }

    void Entity::move_right(const double time) {
        x_position += (speed * time);

    }

    void Entity::move_left(const double time) {
        x_position -= (speed * time);
    }

    void Entity::check_borders() {
        if(x_position > max_x_position){
            destroy();
            return;
        }

    }

    void Entity::move(bool up, bool down, bool left, bool right, const double time) {
        bool change = false;
        // vertical movement
        if(!up and !down){

        }
        else if(up and !down){
            move_up(time);
            change = true;
        }
        else if(down and !up){
            move_down(time);
            change = true;
        }

        // horizontal movement
        if(!left and !right){

        }
        else if(left and !right){
            move_left(time);
            change = true;
        }
        else if(right and !left){
            move_right(time);
            change = true;
        }


        // keeps entity between window borders
        check_borders();

        // notify observers of movement change
        if(change){
            notify(observer::MovementNotification());
        }

    }

    Hitbox Entity::get_hitbox() {
        Hitbox hitbox;

        hitbox.upper_left = {x_position, y_position};
        hitbox.lower_left = {x_position, y_position - height};

        hitbox.upper_right = {x_position + length, y_position};
        hitbox.lower_right = {x_position + length, y_position - height};

        return hitbox;
    }

    const std::string &Entity::get_name() const {
        return name;
    }

    Co Entity::get_center() const {
        Co co;
        co.x = x_position + (length / 2);
        co.y = y_position - (height / 2);
        return co;
    }

    void Entity::update(double time) {}

    float Entity::get_speed() const {
        return speed;
    }

    void Entity::destroy() {
        observer::DestructionNotification notification(weak_entity);
        notify(notification);
    }

    void Entity::set_weak_entity(const std::weak_ptr<Entity> &weak_entity) {
        Entity::weak_entity = weak_entity;
    }

}
