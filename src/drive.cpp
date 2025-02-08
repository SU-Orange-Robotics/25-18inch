#include "vex.h"
#include "drive.h"
#include "robot-config.h"

using namespace vex;

Drive::Drive() {
    invertDrive = false;
}

void Drive::arcadeDrive(double y, double x) {
    inputAdjust(y, x);
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

void Drive::inputAdjust(double &fwd, double &str) { // add parameter for tank drive
    fwd *= fabs(fwd) < deadzone ? 0.0 : 1.0;
    str *= fabs(str) < deadzone ? 0.0 : 1.0;
    
    fwd /= 100;
    str /= 100;
    
    /*
    fwd = pow(fwd, 2) * ((fwd > 0) ? 1 : -1);
    str = pow(str, 2) * ((str > 0) ? 1 : -1);
    */

    fwd *= 100;
    str *= 100;

    //invert control direction
    if (invertDrive) {
        fwd *= -1;
    }
}

void Drive::toggleInvertDrive() {
    invertDrive = !invertDrive;
}

void Drive::leftDrive(double pow) {
    LeftMotorA.spin(directionType::fwd, pow, velocityUnits::pct);
    LeftMotorB.spin(directionType::fwd, pow, velocityUnits::pct);
    LeftMotorC.spin(directionType::fwd, pow, velocityUnits::pct);
}

void Drive::rightDrive(double pow) {
    RightMotorA.spin(directionType::fwd, pow, velocityUnits::pct);
    RightMotorB.spin(directionType::fwd, pow, velocityUnits::pct);
    RightMotorC.spin(directionType::fwd, pow, velocityUnits::pct);
}

void Drive::stop() {
    LeftMotorA.stop();
    LeftMotorB.stop();
    LeftMotorC.stop();
    RightMotorA.stop();
    RightMotorB.stop();
    RightMotorC.stop();
}