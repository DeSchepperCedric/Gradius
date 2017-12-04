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
        model::Actions action;
        action.move_up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        action.move_down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
        action.move_left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        action.move_right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
        action.shoot = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);



        model->update_player(action, time);
    }

    void Controller::update_model(double time) {
        model->update_entities(time);
    }
}