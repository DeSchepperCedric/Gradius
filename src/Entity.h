/**
 * @class model::Entity
 *
 * @brief Base class for all interacting entities
 *
 * @author Cedric De Schepper
 *
 */

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

    struct Actions{
        bool move_up = false;
        bool move_down = false;
        bool move_left = false;
        bool move_right = false;
        bool shoot = false;
    };

class Entity : public observer::Subject {

protected:
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



    virtual void check_borders();


private:
    void move_right(double time);

    void move_left(double time);

    void move_up(double time);

    void move_down(double time);


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

    void move(const Actions& actions, double time);

    Co get_center() const;

    virtual void update(double time) = 0;

    // used for colision handling
    float get_radius();

    int get_health() const;

    int get_damage() const;

    void lose_lives(int damage);

    void check_lives();

    bool is_destroyed() const;

    void set_destroyed(bool destroyed);

    virtual const std::string get_name() const = 0;
};

}


#endif //GRADIUS_ENTITY_H
