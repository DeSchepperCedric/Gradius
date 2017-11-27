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


        void execute_key_presses(const double time);

        void update_model(const double time);
    };

}
#endif //GRADIUS_CONTROLLER_H
