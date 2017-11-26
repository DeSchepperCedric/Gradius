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
    view::View::Shared view = std::make_shared<view::View>(view::View(pointer));
    Game::view = view;
    model::Model::Shared model = std::make_shared<model::Model>();
    // speed
    std::shared_ptr<model::PlayerShip> player = std::make_shared<model::PlayerShip>(0.40,0.20,-3.0,3.0,10,1.0);
    sf::Texture temp;
    temp.loadFromFile("../ship.png");
    sf::Texture* texture = &temp;

    view->add_texture(texture, "PlayerShip");
    std::weak_ptr<view::View> weak_view(view);
    model->register_observer(weak_view);
    //player->register_observer(player_rep);
    model->set_player(player);

    controller.set_Model(model);

    //view.add_entity_representation(player_rep);
    Stopwatch::get_instance();

    bool up;
    bool down;
    bool right;
    bool left;
    while (view->window->isOpen())
    {


        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (view->window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed or (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
                view->window->close();
            }



        }

        controller.execute_key_presses(Stopwatch::get_instance().getFrame_time());
        view->window->clear();
        view->update();
        view->window->display();

        Stopwatch::get_instance().reset();


    }

}

