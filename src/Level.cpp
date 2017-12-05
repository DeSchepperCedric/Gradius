
#include "Level.h"

#include <iostream>

namespace model{

    void Level::add_wave(const Wave::Shared &wave) {
        waves.push(std::move(wave));
    }

    const Wave::Shared& Level::deploy_wave() {
       // Wave::Shared wave = waves.front();

        return waves.front();
    }

    bool Level::level_done() const {
        return waves.empty();
    }

    double Wave::get_time() const {
        return time;
    }

    void Wave::set_time(double time) {
        Wave::time = time;
    }

    void Wave::add_entity(const Entity::Shared &entity) {
        entities.push_back(std::move(entity));
    }

    const std::vector<Entity::Shared> &Wave::get_entities() const {
        return entities;
    }

    void Level::pop_wave() {
        std::cout << "old wave size: " << waves.size()<<std::endl;
        waves.pop();
        std::cout << "new wave size: " << waves.size()<<std::endl;
    }

}