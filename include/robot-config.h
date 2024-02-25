#pragma once
#include "main.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);
#define INTAKE_FORWARD DIGITAL_R1
#define INTAKE_REVERSE DIGITAL_R2

#define CATA_FORWARD DIGITAL_L1
#define CATA_REVERSE DIGITAL_L2

pros::Motor leftFrontMotor(15, pros::E_MOTOR_GEAR_BLUE, true);
pros::Motor leftBackMotor(12, pros::E_MOTOR_GEAR_BLUE, true);
pros::Motor leftBackTopMotor(13, pros::E_MOTOR_GEAR_BLUE, false);
pros::Motor rightFrontMotor(18, pros::E_MOTOR_GEAR_BLUE, false);
pros::Motor rightBackMotor(20, pros::E_MOTOR_GEAR_BLUE, false);
pros::Motor rightBackTopMotor(19, pros::E_MOTOR_GEAR_BLUE, true);

pros::Motor_Group leftMotors({leftFrontMotor, leftBackMotor, leftBackTopMotor});
pros::Motor_Group rightMotors({rightFrontMotor, rightBackMotor, rightBackTopMotor});

pros::Motor_Group leftAuton({leftFrontMotor, leftBackMotor});
pros::Motor_Group rightAuton({rightFrontMotor, rightBackMotor});

pros::Motor_Group leftAutonSmall({leftFrontMotor});
pros::Motor_Group rightAutonSmall({rightFrontMotor});

pros::Motor intake(10, pros::E_MOTOR_GEAR_BLUE, false);

pros::Motor catapult(11, pros::E_MOTOR_GEAR_RED, false);

pros::ADIDigitalOut vertWings(1);
pros::ADIDigitalOut horiWings(2);
pros::ADIDigitalOut hang(3);

pros::Imu imu(14);
         
lemlib::Drivetrain_t drivetrain {
    &leftMotors,
    &rightMotors,
    11.2, // track width
    4, // wheel diameter
    343, // wheel rpm
};

lemlib::Drivetrain_t drivetrainSmall {
    &leftAutonSmall,
    &rightAutonSmall,
    11.2,
    4,
    343,
};

// TODO: Figure out sensor siuation
lemlib::OdomSensors_t sensors {
    nullptr, // vertical tracking wheel 1
    nullptr, // vertical tracking wheel 2
    nullptr, // horizontal tracking wheel 1
    nullptr, // horizontal track wheel 2
    &imu // intertial sensor
};

// forward/backward PID
lemlib::ChassisController_t lateralController {
    60, // kP
    90, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};
 
// turning PID
lemlib::ChassisController_t angularController {
    10, // kP
    60, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    0 // slew rate
};

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);
lemlib::Chassis chassisSmall(drivetrainSmall, lateralController, angularController, sensors);
lemlib::Chassis chassis2(drivetrain, lateralController, angularController, sensors);