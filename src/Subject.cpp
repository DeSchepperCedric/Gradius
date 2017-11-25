//
// Created by Cedric De Schepper on 22/11/17.
//

#include "Subject.h"

#include <algorithm>

namespace observer{

    void Subject::register_observer(Observer::Weak observer) {
        observers.push_back(observer);
    }

    void Subject::unregister_observer(Observer::Shared observer) {

        auto it = observers.begin();

        do {
            if((*it).lock() == observer) break;
            it++;
        } while (it != observers.end());
        observers.erase(it);
    }

    void Subject::notify(const Notification &notification) {
        for(auto & observer : observers){
            observer.lock()->on_notification(notification);
        }
    }

}