//
// Created by Cedric De Schepper on 22/11/17.
//

#ifndef GRADIUS_SUBJECT_H
#define GRADIUS_SUBJECT_H

#include "Observer.h"

#include <vector>

namespace observer {

    class Subject {
    private:
        std::vector<Observer::Weak> observers;

    public:

        void register_observer(Observer::Weak observer);

        void unregister_observer(Observer::Shared observer);

        void notify(const Notification& notification);
    };
}


#endif //GRADIUS_SUBJECT_H
