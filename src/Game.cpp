
#include "Game.h"
#include "Model.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "Stopwatch.h"
#include "Obstacle.h"
#include "World.h"
#include "EnemyShip.h"
#include "Level.h"
#include "Exceptions.h"
#include "Parsers.h"

#include "json.hpp"

#include <iostream>
#include <fstream>
#include <exception>
using std::cout;
using std::endl;

using json = nlohmann::json;

void Game::run() {
    utils::Stopwatch::get_instance();

    while (view->get_window()->isOpen())
    {


        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (view->get_window()->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed or (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
                view->get_window()->close();
            }



        }

        // execute user input
        controller->execute_key_presses(utils::Stopwatch::get_instance().get_frame_time());

        // execute default updates
        controller->update_model(utils::Stopwatch::get_instance().get_frame_time());

        view->get_window()->clear();

        // update and draw all representations
        view->update();

        view->get_window()->display();

        // reset frame timer
        utils::Stopwatch::get_instance().reset();


    }
}

Game::Game() {
    try {
        // open input json file
        std::ifstream i ("../input/Input.json");
        json j;

        i >> j;
        std::vector<int> window_size = j.at("Window").get<std::vector<int>>();

        if(window_size.size() != 2){
            std::cout <<"EXCEPTION"<<std::endl;
        }

        // configure game view with window
        auto pointer = std::make_unique<sf::RenderWindow>(sf::VideoMode(window_size[0], window_size[1]), "Gradius");
        Game::view = std::make_shared<view::View>(view::View(pointer));
        parsers::parse_view(j, Game::view);

        Game::controller = std::make_unique<controller::Controller>();

        model::Model::Shared model = std::make_shared<model::Model>();

        std::weak_ptr<view::View> weak_view(view);
        model->register_observer(weak_view);

        // configure game model
        parsers::parse_model(j, model);

        Game::controller->set_Model(std::move(model));

    }
    catch(const std::exception& e){
        std::cout << e.what() <<std::endl;
        Game::set_up = false;
        std::cout << "Game loading failed" <<std::endl;
        return;
    }

    Game::set_up = true;

}

bool Game::isSet_up() const {
    return set_up;
}
