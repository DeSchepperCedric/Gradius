
#include "Controller.h"
#include "Utilities.h"

#include <iostream>
#include <SFML/Graphics.hpp>
using std::cout;
using std::endl;

namespace controller {

    void Controller::set_Model(std::shared_ptr<model::Model> model) {
        Controller::model = model;
    }



    void Controller::execute_key_presses(double time) {
        model::Moves moves;
        moves.move_up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        moves.move_down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
        moves.move_left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        moves.move_right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
        bool shoot = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

        model->update_player(moves, shoot, time);
    }

    void Controller::update_model(double time) {
        model->update_entities(time);
    }
}