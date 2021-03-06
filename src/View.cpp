
#include "View.h"
#include "Transformation.h"
#include "Exceptions.h"

#include <iostream>

namespace view {

    View::View(std::unique_ptr<sf::RenderWindow>& window) : window(std::move(window)) {}


    void View::update() {
        // draw loss/victory sprite when game is done
        if(game_done != nullptr){
            window->draw(*game_done);
            return;
        }


        for(auto& representation : entity_representations){
            representation->draw(window);
        }
        for(auto& live : lives){
            window->draw(*live);
        }
    }

    void View::add_entity_representation_of_entity(const std::weak_ptr<const model::Entity>& weak_entity) {
        try{
        std::string name = weak_entity.lock()->get_name();



        if(name == "PlayerShip"){

            if(textures.find("Life") == textures.end()){
                throw exceptions::TextureKeyException("Life");
            }
            sf::Texture* live_text = &textures.at("Life");
            float x = 0.0f;

            for(int i =0 ; i < weak_entity.lock()->get_health(); i++){
                std::unique_ptr<sf::Sprite> live = std::make_unique<sf::Sprite>(*live_text);

                live->setScale((25 / live->getGlobalBounds().width) , (25 / live->getGlobalBounds().height));
                live->setPosition(x,0.0f);
                lives.push_back(std::move(live));
                x += 25.0f;
            }
        }
            if(textures.find(name) == textures.end()){
                throw exceptions::TextureKeyException(name);
            }
            sf::Texture* texture = &textures.at(name);

            EntityRepresentation::Shared entity_rep = std::make_shared<EntityRepresentation>(texture, weak_entity);

            entity_rep->scale_representation_to_entity(window->getSize());
            entity_representations.push_back(std::move(entity_rep));
        }
        catch(const std::exception& e){
            std::cout << e.what() << std::endl;
            window->close();
            return;
        }

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
        if (dynamic_cast<const observer::DestructionNotification *>(&notification)) {
            remove_entity_representation_of_entity();

        }
        else if (auto creation = dynamic_cast<const observer::CreationNotification *>(&notification)) {
            add_entity_representation_of_entity(creation->get_weak_entity());

        }
        else if (auto game_done = dynamic_cast<const observer::GameDoneNotification *>(&notification)) {
            end_game(game_done->is_win());
        }
        else if (dynamic_cast<const observer::LoseLifeNotification *>(&notification)) {
            lives.pop_back();
        }
    }

    void View::add_texture(const sf::Texture& texture, const std::string &type) {
        textures[type] = texture;

    }

    const std::unique_ptr<sf::RenderWindow> &View::get_window() const {
        return window;
    }

    void View::end_game(bool win) {
        while (!entity_representations.empty()) {
            entity_representations.pop_back();
        }
        game_done = std::make_unique<sf::Sprite>();
        try{
            if(win){
                if(textures.find("GameWon") == textures.end()){
                    throw exceptions::TextureKeyException("GameWon");
                }


                sf::Texture* texture = &textures.at("GameWon");
                game_done->setTexture(*texture);
            }
            else{
                if(textures.find("GameOver") == textures.end()){
                    throw exceptions::TextureKeyException("GameOver");
                }

                sf::Texture* texture = &textures.at("GameOver");
                game_done->setTexture(*texture);
            }

        }
        catch(const exceptions::TextureFileException& e){
            std::cout << e.what() << std::endl;
            window->close();
            return;
        }
        game_done->setScale((1 / game_done->getGlobalBounds().width) * window->getSize().x , (1 / game_done->getGlobalBounds().height) * window->getSize().y);

    }

};