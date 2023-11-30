#ifndef OOP_HEADERS_PLACE_H_
#define OOP_HEADERS_PLACE_H_

#include "event.h"

class Place: public Event{
 public:
    void realization(Controller& controller) override;
};

#endif