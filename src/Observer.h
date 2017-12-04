/**
 * @class observer::Observer
 *
 * @brief Observer of the Observer Patern
 *
 * @author Cedric De Schepper
 *
 */

#ifndef GRADIUS_OBSERVER_H
#define GRADIUS_OBSERVER_H

#include <memory>
#include "Notification.h"

namespace observer {

    class Observer {
    public:
        typedef std::shared_ptr<observer::Observer> Shared;
        typedef std::weak_ptr<observer::Observer> Weak;

        /**
         * @brief processes notification sent by subject (Observer Pattern)
         * @param notification
         */
        virtual void on_notification(const Notification& notification) =0;
    };

}


#endif //GRADIUS_OBSERVER_H
