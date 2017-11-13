//
// Created by Cedric De Schepper on 13/11/17.
//

#ifndef GRADIUS_GAME_H
#define GRADIUS_GAME_H

#include "Entity.h"
#include <map>

class Game {
    std::map<std::pair<int,int>, Entity> field;

    unsigned int lives;



};


#endif //GRADIUS_GAME_H
