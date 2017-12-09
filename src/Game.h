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
    controller::Controller::Unique controller;

    view::View::Shared view;

    bool set_up = false;

public:
    Game();

    /**
     * @brief runs the game using a game loop
     */
    void run();

    /**
     * @brief simple getter: gets if game was set up properly
     * @return set_up
     */
    bool is_set_up() const;

};


#endif //GRADIUS_GAME_H
