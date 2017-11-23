//
// Created by Cedric De Schepper on 22/11/17.
//

#ifndef GRADIUS_OBSERVER_H
#define GRADIUS_OBSERVER_H

#include <memory>
#include "Notification.h"

namespace observer {

    class Observer {
    public:
        typedef std::shared_ptr<observer::Observer> Shared;

        virtual void on_notification(const Notification& notification) =0;
    };

}


#endif //GRADIUS_OBSERVER_H
