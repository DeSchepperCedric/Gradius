

#include "Notification.h"
#include "Entity.h"

namespace observer{

    EntityNotification::EntityNotification(const std::weak_ptr<const model::Entity> &weak_entity) : weak_entity(
            weak_entity) {}

    const std::weak_ptr<const model::Entity> &EntityNotification::get_weak_entity() const {
        return weak_entity;
    }

    CreationNotification::CreationNotification(const std::weak_ptr<const model::Entity> &weak_entity)
            : EntityNotification(weak_entity) {}


    GameOverNotification::GameOverNotification(bool win) : win(win) {}

    bool GameOverNotification::is_win() const {
        return win;
    }

    LoseLifeNotification::LoseLifeNotification() {}

    DestructionNotification::DestructionNotification() {}
}

