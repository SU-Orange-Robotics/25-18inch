#include "vex.h"
#include "drive.h"
#include "robot-config.h"

using namespace vex;

Drive::Drive() {

}

void Drive::arcadeDrive(double y, double x) {
    x *= 0.75;
    leftDrive(maxClamp(y + x, maxOutputPct));
    rightDrive(maxClamp(y - x, maxOutputPct));
}

void Drive::tankDrive(double left, double right) {
    if (fabs(left - right) <= tankForwardDeadzone) { // if the stick inputs are close together, it sends the same value to both sides
        left = (left + right) / 2;
        right = left;
    }
    leftDrive(maxClamp(left, maxOutputPct));
    rightDrive(maxClamp(right, maxOutputPct));
}

void Drive::leftDrive(double pow) {
    LeftMotorA.spin(directionType::fwd, pow, velocityUnits::pct);
    LeftMotorB.spin(directionType::fwd, pow, velocityUnits::pct);
    //LeftMotorC.spin(directionType::fwd, pow, velocityUnits::pct);
}

void Drive::rightDrive(double pow) {
    RightMotorA.spin(directionType::fwd, pow, velocityUnits::pct);
    RightMotorB.spin(directionType::fwd, pow, velocityUnits::pct);
    //RightMotorC.spin(directionType::fwd, pow, velocityUnits::pct);
}