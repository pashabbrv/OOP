#include "damage.h"
#include "controller.h"

void Damage::realization(Controller& controller){
    controller.change_health(DAMAGE);
}