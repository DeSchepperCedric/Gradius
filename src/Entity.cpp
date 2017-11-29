//
// Created by Cedric De Schepper on 13/11/17.
//

#include "Entity.h"

#include <iostream>
#include <math.h>

namespace model {

    Entity::Entity(float length, float height, float x_position, float y_position, float speed, int health, int damage) : length(
            length), height(height), x_position(x_position), y_position(y_position), speed(speed), health(health), damage(damage) {

    }



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
        Hitbox hitbox = get_hitbox();

        if(hitbox.min_x > max_x_position){
            std::cout <<"DAM1"<<std::endl;
            destroyed = true;
        }
        else if(hitbox.max_x < min_x_position){
            std::cout <<"DAM2"<<std::endl;
            destroyed = true;
        }
        else if(hitbox.min_y > max_y_position){
            destroyed = true;
        }
        else if(hitbox.max_y < min_x_position){
            destroyed = true;
        }
    }

    void Entity::move(bool up, bool down, bool left, bool right, const double time) {
        bool change = false;
        // vertical movement
        if(up and !down){
            move_up(time);
            change = true;
        }
        else if(down and !up){
            move_down(time);
            change = true;
        }

        // horizontal movement
        if(left and !right){
            move_left(time);
            change = true;
        }
        else if(right and !left){
            move_right(time);
            change = true;
        }

        // for Player : keeps ship between window borders
        // for other entities: destroy when completely out of bounds
        check_borders();

        // notify observers of movement change
        if(change and !destroyed){
            notify(observer::MovementNotification());
        }
    }

    Hitbox Entity::get_hitbox() {
        Hitbox hitbox;

        hitbox.min_x = x_position;
        hitbox.max_x = x_position + length;

        hitbox.min_y = y_position - height;
        hitbox.max_y = y_position;

        return hitbox;
    }

    Co Entity::get_center() const {
        Co co;
        co.x = x_position + (length / 2);
        co.y = y_position - (height / 2);
        return co;
    }

    void Entity::update(const double time) {}

    float Entity::get_speed() const {
        return speed;
    }

    float Entity::get_radius() {
       return powf((powf((length / 2.0f), 2.0f) + powf((height / 2.0f), 2.0f)), (0.5f));


    }

    int Entity::get_health() const {
        return health;
    }

    int Entity::get_damage() const {
        return damage;
    }

    void Entity::lose_lives(int damage) {
        if(health < 0){
            return;
        }

        health = std::max(0, health - damage);
    }

    void Entity::check_lives() {
        if(health == 0){
            destroyed = true;
        }
    }


    bool Entity::is_destroyed() const {
        return destroyed;
    }

    void Entity::set_destroyed(bool destroyed) {
        Entity::destroyed = destroyed;
    }

}
