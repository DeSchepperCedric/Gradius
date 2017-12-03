//
// Created by Cedric De Schepper on 27/11/17.
//

#ifndef GRADIUS_OBSTACLE_H
#define GRADIUS_OBSTACLE_H

#include "Entity.h"

namespace model {
    class Obstacle : public Entity{
    public:
        Obstacle(float length, float height, float x_position, float y_position, float speed, int health, int damage);

        void update(const double& time) override;

        const std::string get_name() const override;
    };

}


#endif //GRADIUS_OBSTACLE_H
