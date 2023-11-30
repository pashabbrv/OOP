#ifndef OOP_HEADERS_SCORE_H_
#define OOP_HEADERS_SCORE_H_

#include "event.h"

#define SCORE 10

class Score: public Event{
 public:
    void realization(Controller& controller) override;
};

#endif