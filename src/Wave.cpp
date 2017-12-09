
#include "Wave.h"

namespace model{
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


}