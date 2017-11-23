//
// Created by Cedric De Schepper on 13/11/17.
//

#include "Game.h"
#include "Model.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "Stopwatch.h"

#include <iostream>
using std::cout;
using std::endl;

void Game::run() {

}

Game::Game() {
    auto pointer = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Gradius");
    Game::view = view::View(pointer);
    model::Model::Shared model = std::make_shared<model::Model>();

    std::shared_ptr<model::PlayerShip> player = std::make_shared<model::PlayerShip>(0.40,0.20,-3.0,3.0,0.075,0.015);

    sf::Texture texture;
    texture.loadFromFile("../ship.png");

    view::EntityRepresentation::Unique player_rep= std::make_unique<view::EntityRepresentation>(texture, player);
    model->set_player(player);
    controller.set_Model(model);

    view.add_entity_representation(std::move(player_rep));
    float fps = 30.0f;
    Stopwatch::get_instance();

    bool up;
    bool down;
    bool right;
    bool left;

    while (view.window->isOpen())
    {

        if(Stopwatch::get_instance().get_time() < (1.0 / fps)) continue;
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (view.window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed or (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
                view.window->close();
            }



        }

        controller.execute_key_presses();
        controller.update();
        view.window->clear();
        view.update();
        view.window->display();

        Stopwatch::get_instance().reset();


    }

}

