
#include "View.h"
#include "Transformation.h"

#include <iostream>

namespace view {

    View::View(std::unique_ptr<sf::RenderWindow>& window) : window(std::move(window)) {}


    void View::update() {

        for(auto& representation : entity_representations){
            representation->draw(window);
        }
        for(auto& live : lives){
            window->draw(*live);
        }
    }

    void View::add_entity_representation_of_entity(const std::weak_ptr<const model::Entity>& weak_entity) {
        std::string name = weak_entity.lock()->get_name();
        sf::Texture* texture = &textures.at(name);
        if(name == "PlayerShip"){
            
            sf::Texture* live_text = &textures.at("Life");
            float x = 0.0f;
            EntityRepresentation::Shared player =std::make_shared<EntityRepresentation>(texture, weak_entity);
            player->scale_representation_to_entity(window->getSize());

            for(int i =0 ; i < weak_entity.lock()->get_health(); i++){
                std::unique_ptr<sf::Sprite> live = std::make_unique<sf::Sprite>(*live_text);

                live->setScale((25 / live->getGlobalBounds().width) , (25 / live->getGlobalBounds().height));
                live->setPosition(x,0.0f);
                lives.push_back(std::move(live));
                x += 25.0f;

            }

            entity_representations.push_back(std::move(player));

            return;
        }

        EntityRepresentation::Shared entity_rep = std::make_shared<EntityRepresentation>(texture, weak_entity);

        entity_rep->scale_representation_to_entity(window->getSize());
        entity_representations.push_back(std::move(entity_rep));
    }

    void View::remove_entity_representation_of_entity() {
        for(auto it = entity_representations.begin(); it != entity_representations.end();it++){

            if((*it)->get_weak_entity().expired()){

                entity_representations.erase(it);

                return;
            }
        }
    }

    void View::on_notification(const observer::Notification& notification) {
        if (auto destruction = dynamic_cast<const observer::DestructionNotification *>(&notification)) {
            remove_entity_representation_of_entity();
        } else if (auto creation = dynamic_cast<const observer::CreationNotification *>(&notification)) {
            add_entity_representation_of_entity(creation->get_weak_entity());
        } else if (auto game_over = dynamic_cast<const observer::GameOverNotification *>(&notification)) {
            while (!entity_representations.empty()) {
                entity_representations.pop_back();
            }
            window->close();
        } else if (auto lost_live = dynamic_cast<const observer::LoseLifeNotification *>(&notification)) {
            lives.pop_back();
        }
    }

    void View::add_texture(const sf::Texture& texture, const std::string &type) {
        textures[type] = texture;

    }

    const std::unique_ptr<sf::RenderWindow> &View::get_window() const {
        return window;
    }
};