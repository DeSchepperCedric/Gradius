//
// Created by Cedric De Schepper on 4/12/17.
//

#ifndef GRADIUS_LEVEL_H
#define GRADIUS_LEVEL_H

#include "Entity.h"

#include <vector>
#include <queue>
#include <memory>

namespace model {
    class Wave {
    private:


        double time = 0.0;
        // shared because they will be added to model
        std::vector<Entity::Shared> entities = {};

    public:
        typedef std::shared_ptr<Wave> Shared;

        double get_time() const;

        void set_time(double time);

        void add_entity(const Entity::Shared& entity);

        const std::vector<Entity::Shared> &get_entities() const;

    };



    class Level {
    private:
        std::queue<Wave::Shared> waves = {};

    public:
        typedef std::unique_ptr<Level> Unique;
        typedef std::shared_ptr<Level> Shared;

        Level() = default;

        void add_wave(const Wave::Shared& wave);

        const Wave::Shared& deploy_wave();

        bool level_done() const;

        void pop_wave();
    };

}


#endif //GRADIUS_LEVEL_H
