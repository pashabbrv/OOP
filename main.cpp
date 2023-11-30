#include <iostream>

#include "game.h"
#include "terminal.h"

int main(){
    Terminal terminal;
    Handler handler(terminal, "choices");
    Game game(handler);
    game.start();

    return 0;
}