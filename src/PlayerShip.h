//
// Created by Cedric De Schepper on 13/11/17.
//

#ifndef GRADIUS_PLAYERSHIP_H
#define GRADIUS_PLAYERSHIP_H

#include "Ship.h"

namespace model {

    class PlayerShip : public Ship {
        // invincibility so you don't instanly die after hitting your world
        // doesn't apply to other colissions with non-world entity
        double max_invicibility = 5.0;

        double remaining_invicibility = 0.0;
    public:

        PlayerShip(float length, float height, float x_position, float y_position, float speed, int health, int damage,
                   double time_before_shot);

        virtual void check_borders() override;

        const std::string get_name() const override;

        void update(double time) override;

        double get_remaining_invicibility_after_colission() const;

        void reset_remaining_invicibility();

        Co get_gun_position() override;
    };

}

#endif //GRADIUS_PLAYERSHIP_H
