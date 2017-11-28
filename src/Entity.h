    //
// Created by Cedric De Schepper on 13/11/17.
//

#ifndef GRADIUS_ENTITY_H
#define GRADIUS_ENTITY_H

#include <memory>
#include "Subject.h"

#include <typeindex>

namespace model{

    struct Co {
        float x;
        float y;
    };

    struct Hitbox {
        float max_x;
        float max_y;

        float min_x;
        float min_y;
    };

class Entity : public observer::Subject {
protected:
    std::string name = "Entity";

    float length;
    float height;

    // coordinates of most upper left corner
    float x_position;
    float y_position;

    float max_x_position = 4;
    float min_x_position = -4;

    float max_y_position = 3;
    float min_y_position = -3;

    float speed;

    int health;
    int damage;

    bool destroyed = false;

    void move_right(const double time);

    void move_left(const double time);

    void move_up(const double time);

    void move_down(const double time);

    virtual void check_borders();





public:
    typedef std::shared_ptr<Entity> Shared;

    Entity(float length, float height, float x_position, float y_position, float speed, int health, int damage);

    const float get_length() const;

    const float get_height() const;

    float get_x_position() const;

    float get_y_position() const;

    float get_max_x_position() const;

    float get_min_x_position() const;

    float get_max_y_position() const;

    float get_min_y_position() const;

    float get_speed() const;

    Hitbox get_hitbox();

    const std::string &get_name() const;

    void move(bool up, bool down, bool left, bool right, double time);

    Co get_center() const;

    virtual void update(const double time);

    // used for colision handling
    float get_radius();

    int get_health() const;

    int get_damage() const;

    void lose_lives(int lives);

    void check_lives();

    bool is_destroyed() const;


};

}


#endif //GRADIUS_ENTITY_H
