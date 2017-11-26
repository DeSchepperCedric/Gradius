//
// Created by Cedric De Schepper on 13/11/17.
//

#ifndef GRADIUS_GAME_H
#define GRADIUS_GAME_H

#include "Controller.h"
#include "Model.h"
#include "View.h"

class Game {
private:
    controller::Controller controller;

    view::View::Shared view;

public:
    Game();


    void run();
};


#endif //GRADIUS_GAME_H
