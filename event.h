#ifndef OOP_HEADERS_EVENT_H_
#define OOP_HEADERS_EVENT_H_

class Controller;

class Event {
 public:
    virtual void realization(Controller& controller) = 0;
    virtual Event* create() const = 0;
};

#endif