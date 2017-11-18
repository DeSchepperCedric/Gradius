#include <iostream>
#include <vector>
#include <memory>

#include "Entity.h"
#include "Stopwatch.h"
#include "Transformation.h"
#include "View.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"




using std::endl;
using std::cout;

int main(int argc, char ** argv) {
      auto pointer = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Gradius");
    view::View test(pointer);

    Game g(test);
    g.run();

        // Create the main rendering window
       /* sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML Graphics");
        sf::CircleShape Rectangle (50);

        // Start game loop
        sf::Clock clock;
        while (App.isOpen())
        {
            // Process events
            sf::Event Event;
            while (App.pollEvent(Event))
            {
                // Close window : exit
                if (Event.type == sf::Event::Closed)
                    App.close();

                // A key has been pressed
                if (Event.type == sf::Event::KeyPressed)
                {
                    // Escape key : exit
                    if (Event.key.code == sf::Keyboard::Escape)
                        App.close();
                }
            }

            // Clear the screen
            App.clear(sf::Color(0, 0, 0));
            cout << clock.getElapsedTime().asMilliseconds()<<endl;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  {
                cout << "t: "<<clock.getElapsedTime().asMilliseconds()<<endl;
                Rectangle.move(150 * clock.getElapsedTime().asSeconds() * -1, 0);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                Rectangle.move(150 * clock.getElapsedTime().asSeconds(), 0);
            }
            clock.restart();
            App.draw(Rectangle);

            // Display window contents on screen
            App.display();
        }

        return EXIT_SUCCESS;

*/
    /*
     *
     * sf::Texture texture;
        texture.loadFromFile("ship.png");
        sf::Sprite sprite;
        sprite.setTexture(texture, true);

        float x_scale = (float)((0.50*720.0) / (8.0 * 343.0));
        float y_scale = (float)((0.25*540.0) / (6.0 * 198.0));


        sprite.setScale(x_scale, y_scale);
        // run the program as long as the window is open
        while (window->isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window->pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window->close();
            }
            window->clear();
            window->draw(sprite);
            window->display();

        }


        // update all sprites

     */


    return 0;
}