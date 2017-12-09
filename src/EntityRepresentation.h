/**
 * @class view::EntityRepresentation
 *
 * @brief Graphical representation of an entity
 *
 * @author Cedric De Schepper
 *
 */

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

    protected:
        std::weak_ptr<const model::Entity> weak_entity;

        bool to_be_moved = true;

    public:
        typedef std::shared_ptr<EntityRepresentation> Shared;
        typedef std::unique_ptr<EntityRepresentation> Unique;

        EntityRepresentation(const sf::Texture* texture, const std::weak_ptr<const model::Entity> &weak_entity);

        /**
         * @brief draws the entityRepresentation on the window
         * @param window
         */
        virtual void draw(std::unique_ptr<sf::RenderWindow>& window);

        /**
         * @brief scales representation compared to window size and entity size
         * @param window_size size of display window
         */
        void scale_representation_to_entity(const sf::Vector2u& window_size);

        /**
         * @brief processes notification sent by subject (Observer Pattern)
         * @param notification
         */
        void on_notification(const observer::Notification& notification) override;

        /**
         * @brief simple getter: gets weak_ptr to the entity drawn by the entityRepresentation
         * @return weak_ptr to the entity
         */
        const std::weak_ptr<const model::Entity> &get_weak_entity() const;
    };

}


#endif //GRADIUS_ENTITYREPRESENTATION_H
