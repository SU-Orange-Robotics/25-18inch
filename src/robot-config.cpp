#include "vex.h"
#include "drive.h"
#include "robot-config.h"

using namespace vex;

competition Competition;

motor LeftMotorA(PORT1, gearSetting::ratio18_1, true);
motor LeftMotorB(PORT2, gearSetting::ratio18_1, false);
motor LeftMotorC(PORT3, gearSetting::ratio18_1, true);
motor RightMotorA(PORT8, gearSetting::ratio18_1, false);
motor RightMotorB(PORT9, gearSetting::ratio18_1, true);
motor RightMotorC(PORT10, gearSetting::ratio18_1, false);

motor Intake(PORT11, gearSetting::ratio6_1, true);
motor Chainlift(PORT12, gearSetting::ratio18_1, false);
motor MogoMech(PORT16, gearSetting::ratio36_1, false);

optical ColorSensor(PORT20);

brain Brain;
controller Controller1(controllerType::primary);

Drive drive;