/**
 * @class observer::Subject
 *
 * @brief Subject of the Observer Patern
 *
 * @author Cedric De Schepper
 *
 */
#ifndef GRADIUS_SUBJECT_H
#define GRADIUS_SUBJECT_H

#include "Observer.h"

#include <vector>

namespace observer {

    class Subject {
    private:
        std::vector<Observer::Weak> observers;

    public:

        /**
         * @brief register an observer to observe the subject
         * @param observer
         */
        void register_observer(Observer::Weak observer);

        /**
         * @brief unregister an observer that observes the subject
         * @param observer
         */
        void unregister_observer(Observer::Shared observer);

        /**
         * @brief notify all observers of a notification
         * @param notification
         */
        void notify(const Notification& notification);
    };
}


#endif //GRADIUS_SUBJECT_H
