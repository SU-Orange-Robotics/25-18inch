#include "vex.h"
#include "robot-config.h"
#include "intakeLift.h"

using namespace vex;

void intakeSpin(bool reversed) {
    Intake.spin(directionType::fwd, intakePow * (reversed ? -1 : 1), percentUnits::pct);
}

void intakeStop() {
    Intake.stop();
}

void chainliftSpin(bool reversed) {
    Chainlift.spin(directionType::fwd, intakePow * (reversed ? -1 : 1), percentUnits::pct);
}

void chainliftStop() {
    Chainlift.stop();
}