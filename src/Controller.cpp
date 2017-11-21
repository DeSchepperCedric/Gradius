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


    void Controller::move_player(bool up, bool down, bool left, bool right){
        if(!up and !down){
            model->get_player()->stop_vertical_movement();
        }
        else if(up and !down){
            model->get_player()->move_up();
        }
        else if(down and !up){
            model->get_player()->move_down();
        }

        if(!left and !right){
            model->get_player()->stop_horizontal_movement();
        }
        else if(left and !right){
            model->get_player()->move_left();
        }
        else if(right and !left){
            model->get_player()->move_right();
        }

    }

    void Controller::update() {
        Controller::model->get_player()->update();
    }

    void Controller::execute_key_presses() {
        bool up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        bool down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
        bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

        move_player(up, down, left, right);
    }
}