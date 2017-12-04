//
// Created by Cedric De Schepper on 15/11/17.
//

#include "Controller.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using std::cout;
using std::endl;

namespace controller {

    void Controller::set_Model(std::shared_ptr<model::Model> model) {
        Controller::model = model;

    }



    void Controller::execute_key_presses(double time) {
        bool up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        bool down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
        bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
        bool shoot = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

        model->update_player(up,down,left,right,shoot, time);
    }

    void Controller::update_model(double time) {
        model->update_entities(time);
    }
}