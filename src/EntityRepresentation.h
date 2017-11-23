//
// Created by Cedric De Schepper on 15/11/17.
//

#ifndef GRADIUS_ENTITYREPRESENTATION_H
#define GRADIUS_ENTITYREPRESENTATION_H


#include "Entity.h"
#include "Observer.h"
#include "Notification.h"

#include <SFML/Graphics.hpp>
#include <memory>

namespace view {

    class EntityRepresentation : public sf::Sprite, public observer::Observer {
        friend class View;

    private:
        std::weak_ptr<const model::Entity> weak_entity;

        bool to_be_moved = true;

    public:
        typedef std::shared_ptr<EntityRepresentation> Shared;
        typedef std::unique_ptr<EntityRepresentation> Unique;

        EntityRepresentation(const sf::Texture &texture, const std::weak_ptr<const model::Entity> &weak_entity);

        void draw(std::shared_ptr<sf::RenderWindow> window);

        void scale_representation_to_entity(const sf::Vector2u& window_size);

        virtual void on_notification(const observer::Notification& notification);

        const std::weak_ptr<const model::Entity> &get_weak_entity() const;
    };

}


#endif //GRADIUS_ENTITYREPRESENTATION_H
