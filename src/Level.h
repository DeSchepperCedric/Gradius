//
// Created by Cedric De Schepper on 4/12/17.
//

#ifndef GRADIUS_LEVEL_H
#define GRADIUS_LEVEL_H

#include "Entity.h"

#include <vector>
#include <queue>

namespace model {
    struct Wave {
        double time;
        std::vector<std::string> entities;
    };



    class Level {
    private:
        std::queue<Wave> waves;

    public:

    };

}


#endif //GRADIUS_LEVEL_H
