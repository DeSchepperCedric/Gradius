//
// Created by Cedric De Schepper on 15/11/17.
//

#ifndef GRADIUS_MODEL_H
#define GRADIUS_MODEL_H

#include <memory>
#include <vector>

#include "Entity.h"
#include "PlayerShip.h"
#include "Subject.h"

namespace model  {

    class Model: public observer::Subject{
    private:
        std::vector<std::shared_ptr<Entity>> entities;

        std::shared_ptr<PlayerShip> player;

        bool deletion_happened = false;

        float world_speed = 10.0f;

        void check_for_collisions(const Entity::Shared& entity);

        void collision(const Entity::Shared& ent1, const Entity::Shared& ent2);

        void player_shoots();

        void remove_destroyed_entities();

    public:
        typedef std::shared_ptr<Model> Shared;

        void add_entity(Entity::Shared entity);

        void remove_entity(std::weak_ptr<const Entity> entity);

        void set_player(std::shared_ptr<PlayerShip> player);

        void update_player(bool up, bool down, bool left, bool right,bool shoot, double time);

        void update_entities(double time);





    };

}


#endif //GRADIUS_MODEL_H
