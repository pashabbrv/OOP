#include "game.h"

void Game::start() {
    Tracker tracker(render_, player_, field_);
    tracker.check_state(States::kStart);
    
    choose_level(tracker);
    play(tracker);
    end(tracker);
}

void Game::choose_level(Tracker& tracker) {
    Operations operation;
    player_.set_x_coord(0);
    player_.set_y_coord(0);
    player_.set_score(0);

    while (true) {
        tracker.check_state(States::kLevel);
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
            tracker.check_state(States::kWarning);
            continue;
        }
        system("cls");
    }
}

void Game::play(Tracker& tracker) {
    Controller controller(player_, field_);
    Operations operation;
    Ways way;

    while (true) {
        system("cls");
        tracker.check_state(States::kPlay);

        if (player_.get_health() <= 0) {
            tracker.check_state(States::kLose);
            break;
        }

        if (player_.get_x_coord() == field_.get_exit_x() && player_.get_y_coord() == field_.get_exit_y()) {
            tracker.check_state(States::kWin);
            break;
        }

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

void Game::end(Tracker& tracker) {
    Operations operation;
    tracker.check_state(States::kNewGame);

    while (true) {
        operation = handler_.get_operation();

        if (operation == Operations::Yes) {
            system("cls");    
            start();
        } else if (operation == Operations::No) {
            tracker.check_state(States::kEnd);
            exit(0);
        } else
            continue;
    }
}

Game::Game(Handler& handler, Render& render) : handler_(handler), render_(render) {}