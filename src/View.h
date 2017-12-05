/**
 * @class view::View
 *
 * @brief view of MVC that contains all graphical representations and the game window
 */


#ifndef GRADIUS_VIEW_H
#define GRADIUS_VIEW_H

#include "EntityRepresentation.h"

#include <memory>
#include <list>
#include <SFML/Graphics.hpp>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

namespace view {
    class View : public observer::Observer {
    private:
        // Shared pointers to Entity_representations
        // reason : Entity_rep an observer to a subject (entity) so the subject needs a weak pointer to its observer
        std::vector<view::EntityRepresentation::Shared> entity_representations;

        std::unordered_map<std::string,sf::Texture> textures;

        std::shared_ptr<sf::RenderWindow> window;

    public:
        typedef std::shared_ptr<View> Shared;

        View(std::shared_ptr<sf::RenderWindow> window);

        /**
         * @brief update the view: update the view and update + draw all entityRepresentation
         */
        void update();

        /**
         * @brief add the entityRepresentation of an entity that got created
         * @param weak_entity weak_ptr to the entity that got created
         */
        void add_entity_representation_of_entity(const std::weak_ptr<const model::Entity>& weak_entity);

        /**
         * @brief remove the entityRepresentation of an entity that is gonna be destroyed
         * @param weak_entity weak_ptr to the entity that's gonna be removed
         */
        void remove_entity_representation_of_entity();

        /**
         * @brief processes notification sent by subject (Observer Pattern)
         * @param notification
         */
        virtual void on_notification(const observer::Notification& notification);

        /**
         * @brief add texture to be used on game sprites
         * @param texture texture to be added to sprite
         * @param type type of entity that the texture will be used on
         */
        void add_texture(const sf::Texture texture, const std::string& type);

        /**
         * @brief simple getter: get game window to be displayed
         * @return game window
         */
        const std::shared_ptr<sf::RenderWindow> &get_window() const;

    };

}


#endif //GRADIUS_VIEW_H
