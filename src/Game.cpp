//
// Created by Cedric De Schepper on 13/11/17.
//

#include "Game.h"
#include "Model.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "Stopwatch.h"
#include "Obstacle.h"
#include "World.h"
#include "EnemyShip.h"

#include <iostream>
using std::cout;
using std::endl;

void Game::run() {
    utils::Stopwatch::get_instance();

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

        controller.execute_key_presses(utils::Stopwatch::get_instance().getFrame_time());
        controller.update_model(utils::Stopwatch::get_instance().getFrame_time());

        view->window->clear();

        view->update();

        view->window->display();


        utils::Stopwatch::get_instance().reset();


    }

}

Game::Game() {
    auto pointer = std::make_shared<sf::RenderWindow>(sf::VideoMode(900, 600), "Gradius");
    view::View::Shared view = std::make_shared<view::View>(view::View(pointer));
    Game::view = view;

    model::Model::Shared model = std::make_shared<model::Model>();
    // speed
    std::shared_ptr<model::PlayerShip> player = std::make_shared<model::PlayerShip>(0.40,0.40,-3.0,0.0,8,3,1,0.5);
    //sf::Texture temp;
   // temp.loadFromFile("../ship.png");
   // sf::Texture* texture = &temp;
    sf::Texture texture;
    texture.loadFromFile("../images/x_wing.jpg");
    view->add_texture(texture, "PlayerShip");

    sf::Texture temp_bullet;
    temp_bullet.loadFromFile("../images/red_laser.png");
    view->add_texture(temp_bullet, "Bullet");



    std::weak_ptr<view::View> weak_view(view);
    std::weak_ptr<model::Model> weak_model(model);

    model->register_observer(weak_view);
    //player->register_observer(player_rep);
    model->set_player(player);

    std::shared_ptr<model::Obstacle> ob = std::make_shared<model::Obstacle>(0.40,0.80,4.0,0.0,2,1,1);
    std::shared_ptr<model::Obstacle> ob2 = std::make_shared<model::Obstacle>(0.80,0.80,4.0,2.0,2,-1,1);

    sf::Texture ob_text;
    ob_text.loadFromFile("../images/astroid.jpg");

    sf::Texture ob_text2;
    ob_text2.loadFromFile("../images/planet.png");

    sf::Texture world_text;
    world_text.loadFromFile("../images/sun.jpg");

    view->add_texture(ob_text, "DestructableObstacle");
    view->add_texture(ob_text2, "IndestructableObstacle");
    view->add_texture(world_text, "World");

    model->create_all_world_entities();
    //model->add_entity(std::move(world));
    model->add_entity(std::move(ob));
    model->add_entity(std::move(ob2));


    std::shared_ptr<model::EnemyShip> enemy = std::make_shared<model::EnemyShip>(0.40,0.40,3.0,0.0,2,1,1,1.0f);
    sf::Texture enemy_text;
    enemy_text.loadFromFile("../images/x_wing.jpg");
    view->add_texture(enemy_text, "EnemyShip");
    model->add_entity(std::move(enemy));


    controller.set_Model(model);

    //view.add_entity_representation(player_rep);


}

