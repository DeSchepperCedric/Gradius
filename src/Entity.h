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




private:
    /**
     * @brief move player right
     * @param time determines movement distance
     */
    void move_right(double time);

    /**
    * @brief move player left
    * @param time determines movement distance
    */
    void move_left(double time);

    /**
    * @brief move player up
    * @param time determines movement distance
    */
    void move_up(double time);

    /**
     * @brief move player down
     * @param time determines movement distance
     */
    void move_down(double time);

    /**
     * @brief   For non-player entities, set destroyed if out of bounds.
     *          For player, stop player from moving out of bounds
     */
    virtual void check_borders();

public:
    typedef std::shared_ptr<Entity> Shared;

    Entity(float length, float height, float x_position, float y_position, float speed, int health, int damage);

    /**
    * @brief simple getter: gets length
    * @return length
    */
    const float get_length() const;

    /**
     * @brief simple getter: gets height
     * @return height
     */
    const float get_height() const;

    /**
    * @brief simple getter: gets current x position
    * @return x_position
    */
    float get_x_position() const;

    /**
     * @brief simple getter: gets current y position
     * @return y_position
     */
    float get_y_position() const;

    /**
    * @brief simple getter: gets maximum x position the entity can have
    * @return max_x_position
    */
    float get_max_x_position() const;

    /**
    * @brief simple getter: gets minimum x position the entity can have
    * @return min_x_position
    */
    float get_min_x_position() const;

    /**
    * @brief simple getter: gets maximum y position the entity can have
    * @return max_y_position
    */
    float get_max_y_position() const;

    /**
     * @brief simple getter: gets minimum y position the entity can have
     * @return min_y_position
     */
    float get_min_y_position() const;

    /**
     * @brief simple setter: set x position of the entity
     * @param x_position new x position
     */
    void set_x_position(float x_position);

    /**
     * @brief simple speed getter
     * @return
     */
    float get_speed() const;

    /**
     * @brief calculates the entity's hitbox: max/min y and x coordinate
     * @return entity's hitbox
     */
    Hitbox get_hitbox();

    /**
     * @brief move entity in right direction
     * @param actions determines move directions
     * @param time determines movement distance
     */
    void move(const Actions& actions, double time);

    /**
     * @brief determine center of entity
     * @return center coordinates
     */
    Co get_center() const;

    /**
     * @brief updates the entity: performs actions for specific entities (ex. move)
     * @param time
     */
    virtual void update(double time) = 0;

    /**
     * @brief determines radius of circle around entity used by colission handling
     * @return radius
     */
    float get_radius();

    /**
     * @brief simple getter: gets health
     * @return health
     */
    int get_health() const;

    /**
     * @brief simple getter: gets damage
     * @return damage
     */
    int get_damage() const;

    /**
     * @brief deals damage to entity
     * @param damage
     */
    void lose_lives(int damage);

    /**
     * @brief checks if lives == 0. If so, sets entity as destroyed
     */
    void check_lives();

    /**
     * @brief simple getter: gets destroyed
     * @return destroyed
     */
    bool is_destroyed() const;

    /**
     * @brief simple setter: sets destroyed
     * @param destroyed
     */
    void set_destroyed(bool destroyed);

    /**
     * @brief get name
     * @return entity name
     */
    virtual const std::string get_name() const = 0;
};

}


#endif //GRADIUS_ENTITY_H
