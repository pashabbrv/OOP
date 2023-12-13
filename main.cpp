#include <iostream>

#include "game.h"
#include "terminal.h"
#include "render_terminal.h"

int main(){
    Terminal terminal;
    RenderTerminal render;
    Handler handler(terminal, "choices");
    Game game(handler, render);
    game.start();

    return 0;
}