#include "vex.h"
#include "drive.h"
#include "robot-config.h"

using namespace vex;

competition Competition;

motor LeftMotorA(NULL, gearSetting::ratio18_1, false);
motor LeftMotorB(NULL, gearSetting::ratio18_1, false);
motor RightMotorA(NULL, gearSetting::ratio18_1, true);
motor RightMotorB(NULL, gearSetting::ratio18_1, true);

motor Intake(NULL, gearSetting::ratio18_1, false);
motor Chainlift(NULL, gearSetting::ratio18_1, false);

optical ColorSensor(NULL);

brain Brain;
controller Controller1(controllerType::primary);

Drive drive;