#include "score.h"
#include "controller.h"

void Score::realization(Controller& controller){
    controller.change_score(SCORE);
}

Event* Score::create() const {
    return new Score;
}