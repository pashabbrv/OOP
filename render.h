#ifndef OOP_RENDER_H
#define OOP_RENDER_H

#include "player.h"
#include "field.h"

class Render {
 public:
    virtual void print_start() const = 0;
    virtual void print_level() const = 0;
    virtual void print_win() const = 0;
    virtual void print_warning() const = 0;
    virtual void print_lose() const = 0;
    virtual void print_player(Player& player) const = 0;
    virtual void print_field(Player& player, Field& field) const = 0;
    virtual void print_new_game() const = 0;
    virtual void print_end() const = 0;
};

#endif