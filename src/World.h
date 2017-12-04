//
// Created by Cedric De Schepper on 29/11/17.
//

#ifndef GRADIUS_WORLD_H
#define GRADIUS_WORLD_H


#include "Entity.h"

namespace model {
    class World : public Entity{
    public:
        typedef std::shared_ptr<World> Shared;

        World(float length, float height, float x_position, float y_position, float speed, int health, int damage);

        const std::string get_name() const override;

        void update(double time) override;


    };
}


#endif //GRADIUS_WORLD_H
