#include "vex.h"
#include <math.h>

#pragma once

class Drive {
    private:

        const double tankForwardDeadzone = 20;
        const double maxOutputPct = 100; // limits maximum motor output percentage

        static double maxClamp(double input, double max) {
            return (fabs(input) <= max ? input : max * (input / fabs(input)));
        }

    public:
        Drive();

        void arcadeDrive(double y, double x);

        void tankDrive(double left, double right);

        void leftDrive(double pow);
        void rightDrive(double pow);
};