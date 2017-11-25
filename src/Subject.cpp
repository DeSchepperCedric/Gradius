//
// Created by Cedric De Schepper on 22/11/17.
//

#include "Subject.h"

#include <algorithm>

namespace observer{

    void Subject::register_observer(Observer::Shared observer) {
        observers.push_back(observer);
    }

    void Subject::unregister_observer(Observer::Shared observer) {
        // using erase-remove idiom to find and erase all occurences of the observer
        auto it = std::find(observers.begin(), observers.end(), observer);
        observers.erase(it);
    }

}