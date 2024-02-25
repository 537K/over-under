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
	pros::lcd::print(1, "running");

	chassis.calibrate();
	//chassis.setPose(-39.973, -61.233, 0, false);
	chassis.setPose(0, 0, 0); // X: 0, Y: 0, Heading: 0
	hang.set_value(0);
	// chassisSmall.calibrate();
	// chassisSmall.setPose(0, 0, 0);

	new pros::Task {screen}; // create a task to print the position to the screen
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

void skillsExo() {
	// Move to () look at (43.892, -6.858, 57.202)
	catapult.move(-100);
	pros::delay(40000);
	catapult.move(0);
	chassis.calibrate();
chassis.setPose(-43.525, -58.415, 57.202, false);
//chassis.moveTo(-41.709, -57.92, 1000);
chassis.moveTo(32.932, -57.759, 1000);
chassis.moveTo(48.086, -52.761, 1000);
chassis.turnTo(0, -100, 1000);
chassis.moveTo(58.726, -40.026, 1000);
chassis.moveTo(62, -28.257, 1000);
chassis.moveTo(58.726, -40.026, 1000);
chassis.moveTo(38.252, -33.738, 1000);
chassis.moveTo(20.035, -30.837, 1000);
chassis.moveTo(16.489, -15.199, 1000);
vertWings.set_value(1);
chassis.turnTo(-16, -15, 1000);
chassis.moveTo(45.897, -11.975, 5000);
chassis.moveTo(15.844, -9.395, 5000);
chassis.moveTo(45.897, -11.975, 5000);
chassis.moveTo(15.844, -9.395, 5000);
chassis.moveTo(45.673, -1.335, 5000);
chassis.moveTo(16.166, 8.499, 5000);
chassis.moveTo(45.673, -1.335, 5000);
chassis.moveTo(16.166, 8.499, 5000);
chassis.moveTo(45, 10.917, 5000);
chassis.moveTo(16.166, 8.499, 5000);
chassis.moveTo(45, 10.917, 5000);
chassis.moveTo(16.166, 8.499, 5000);
}

void skillsSkyler() {
	leftMotors.set_voltage_limit(127000);
	rightMotors.set_voltage_limit(127000);
	chassis.setPose(-39.973, -61.233, 0, false);
	chassis.moveTo(-39.973, -35, 1000);
	chassis.turnTo(43.892, -6.858, 2000);
	chassis.moveTo(-58, -35, 1000);
	chassis.turnTo(43.892, -6.858, 1000);
	
	chassis2.setPose(0, 0, 0, false);
	chassis2.moveTo(0, -30, 1000);
	lemlib::Pose real = chassis.getPose();
	catapult.move(-106);
	pros::delay(33000);
	catapult.move(0);
	chassis.calibrate();
	chassisSmall.setPose(0, 0, 0, false);
	chassisSmall.moveTo(0, 3, 1000);
	chassis.setPose(real.x, real.y, real.theta);

	chassis.moveTo(-35.282, -62.654, 1000);
	chassis.turnTo(-100, chassis.getPose().y, 1000);
	chassis.moveTo(36, -64.5, 5000);
chassis.moveTo(54.61, -48.721, 1000);
chassis.turnTo(0, -100, 1000);
chassis.moveTo(58.726, -40.026, 1000);
chassis.moveTo(62, -28.257, 1000);
chassis.moveTo(58.726, -40.026, 1000);
chassis.moveTo(62, -28.257, 1000);
chassis.moveTo(38.252, -33.738, 1000);
chassis.moveTo(20.035, -30.837, 1000);
chassis.moveTo(16.489, -15.199, 1000);
vertWings.set_value(1);
chassis.turnTo(-16, -15, 1000);
chassis.moveTo(45.897, -11.975, 1000);
vertWings.set_value(0);
chassis.moveTo(15.844, -9.395, 1000);
vertWings.set_value(1);
// chassis.moveTo(45.897, -11.975, 1000);
// chassis.moveTo(15.844, -9.395, 1000);
chassis.moveTo(45.673, -1.335, 1000);
vertWings.set_value(0);
chassis.moveTo(16.166, 8.499, 1000);
vertWings.set_value(1);
chassis.moveTo(45.673, -1.335, 1000);
vertWings.set_value(0);
chassis.moveTo(16.166, 8.499, 1000);
vertWings.set_value(0);
chassis.moveTo(31.685, 38.703, 1000);
chassis.moveTo(42.697, 57.581, 1000);
chassis.moveTo(55.956, 35.332, 1000);
// chassis.moveTo(45, 10.917, 1000);
// chassis.moveTo(16.166, 8.499, 1000);

}

void skillsVoltage() {
	chassis.setPose(-41.577, -58.605, 144.48, false);
	chassis.moveTo(-60.679, -30.064, 1000);
	chassis.moveTo(chassis.getPose().x, chassis.getPose().y - 5, 1000);

	chassis.turnTo(43.892, 20, 1000);
	chassis.moveTo(-58, -42.03, 1000);
	chassis.turnTo(43.892, 10, 1000);
	lemlib::Pose real = chassis.getPose();
	chassisSmall.setPose(0, 0, 0, false);
	chassisSmall.moveTo(0, -10, 1000);
	
	catapult.move(-106);
	pros::delay(27000);
	catapult.move(0);
	chassis.calibrate();
	chassisSmall.setPose(0, 0, 0, false);
	chassisSmall.moveTo(0, 3, 1000);
	chassis.setPose(real.x, real.y, real.theta);

	chassis.moveTo(-35.282, -62.654, 1000);
	chassis.turnTo(-100, chassis.getPose().y, 1000);
	chassis.moveTo(36, -64.5, 5000);
chassis.moveTo(54.61, -48.721, 1000);
chassis.turnTo(0, -100, 1000);
chassis.moveTo(58.726, -40.026, 1000);
chassis.moveTo(62, -28.257, 1000);
chassis.moveTo(58.726, -40.026, 1000);
chassis.moveTo(62, -28.257, 1000);
chassis.moveTo(38.252, -33.738, 1000);
chassis.moveTo(20.035, -30.837, 1000);
chassis.moveTo(16.489, -15.199, 1000);
vertWings.set_value(1);
chassis.turnTo(-16, -15, 1000);
chassis.moveTo(45.897, -11.975, 1000);
vertWings.set_value(0);
chassis.moveTo(15.844, -9.395, 1000);
vertWings.set_value(1);
// chassis.moveTo(45.897, -11.975, 1000);
// chassis.moveTo(15.844, -9.395, 1000);
chassis.moveTo(45.673, -1.335, 1000);
vertWings.set_value(0);
chassis.moveTo(16.166, 8.499, 1000);
vertWings.set_value(1);
chassis.moveTo(45.673, -1.335, 1000);
vertWings.set_value(0);
chassis.moveTo(16.166, 8.499, 1000);
vertWings.set_value(0);
chassis.moveTo(31.685, 38.703, 1000);
chassis.moveTo(42.697, 57.581, 1000);
chassis.moveTo(55.956, 35.332, 1000);
// chassis.moveTo(45, 10.917, 1000);
// chassis.moveTo(16.166, 8.499, 1000);
}

void farSideShort() {
	// // intakeLever.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	vertWings.set_value(1);
	chassis.setPose(0, 0, 0, false);
	chassis.moveTo(0, -20, 1000);
	chassis.moveTo(0, 0, 1000);
	// chassis.setPose(0, 0, 0, false);
	// chassis.turnTo(-15, 15, 1000);
	// chassis.setPose(0, 0, 0, false);
	// vertWings.set_value(0);
	// chassis.setPose(0, 0, 0, false);
	// chassis.moveTo(0, -15, 1000);
	// chassis.moveTo(0, 0, 1000);
	// //chassis.setPose(0, 0, 0, 1000);
	// //chassis.turnTo(-60, 0, 1000);
	// //chassis.moveTo(0, 0, 1000);
	// ch
	// m  nhb8ssis.setPose(0, 0, 0, false);
	// //chassis.turnTo(15, 15, 1000);
// 	// chassis.setPose(0, 0, 0, false);
// 	// chassis.moveTo(0, -20, 1000);
// 	chassis.moveTo(0, 0, 5000);
// chassis.moveTo(0.294, -16.786, 5000);
// chassis.moveTo(8.898, -26.176, 5000);
}

void farSideExo() {
	chassis.setPose(0, 0, 0, false);
	vertWings.set_value(1);
	chassis.moveTo(0, -15, 1000);
	vertWings.set_value(0);
	chassis.moveTo(0, -20, 1000);
	chassis.setPose(0, 0, 0, false);
	chassis.turnTo(-30, 45,1000);
	chassis.setPose(0, 0, 0, false);
	// chassis.moveTo(0, -100, 5000);
	// chassis.moveTo(0, -70, 5000);
	chassis.moveTo(0, -30, 1000);
	chassis.moveTo(0, -10, 1000);
	chassis.moveTo(0, -30, 1000);
	chassis.moveTo(0, -10, 1000);
}

void closeSideExo() {
	chassis.setPose(0, 0, 0, false);
	chassis.moveTo(0, 15, 1000);
	vertWings.set_value(1);
	chassis.moveTo(0, 5, 1000);
	vertWings.set_value(0);
	chassis.moveTo(0, -7, 1000);
	chassis.setPose(0, 0, 0, false);
	chassis.turnTo(-45, 37, 1000);
	chassis.setPose(0, 0, 0, false);
	chassis.moveTo(0, -29, 1000);
}

void closeSideVolt() {
	pros::delay(8000);
	intake.move(127);
	pros::delay(3000);
	intake.move(-127);
	
}

void tileTest() {
	// leftBackTopMotor.set_brake_mode()
	chassis.setPose(0, 0, 0, false);
	chassis.moveTo(0, 12, 10000);
	chassis.setPose(0, 0, 0, false);
	chassis.turnTo(0, 100, 10000);
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Managvement System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 * 
 */
void autonomous() {
	closeSideVolt();
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
	//int invert = 0;
	leftMotors.set_brake_modes(pros::E_MOTOR_BRAKE_BRAKE);
	rightMotors.set_brake_modes(pros::E_MOTOR_BRAKE_BRAKE);
	// intakeLever.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	//catapultMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	while (true) {
		// if (invert == 0) {
			int power = controller.get_analog(ANALOG_LEFT_Y);
			int turn = controller.get_analog(ANALOG_RIGHT_X);
			int left = power + turn;
			int right = power - turn;
			leftMotors.move(left);
			rightMotors.move(right);
		// } else {
		// 	int power = -(controller.get_analog(ANALOG_LEFT_Y));
		// 	int turn = -(controller.get_analog(ANALOG_RIGHT_X));
		// 	int left = power + turn;
		// 	int right = power - turn;
		// 	leftMotors.move(left);
		// 	rightMotors.move(right);
		// }

		if (controller.get_digital_new_press(DIGITAL_RIGHT)) {
			leftMotors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
			rightMotors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
			chassis.setPose(-39.973, -61.233, 0, false);
			chassis.moveTo(-39.973, -45, 1000);
			chassis.turnTo(43.892, -6.858, 1000);
			chassis.moveTo(-58, -42.03, 1000);
			chassis.turnTo(43.892, -12, 1000);
			lemlib::Pose real = chassis.getPose();
			chassis.setPose(0, 0, 0, false);
			chassis.moveTo(0, -10, 1000);
			leftMotors.set_brake_modes(pros::E_MOTOR_BRAKE_BRAKE);
			rightMotors.set_brake_modes(pros::E_MOTOR_BRAKE_BRAKE);
		}

		if (controller.get_digital(DIGITAL_X)) {
			horiWings.set_value(1);
		} else if (controller.get_digital(DIGITAL_Y)) {
			horiWings.set_value(0);
		}

		if (controller.get_digital(DIGITAL_A)) {
			vertWings.set_value(1);
		} else if (controller.get_digital(DIGITAL_B)) {
			vertWings.set_value(0);
		}

		if (controller.get_digital(DIGITAL_L1)) {
			catapult.move(-97);
		} else {
			catapult.move(0);
		}

		if (controller.get_digital(DIGITAL_R1)) {
			intake.move(-127);
		} else if (controller.get_digital(DIGITAL_R2)) {
			intake.move(127);
		} else {
			intake.move(0);
		}

		if (controller.get_digital(DIGITAL_UP)) {
			hang.set_value(1);
		} else if (controller.get_digital(DIGITAL_DOWN)) {
			hang.set_value(0);
		}

		
		// if (controller.get_digital(DIGITAL_R2)) {
		// 	// flywheelMotor.move(127);
		// } else if (controller.get_digital(DIGITAL_R1)) {
		// 	// flywheelMotor.move(-127);
		// } else if (controller.get_digital(DIGITAL_L2)){
		// 	// flywheelMotor.move(63.5);
		// } else if (controller.get_digital(DIGITAL_L1)) {
		// 	// flywheelMotor.move(-63.5);
		// } else {
		// 	// flywheelMotor.move(0);
		// }

		// if (controller.get_digital(DIGITAL_UP)) {
		// 	// intakeLever.move(-127);
		// } else if (controller.get_digital(DIGITAL_DOWN)) {
		// 	// intakeLever.move(127);
		// } else {
		// 	// intakeLever.move(0);
		// }

		if (controller.get_digital(DIGITAL_X)) {
			// wings.set_value(1);
		} else if (controller.get_digital(DIGITAL_Y)) {
			// wings.set_value(0);
		}

		pros::delay(2);
	}
}
