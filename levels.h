#ifndef OOP_HEADERS_LEVELS_H_
#define OOP_HEADERS_LEVELS_H_

#include "field.h"
#include "damage.h"
#include "score.h"
#include "place.h"

class Levels{
 public:
    Field& first_level();
    Field& second_level();
 private:
    Damage* damage = new Damage;
    Score* score = new Score;
    Place* place = new Place;
};

#endif