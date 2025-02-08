/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Andrew Tedesco                                            */
/*    Created:      1/24/2025, 5:27:31 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "drive.h"
#include "intakeLift.h"
#include "mogoMech.h"
#include "robot-config.h"

using namespace vex;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...

  MogoMech.setStopping(brakeType::hold);

  LeftMotorA.setStopping(brakeType::brake);
  LeftMotorB.setStopping(brakeType::brake);
  LeftMotorC.setStopping(brakeType::brake);

  RightMotorB.setStopping(brakeType::brake);
  RightMotorA.setStopping(brakeType::brake);
  RightMotorC.setStopping(brakeType::brake);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    //drive.tankDrive(Controller1.Axis3.position(), Controller1.Axis2.position());

    // 2 stick arcade
    drive.arcadeDrive(Controller1.Axis3.position(), Controller1.Axis1.position());


    Controller1.ButtonX.pressed([](){
      drive.toggleInvertDrive();
    });


    // mogomech stuff
    Controller1.ButtonR1.pressed([](){
      mogoUp();
    });

    Controller1.ButtonR1.released([](){
      mogoStop();
    });

    Controller1.ButtonLeft.pressed([](){
      mogoDown();
    });

    Controller1.ButtonLeft.released([](){
      mogoStop();
    });

    Controller1.ButtonRight.pressed([](){
      mogoUp();
    });

    Controller1.ButtonRight.released([](){
      mogoStop();
    });


    // main intake and lift control
    Controller1.ButtonR2.pressed([](){
      intakeSpin();
      chainliftSpin();
    });

    Controller1.ButtonR2.released([](){
      intakeStop();
      chainliftStop();
    });


    // secondary chainlift controls
    Controller1.ButtonUp.pressed([](){
      chainliftSpin();
    });

    Controller1.ButtonUp.released([](){
      chainliftStop();
    });

    Controller1.ButtonDown.pressed([](){
      chainliftSpin(true);
    });

    Controller1.ButtonDown.released([](){
      chainliftStop();
    });


    // secondary intake controls
    Controller1.ButtonL2.pressed([](){
      intakeSpin();
    });

    Controller1.ButtonL2.released([](){
      intakeStop();
    });

    Controller1.ButtonL1.pressed([](){
      intakeSpin(true);
    });

    Controller1.ButtonL1.released([](){
      intakeStop();
    });



    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec); // lower this time if we actually use this loop for anything
  }
}
