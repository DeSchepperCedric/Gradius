/**
 * @class Game
 *
 * @brief class that runs the Gradius game
 *
 * @author Cedric De Schepper
 *
 */
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

    /**
     * @brief runs the game using a game loop
     */
    void run();
};


#endif //GRADIUS_GAME_H
