//
// Created by Cedric De Schepper on 15/11/17.
//

#ifndef GRADIUS_MODEL_H
#define GRADIUS_MODEL_H

#include <memory>
#include <vector>
#include "Entity.h"
#include "PlayerShip.h"

namespace model {

    class Model {
    private:
        std::vector<std::shared_ptr<Entity>> entities;

        std::shared_ptr<PlayerShip> player;

    public:
        typedef std::shared_ptr<Model> Shared;

        const std::shared_ptr<PlayerShip> &get_player() const;

        void add_entity(std::shared_ptr<Entity> entity);

        void set_player(std::shared_ptr<PlayerShip> player);
    };

}


#endif //GRADIUS_MODEL_H
