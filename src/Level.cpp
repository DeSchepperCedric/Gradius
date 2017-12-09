
#include "Level.h"

#include <iostream>

namespace model{

    void Level::add_wave(const Wave::Shared &wave) {
        waves.push(wave);
    }

    const Wave::Shared& Level::deploy_wave() {
        return waves.front();
    }

    bool Level::level_done() const {
        return waves.empty();
    }



    void Level::pop_wave() {
        waves.pop();
    }

}