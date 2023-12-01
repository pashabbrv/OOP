#include "place.h"
#include "controller.h"

void Place::realization(Controller& controller){
    controller.movement(Ways::RIGHT);
    controller.movement(Ways::DOWN); 
}

Event* Place::create() const {
    return new Place;
}