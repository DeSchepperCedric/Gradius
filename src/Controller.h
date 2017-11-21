//
// Created by Cedric De Schepper on 15/11/17.
//

#ifndef GRADIUS_CONTROLLER_H
#define GRADIUS_CONTROLLER_H

#include "Model.h"

namespace controller {

    class Controller {
    private:
        std::shared_ptr<model::Model> model;

    public:

        void set_Model(std::shared_ptr<model::Model> model);

        void move_player(bool up, bool down, bool left, bool right);

        void update();

        void execute_key_presses();
    };

}
#endif //GRADIUS_CONTROLLER_H
