#include "main.h"

pros::Motor leftFrontMotor(1, pros::E_MOTOR_GEAR_BLUE, false);
pros::Motor leftBackMotor(2, pros::E_MOTOR_GEAR_BLUE, false);
pros::Motor rightFrontMotor(3, pros::E_MOTOR_GEAR_BLUE, false);
pros::Motor rightBackMotor(4, pros::E_MOTOR_GEAR_BLUE, false);

pros::Motor_Group leftMotors({leftFrontMotor, leftBackMotor});
pros::Motor_Group rightMotors({rightFrontMotor, rightBackMotor});

pros::Motor catapultMotor(5, pros::E_MOTOR_GEAR_RED, false);
pros::Motor intakeMotor(6, pros::E_MOTOR_GEAR_GREEN, false);

lemlib::Drivetrain_t drivetrain {
    &leftMotors,
    &rightMotors,
    11.2, // track width
    4, // wheel diameter
    343, // wheel rpm
};

// TODO: Figure out sensor siuation
lemlib::OdomSensors_t sensors {
    nullptr, // vertical tracking wheel 1
    nullptr, // vertical tracking wheel 2
    nullptr, // horizontal tracking wheel 1
    nullptr, // horizontal track wheel 2
    nullptr // intertial sensor
};

// forward/backward PID
lemlib::ChassisController_t lateralController {
    8, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};
 
// turning PID
lemlib::ChassisController_t angularController {
    4, // kP
    40, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    0 // slew rate
};

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);