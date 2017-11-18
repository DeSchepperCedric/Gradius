//
// Created by Cedric De Schepper on 15/11/17.
//

#ifndef GRADIUS_VIEW_H
#define GRADIUS_VIEW_H

#include "EntityRepresentation.h"

#include <memory>
#include <list>

#include <SFML/Graphics.hpp>

namespace view {
    class View {
    private:
        std::list<std::shared_ptr<EntityRepresentation>> entity_representations;
    public:
        std::shared_ptr<sf::RenderWindow> window;

    public:
        View(std::shared_ptr<sf::RenderWindow> window);

        void update();

        void add_entity_representation(EntityRepresentation::Shared entity_rep);

    };

}


#endif //GRADIUS_VIEW_H
