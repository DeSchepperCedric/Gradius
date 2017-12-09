
#include "Game.h"

int main(int argc, char ** argv) {


    Game g("../input/Input.json");

    if(g.is_set_up()){
        g.run();
    }

    return 0;
}