//
// Created by Cedric De Schepper on 23/11/17.
//

#ifndef GRADIUS_NOTIFICATION_H
#define GRADIUS_NOTIFICATION_H

#include <memory>
#include <string>
#include "Entity.h"

namespace observer {
    class Notification {
    public:
        virtual ~Notification() = default;
    };

    class MovementNotification : public Notification {
    public:
        MovementNotification() = default;
    };

    class EntityNotification : public Notification {
        std::weak_ptr<const model::Entity> weak_entity;

    public:
        explicit EntityNotification(const std::weak_ptr<const model::Entity> &weak_entity);

        const std::weak_ptr<const model::Entity> &get_weak_entity() const;
    };

    class DestructionNotification : public EntityNotification {
    public:
        explicit DestructionNotification(const std::weak_ptr<const model::Entity> &weak_entity);

    };

    class CreationNotification : public EntityNotification {
    public:
        explicit CreationNotification(const std::weak_ptr<const model::Entity> &weak_entity);
    };



}


#endif //GRADIUS_NOTIFICATION_H
