#ifndef OOP_HEADERS_DAMAGE_H_
#define OOP_HEADERS_DAMAGE_H_

#include "event.h"

#define DAMAGE -10

class Damage: public Event{
 public:
    void realization(Controller& controller) override;
};

#endif