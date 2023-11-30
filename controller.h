#ifndef OOP_HEADERS_CONTROLLER_H_
#define OOP_HEADERS_CONTROLLER_H_

#include "player.h"
#include "ways.h"
#include "field.h"

class Controller {
 public:
    void movement(Ways way, int step = 1);
    void change_health(int health);
    void change_score(int score);
    Controller(Player& player, Field& field);

 private:
    Player& player_;
    Field& field_;
};

#endif