#include "main.h"
//include "robot-config.h"

void screen() {
  while (true) {
    lemlib::Pose pose =
        chassis.getPose(); // get the current position of the robot
    pros::lcd::clear_line(1);
    pros::lcd::print(1, "x: %f in", pose.x); // print the x position
    pros::lcd::clear_line(2);
    pros::lcd::print(2, "y: %f in", pose.y); // print the y position
    pros::lcd::clear_line(3);
    pros::lcd::print(3, "heading: %f deg",
                     pose.theta); // print the heading
    pros::delay(200);  
  }
}


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::print(1, "sussy balls 3");

	chassis.calibrate();
	chassis.setPose(0, 0, 0); // X: 0, Y: 0, Heading: 0
	// chassisSmall.calibrate();
	// chassisSmall.setPose(0, 0, 0);

	//new pros::Task {screen}; // create a task to print the position to the screen
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

void skillsSRR() {
	intakeLever.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	chassis.setPose(0, 0, 0, false);
	//chassis.moveTo(0, 10, 1000);
	chassis.moveTo(0, -25, 1000);
	chassis.setPose(0, 0, 0, false);
	chassis.moveTo(0, 40, 1000);
	chassis.setPose(0, 0, 0, false);
	chassis.turnTo(-70, 0, 1000);
	// chassisSmall.setPose(0, 0, 0, false);
	// chassisSmall.moveTo(0, 500, 1000);

	leftMotors.move(127);
	pros::delay(500);
	leftMotors.move(0);

	pros::lcd::clear_line(1);
	pros::lcd::print(1, "got past left");

	intakeLever.move(-127);
	pros::delay(1200);
	intakeLever.move(0);

	pros::lcd::clear_line(1);
	pros::lcd::print(1, "got past intakelever");

	while (true) { 
		flywheelMotor.move(-127);
	}
}

void skills() {
	intakeLever.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	chassis.setPose(0, 0, 0, false);
	chassis.moveTo(0, 10, 1000);
}

void raiseStick() {
	intakeLever.move_relative(-2900, 100);
}

void skillsPNW() {
	chassis.setPose(0, 0, 0, false);
	chassis.moveTo(0, -25, 1000);
	chassis.moveTo(0, 0, 1000);
	chassis.setPose(0, 0, false);
	chassis.turnTo(-60, 0, 1000);
	chassis.setPose(0, 0, 0, false);
	chassis.moveTo(0, 7, 1000);
	chassis.setPose(0, 0, 0, false);
	//chassis.turnTo(-11.5, -11.5, 1000);
	
	intakeLever.move_relative(-2900, 100);
	chassis.moveTo(0, 5, 1000);
	pros::delay(2000);
	chassis.setPose(0, 0, 0, false);
	pros::delay(2000);
	intakeLever.move_relative(2800, 100);

	chassis.turnTo(60, 0, 1000);
	chassis.setPose(0, 0, 1000);
	chassis.turnTo(30, 30, 1000);
}



/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	skillsPNW();
	//raiseStick();
}



/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */ 
void opcontrol() {
	leftMotors.set_brake_modes(pros::E_MOTOR_BRAKE_BRAKE);
	rightMotors.set_brake_modes(pros::E_MOTOR_BRAKE_BRAKE);
	intakeLever.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	//catapultMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	while (true) {
		int power = controller.get_analog(ANALOG_LEFT_Y);
		int turn = controller.get_analog(ANALOG_RIGHT_X);
		int left = power + turn;
		int right = power - turn;
		leftMotors.move(left);
		rightMotors.move(right);

		
		if (controller.get_digital(DIGITAL_R2)) {
			flywheelMotor.move(127);
		} else if (controller.get_digital(DIGITAL_R1)) {
			flywheelMotor.move(-127);
		} else if (controller.get_digital(DIGITAL_L2)){
			flywheelMotor.move(63.5);
		} else if (controller.get_digital(DIGITAL_L1)) {
			flywheelMotor.move(-63.5);
		} else {
			flywheelMotor.move(0);
		}

		if (controller.get_digital(DIGITAL_UP)) {
			intakeLever.move(127);
		} else if (controller.get_digital(DIGITAL_DOWN)) {
			intakeLever.move(-127);
		} else {
			intakeLever.move(0);
		}

		if (controller.get_digital(DIGITAL_X)) {
			wings.set_value(1);
		} else if (controller.get_digital(DIGITAL_Y)) {
			wings.set_value(0);
		}

		pros::delay(2);
	}
}