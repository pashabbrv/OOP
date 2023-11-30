#include "game.h"

void Game::start() {
    std::cout << "Welcome!" << std::endl;
    choose_level();
    play();
    end();
}

void Game::choose_level() {
    Operations operation;

    while (true) {
        std::cout << "Choose the level that you want to play. Press '1' or '2':" << std::endl;
        operation = handler_.get_operation();

        if (operation == Operations::Level1) {
            field_ = levels_.first_level();
            player_.set_health(10);
            break;
        } else if (operation == Operations::Level2) {
            field_ = levels_.second_level();
            player_.set_health(40);
            break;  
        } else {
            std::cout << "There is no such level! Try again." << std::endl;
            continue;
        }
        system("cls");
    }
}

void Game::play() {
    Controller controller(player_, field_);
    Operations operation;
    Ways way;

    while (true) {
        system("cls");
        player_.print_settings();
        field_.print_field(player_);

        if (player_.get_health() <= 0) {
            std::cout << "You loose! GAME OVER" << std::endl;
            break;
        }

        if (player_.get_x_coord() == field_.get_exit_x() && player_.get_y_coord() == field_.get_exit_y()) {
            std::cout << "You win!" << std::endl;
            break;
        }

        std::cout << "Choose what you want to do: 'w' - go up, 'a' - go left, 's' - go down, 'd' - go right. " << std::endl;
        std::cout << "If you want to quit the game press 'q'." << std::endl;
        operation = handler_.get_operation();

        if (operation == Operations::Quit)
            break;

        switch (operation) {
            case Operations::GoUp:
                way = Ways::UP;
                break;
            case Operations::GoLeft:
                way = Ways::LEFT;
                break;
            case Operations::GoDown:
                way = Ways::DOWN;
                break;
            case Operations::GoRight:
                way = Ways::RIGHT;
                break;
            default:
                continue;
        }
        controller.movement(way);
    }
}

void Game::end() {
    player_.set_x_coord(0);
    player_.set_y_coord(0);
    player_.set_score(0);

    Operations operation;
    std::cout << "Do you want to play again? Press 'y' or 'n': " << std::endl;

    while (true) {
        operation = handler_.get_operation();

        if (operation == Operations::Yes) {
            system("cls");    
            start();
        } else if (operation == Operations::No) {
            std::cout << "Goodbye :)" << std::endl;
            exit(0);
        } else
            continue;
    }
}

Game::Game(Handler& handler) : handler_(handler) {}