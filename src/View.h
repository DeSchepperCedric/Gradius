//
// Created by Cedric De Schepper on 15/11/17.
//

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
    public:
        std::shared_ptr<sf::RenderWindow> window;



    public:
        typedef std::shared_ptr<View> Shared;

        View() = default;

        View(std::shared_ptr<sf::RenderWindow> window);

        void update();

        void add_entity_representation(EntityRepresentation::Shared& entity_rep);

        void add_entity_representation_of_entity(const std::weak_ptr<const model::Entity>& weak_entity);

        void remove_entity_representation_of_entity(std::weak_ptr<const model::Entity> weak_entity);

        virtual void on_notification(const observer::Notification& notification);

        void add_texture(const sf::Texture texture, const std::string& type);

    };

}


#endif //GRADIUS_VIEW_H
