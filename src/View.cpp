//
// Created by Cedric De Schepper on 15/11/17.
//

#include "View.h"
#include "Transformation.h"

#include <iostream>

namespace view {

    View::View(std::shared_ptr<sf::RenderWindow> window) : window(window) {}


    void View::update() {

        for(auto& representation : entity_representations){
            representation->draw(window);
        }
    }

    void View::add_entity_representation(EntityRepresentation::Unique entity_rep) {
        entity_rep->scale_representation_to_entity(window->getSize());
        entity_representations.push_back(std::move(entity_rep));
    }

    void View::add_entity_representation_of_entity(std::weak_ptr<const model::Entity> weak_entity) {
        const sf::Texture texture = textures.at(std::type_index(typeid(weak_entity.lock().get())));
        EntityRepresentation::Unique entity_rep = std::make_unique<EntityRepresentation>(texture, weak_entity);

        entity_rep->scale_representation_to_entity(window->getSize());
        entity_representations.push_back(std::move(entity_rep));
    }

    void View::remove_entity_representation_of_entity(std::weak_ptr<const model::Entity> weak_entity) {
        int index = 0;
        for(auto it = entity_representations.begin(); it != entity_representations.end();it++){
            if((*it)->get_weak_entity().expired()){
                entity_representations.erase(it);
                return;
            }
        }
    }

    void View::on_notification(const observer::Notification& notification) {
        if(auto destruction = dynamic_cast<const observer::DestructionNotification*>(&notification)){
            remove_entity_representation_of_entity(destruction->get_weak_entity());
        }
        else if(auto creation = dynamic_cast<const observer::CreationNotification*>(&notification)){
            add_entity_representation_of_entity(creation->get_weak_entity());
        }
    }


};