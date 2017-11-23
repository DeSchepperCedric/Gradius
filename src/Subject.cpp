//
// Created by Cedric De Schepper on 22/11/17.
//

#include "Subject.h"

namespace observer{

    void Subject::register_observer(Observer::Shared observer) {
        observers.push_back(observer);
    }

    void Subject::unregister_observer(Observer::Shared observer) {
        // using erase-remove idiom to find and erase all occurences of the observer
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

}