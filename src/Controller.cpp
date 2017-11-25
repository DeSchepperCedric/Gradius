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

    void Controller::update() {
        Controller::model->get_player()->update();
    }

    void Controller::execute_key_presses() {
        bool up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        bool down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
        bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

        model->get_player()->move(up, down, left, right);
    }
}