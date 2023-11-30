#ifndef OOP_HEADERS_GAME_H_
#define OOP_HEADERS_GAME_H_

#include "levels.h"
#include "handler.h"
#include "controller.h"

class Game {
 public:
   void start();
   Game(Handler& handler);

 private:   
   Handler& handler_;
   Levels levels_;
   Field field_;
   Player player_;

   void choose_level();
   void play();
   void end();
};

#endif