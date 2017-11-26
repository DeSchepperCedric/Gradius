//
// Created by Cedric De Schepper on 15/11/17.
//

#include "Model.h"


namespace model{

    void Model::set_player(std::shared_ptr<PlayerShip> player) {
        Model::player = player;

        std::weak_ptr<const Entity> weak_entity(player);
        notify(observer::CreationNotification(player));
    }

    void Model::add_entity(std::shared_ptr<Entity> entity) {
        entities.push_back(entity);

        // notify observers of entity creation
        std::weak_ptr<const Entity> weak_entity(entity);
        notify(observer::CreationNotification(entity));
    }

    void Model::update_player(bool up, bool down, bool left, bool right, double time) {
        player->move(up, down, left, right, time);
    }
}

