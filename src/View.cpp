//
// Created by Cedric De Schepper on 15/11/17.
//

#include "View.h"
#include "Transformation.h"

#include <iostream>

namespace view {

    void View::update() {

        for(auto& representation : entity_representations){
            representation->draw(window);
        }
    }

    View::View(std::shared_ptr<sf::RenderWindow> window) : window(window) {}

    void View::add_entity_representation(EntityRepresentation::Shared entity_rep) {
        entity_rep->scale_representation_to_entity(window->getSize());
        entity_representations.push_back(entity_rep);
    }
};