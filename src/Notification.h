
#ifndef GRADIUS_NOTIFICATION_H
#define GRADIUS_NOTIFICATION_H

#include <memory>
#include <string>

namespace model{
    class Entity;
}

namespace observer {

    /**
     * @class Notification
     * @brief Base notification class
     */
    class Notification {
    public:
        virtual ~Notification() = default;
    };
    /**
     * @class MovementNotification
     * @brief notification after the movement of an entity
     */
    class MovementNotification : public Notification {
    public:
        MovementNotification() = default;
    };

    /**
     * @class EntityNotification
     * @brief notification containing a weak_ptr to entity
     */
    class EntityNotification : public Notification {
        std::weak_ptr<const model::Entity> weak_entity;

    public:
        explicit EntityNotification(const std::weak_ptr<const model::Entity> &weak_entity);

        const std::weak_ptr<const model::Entity> &get_weak_entity() const;
    };

    /**
     * @class DestructionNotification
     * @brief notification after the destruction of an entity
     */
    class DestructionNotification : public EntityNotification {
    public:
        explicit DestructionNotification(const std::weak_ptr<const model::Entity> &weak_entity);

    };

    /**
     * @class CreationNotification
     * @brief notification after the creation of an entity
     */
    class CreationNotification : public EntityNotification {
    public:
        explicit CreationNotification(const std::weak_ptr<const model::Entity> &weak_entity);
    };



}


#endif //GRADIUS_NOTIFICATION_H
