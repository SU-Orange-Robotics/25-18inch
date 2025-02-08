#include "vex.h"
#include "robot-config.h"
#include "mogoMech.h"

using namespace vex;

void mogoDown() {
    MogoMech.spin(directionType::fwd, mechPow, percentUnits::pct);
}

void mogoUp() {
    MogoMech.spin(directionType::rev, mechPow, percentUnits::pct);
}

void mogoStop() {
    MogoMech.stop(brakeType::hold);
}