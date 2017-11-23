//
// Created by Cedric De Schepper on 22/11/17.
//

#ifndef GRADIUS_OBSERVER_H
#define GRADIUS_OBSERVER_H

#include <memory>

namespace observer {

    class Observer {
    public:
        typedef std::shared_ptr<observer::Observer> Shared;

    };
}


#endif //GRADIUS_OBSERVER_H
