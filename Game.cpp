//
// Created by Cedric De Schepper on 13/11/17.
//

#include "Game.h"
#include "Model.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>

#include <iostream>
using std::cout;
using std::endl;

void Game::run() {

}

Game::Game(view::View &view) : view(view) {
    model::Model::Shared model = std::make_shared<model::Model>();

    std::shared_ptr<PlayerShip> player = std::make_shared<PlayerShip>(0.1,0.2,-3.0,3.0,0.05);

    sf::Texture texture;
    texture.loadFromFile("ship.png");

    view::EntityRepresentation::Shared player_rep= std::make_shared<view::EntityRepresentation>(texture, player);
    model->set_player(player);
    controller.set_Model(model);

    float x_scale = (float)((0.50*720.0) / (8.0 * 343.0));
    float y_scale = (float)((0.25*540.0) / (6.0 * 198.0));


    player_rep->setScale(x_scale, y_scale);
    view.add_entity_representation(player_rep);
    sf::Clock clock;
    while (view.window->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (view.window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                view.window->close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                controller.move_player_down();
            }
            clock.restart();
            view.window->clear();
            view.update();
            view.window->display();
        }


    }

}

