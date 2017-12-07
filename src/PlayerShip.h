/**
 * @class model::PlayerShip
 *
 * @brief PlayerShip entity : ship entity that the player can control
 *
 * @author Cedric De Schepper
 *
 */

#ifndef GRADIUS_PLAYERSHIP_H
#define GRADIUS_PLAYERSHIP_H

#include "Ship.h"

namespace model {

    class PlayerShip : public Ship {
        // invincibility so you don't instanly die after hitting your world
        // doesn't apply to other colissions with non-world entity
        double max_invicibility = 5.0;

        // if invincibility is at 0.0, player can take damage
        double remaining_invicibility = 0.0;
    public:
        typedef std::shared_ptr<PlayerShip> Shared;

        PlayerShip(float length, float height, float x_position, float y_position, float speed, int health, int damage,
                   double time_before_shot);

        /**
         * @brief stop player from moving out of bounds
         */
        virtual void check_borders() override;

        /**
         * @brief get name
         * @return "PlayerShip"
         */
        const std::string get_name() const override;

        /**
         * @brief updates player : updates time before player can fire and
         *                         updates time before player can take damage by world
         * @param time
         */
        void update(double time) override;

        /**
         * @brief simple getter: gets remaining_invincibility before player can take damage by world
         * @return remaining_invicibility
         */
        double get_remaining_invicibility_after_colission() const;

        /**
         * @brief changes remaining_invincibility to max_invincibility after player takes damage by world entity
         */
        void reset_remaining_invicibility();

        /**
         * @brief : determines position of its gun
         * @return gun coordinates
         */
        Co get_gun_position() override;
    };

}

#endif //GRADIUS_PLAYERSHIP_H
