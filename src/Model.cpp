//
// Created by Cedric De Schepper on 15/11/17.
//

#include "Model.h"

namespace model{

    const std::shared_ptr<PlayerShip>& Model::get_player() const {
        return player;
    }

    void Model::set_player(std::shared_ptr<PlayerShip> player) {
        Model::player = player;
    }

    void Model::add_entity(std::shared_ptr<Entity> entity) {
        entities.push_back(entity);
    }
}

