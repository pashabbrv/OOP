#include "tracker.h"

void Tracker::check_state(States state) const {
    switch (state) {
        case States::kStart:
            render_.print_start();
            break;
        case States::kLevel:
            render_.print_level();
            break;
        case States::kPlay:
            render_.print_player(player_);
            render_.print_field(player_, field_);
            break;
        case States::kLose:
            render_.print_lose();
            break;
        case States::kWin:
            render_.print_win();
            break;
        case States::kWarning:
            render_.print_warning();
            break;
        case States::kNewGame:
            render_.print_new_game();
            break;
        case States::kEnd:
            render_.print_end();
            break;
    }
}

Tracker::Tracker(Render& render, Player& player, Field& field) : render_(render), player_(player), field_(field) {}