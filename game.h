#ifndef OOP_HEADERS_GAME_H_
#define OOP_HEADERS_GAME_H_

#include "levels.h"
#include "handler.h"
#include "controller.h"
#include "tracker.h"
#include "render.h"

class Game {
 public:
   void start();
   Game(Handler& handler, Render& render);

 private:   
   Handler& handler_;
   Levels levels_;
   Field field_;
   Player player_;
   Render& render_;

   void choose_level(Tracker& tracker);
   void play(Tracker& tracker);
   void end(Tracker& tracker);
};

#endif