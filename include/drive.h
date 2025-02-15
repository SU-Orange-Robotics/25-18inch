#include "vex.h"
#include <math.h>

#pragma once

class Drive {
    private:

        const double deadzone = 10; // from 0 to 100
        const double tankForwardDeadzone = 20; // difference b/t stick values (0 to 200)
        const double maxOutputPct = 100; // limits maximum motor output percentage

        bool invertDrive;

        static double maxClamp(double input, double max) {
            return (fabs(input) <= max ? input : max * (input / fabs(input)));
        }

        void inputAdjust(double &fwd, double &str);

    public:
        Drive();

        void arcadeDrive(double y, double x);

        void tankDrive(double left, double right);

        void toggleInvertDrive();

        void driveForward(double pow, double time);

        void leftDrive(double pow);
        void rightDrive(double pow);

        void stop();
};