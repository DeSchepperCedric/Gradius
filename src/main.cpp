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


    Game g;

    if(g.is_set_up()){
        g.run();
    }

    return 0;
}