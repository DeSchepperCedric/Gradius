//
// Created by Cedric De Schepper on 13/11/17.
//

#ifndef GRADIUS_MOVINGENTITY_H
#define GRADIUS_MOVINGENTITY_H

#include "Entity.h"

namespace model {

    class MovingEntity : public Entity {
    protected:
        float horizontal_speed = 0.0f;
        float vertical_speed = 0.0f;
        float max_speed;
        float acceleration;

        bool horizontal_change = false;
        bool vertical_change =false;

        void check_speed();

        void check_borders();

    public:

        MovingEntity(float length, float height, float x_position, float y_position, float max_speed,
                     float acceleration);

        void move(bool up, bool down, bool left, bool right, const double time);

        void move_right(const double time);

        void move_left(const double time);

        void move_up(const double time);

        void move_down(const double time);

        void stop_vertical_movement();

        void stop_horizontal_movement();

        void update();
    };

}


#endif //GRADIUS_MOVINGENTITY_H
