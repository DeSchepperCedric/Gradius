//
// Created by Cedric De Schepper on 15/11/17.
//

#include "Controller.h"
#include <iostream>
using std::cout;
using std::endl;

namespace controller {

    void Controller::set_Model(std::shared_ptr<model::Model> model) {
        Controller::model = model;
    }


    void Controller::move_player_down() {
        Controller::model->get_player()->move_down();
    }
}