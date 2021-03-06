

#include "Entity.h"
#include "PlayerShip.h"

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

    void Entity::move_down(double time) {
        y_position -= (speed * time);
    }

    void Entity::move_up(double time) {
        y_position += (speed * time);
    }

    void Entity::move_right(double time) {
        x_position += (speed * time);

    }

    void Entity::move_left(double time) {
        x_position -= (speed * time);
    }

    void Entity::check_borders() {
        // if non-player entity is outside the game field : destroy the entity
        Hitbox hitbox = get_hitbox();

        if(hitbox.min_x > max_x_position){
            destroyed = true;
        }
        else if(hitbox.max_x < min_x_position){
            destroyed = true;
        }
        else if(hitbox.min_y > max_y_position){
            destroyed = true;
        }
        else if(hitbox.max_y < min_x_position){
            destroyed = true;
        }
    }

    void Entity::move(const Moves& actions, double time) {
        bool change = false;
        // vertical movement
        if(actions.move_up and !actions.move_down){
            move_up(time);
            change = true;
        }
        else if(actions.move_down and !actions.move_up){
            move_down(time);
            change = true;
        }

        // horizontal movement
        if(actions.move_left and !actions.move_right){
            move_left(time);
            change = true;
        }
        else if(actions.move_right and !actions.move_left){
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

    float Entity::get_speed() const {
        return speed;
    }

    float Entity::get_radius() {
        // calculate radius around entity for colission handling
        // using pythagoras
       return powf((powf((length / 2.0f), 2.0f) + powf((height / 2.0f), 2.0f)), (0.5f));
    }

    int Entity::get_health() const {
        return health;
    }

    int Entity::get_damage() const {
        return damage;
    }

    void Entity::lose_lives(int damage) {
        // if health is -1 : object is indestructable
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

    void Entity::set_x_position(float x_position) {
        Entity::x_position = x_position;
    }
}
