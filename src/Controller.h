/**
 * @class controller::Controller
 *
 * @brief controller class of MVC
 *
 * @author Cedric De Schepper
 *
 */

#ifndef GRADIUS_CONTROLLER_H
#define GRADIUS_CONTROLLER_H

#include "Model.h"

namespace controller {

    class Controller {
    private:
        std::shared_ptr<model::Model> model;

    public:
        /**
         * @brief simple setter: set the model controlled by the Controller in MVC
         * @param model the model of MVC
         */
        void set_Model(std::shared_ptr<model::Model> model);

        /**
         * @brief process key presses
         * @param time
         */
        void execute_key_presses(double time);

        /**
         * @brief updates the model
         * @param time
         */
        void update_model(double time);
    };

}
#endif //GRADIUS_CONTROLLER_H
