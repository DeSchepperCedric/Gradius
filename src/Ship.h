//
// Created by Cedric De Schepper on 26/11/17.
//

#ifndef GRADIUS_SHIP_H
#define GRADIUS_SHIP_H

#include "Entity.h"

namespace model {
    class Ship : public Entity {
    protected:
        double remaining_time_before_shot = 0.0;
        double time_before_shot;
    public:

        Ship(float length, float height, float x_position, float y_position, float speed, int health, int damage,
             double time_before_shot);

        Co get_gun_position();

        bool shoot();

        virtual void update(const double time);

        const std::string get_name() const = 0;

    };

}


#endif //GRADIUS_SHIP_H
