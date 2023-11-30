#include <iostream>

#include "controller.h"
#include "player.h"
#include "ways.h"
#include "field.h"

void Controller::movement(Ways way, int step) {
    int prev_x = player_.get_x_coord();
    int prev_y = player_.get_y_coord();

    switch (way) {
    case Ways::UP:
        player_.set_y_coord(prev_y - step);
        break;
    case Ways::DOWN:
        player_.set_y_coord(prev_y + step);
        break;
    case Ways::LEFT:
        player_.set_x_coord(prev_x - step);
        break;
    case Ways::RIGHT:
        player_.set_x_coord(prev_x + step);
        break;
    }

    if(!field_.valid(player_.get_x_coord(), player_.get_y_coord()) || !field_.get_cell(player_.get_x_coord(), player_.get_y_coord()).get_access()) {
        player_.set_x_coord(prev_x);
        player_.set_y_coord(prev_y);
    }

    if(field_.get_cell(player_.get_x_coord(), player_.get_y_coord()).get_access() && field_.get_cell(player_.get_x_coord(), player_.get_y_coord()).get_event()){
        field_.get_cell(player_.get_x_coord(), player_.get_y_coord()).start_event(*this);
    }
}

void Controller::change_health(int health) {
    player_.set_health(player_.get_health() + health);
}

void Controller::change_score(int score) {
    player_.set_score(player_.get_score() + score);
}

Controller::Controller(Player& player, Field& field) : player_(player), field_(field){}