/**
 * @class model::PlayerShip
 *
 * @brief PlayerShip entity : ship entity that the player can control
 *
 * @author Cedric De Schepper
 *
 */

#ifndef GRADIUS_SHIP_H
#define GRADIUS_SHIP_H

#include "Entity.h"

namespace model {
    class Ship : public Entity {
    protected:
        double remaining_time_before_shot = 0.0;
        double time_before_shot;
    public:
        typedef std::shared_ptr<Ship> Shared;

        Ship(float length, float height, float x_position, float y_position, float speed, int health, int damage,
             double time_before_shot);

        /**
         * @brief : determines position of its gun
         * @return gun coordinates
         */
        virtual Co get_gun_position() = 0;

        /**
         * @brief determines if ship can fire. If it can, reset remaining_time_before_shot
         * @return True if ship can fire. False if not
         */
        bool shoot();

        /**
         * @brief update ship
         * @param time
         */
        void update(double time) override = 0;

        /**
         * @brief get name of the entity
         * @return "Ship"
         */
        const std::string get_name() const override  = 0;

        /**
         * @brief updates time before ship can fire
         * @param time
         */
        void update_gun_timer(double time);

    };

}


#endif //GRADIUS_SHIP_H
