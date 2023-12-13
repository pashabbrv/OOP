#include "render_terminal.h"

void RenderTerminal::print_start() const {
    std::cout << "Welcome!" << std::endl;
}

void RenderTerminal::print_level() const {
    std::cout << "Choose the level that you want to play. Press '1' or '2': " << std::endl;
}

void RenderTerminal::print_win() const {
    std::cout << "You win!" << std::endl;
}

void RenderTerminal::print_warning() const {
    std::cout << "There is no such level! Try again." << std::endl;
}

void RenderTerminal::print_lose() const {
    std::cout << "You loose! GAME OVER" << std::endl;
}

void RenderTerminal::print_player(Player& player) const {
    std::cout << "Health: " << player.get_health()
              << "  Score: " << player.get_score() << std::endl;
    std::cout << "Coordinates X: " << player.get_x_coord()
              << "  Coordinates Y: " << player.get_y_coord() << std::endl << std::endl;
}

void RenderTerminal::print_field(Player& player, Field& field) const {
     for (int y = 0; y < field.get_width(); y++) {
        for (int x = 0; x < field.get_length(); x++) {
            if (player.get_x_coord() == x && player.get_y_coord() == y)
                std::cout << "* ";
            else if (field.get_cell(x, y).get_event() && typeid(*field.get_cell(x, y).get_event()) == typeid(Damage))
                std::cout << "D ";
            else if (field.get_cell(x, y).get_event() && typeid(*field.get_cell(x, y).get_event()) == typeid(Score))
                std::cout << "S ";
            else if (field.get_cell(x, y).get_event() && typeid(*field.get_cell(x, y).get_event()) == typeid(Place))
                std::cout << "P ";
            else if (x == 0 && y == 0)
                std::cout << "0 ";
            else if (field.get_exit_x() == x && field.get_exit_y() == y)
                std::cout << "W ";
            else if (field.get_cell(x, y).get_access())
                std::cout << ". ";
            else if (!field.get_cell(x, y).get_access())
                std::cout << "# ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Choose what you want to do: 'w' - go up, 'a' - go left, 's' - go down, 'd' - go right. " << std::endl;
    std::cout << "If you want to quit the game press 'q'." << std::endl;
}

void RenderTerminal::print_new_game() const {
    std::cout << "Do you want to play again? Press 'y' or 'n': " << std::endl;
}

void RenderTerminal::print_end() const {
    std::cout << "Goodbye :)" << std::endl;
}