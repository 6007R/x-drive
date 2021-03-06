#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
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
	driveFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	driveLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	driveBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	driveRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	//pros::ADIGyro gyro('B', 0.972); //Gyro Scale
	//pros::delay(2000);
	//float gyrodrift = calculateGyroDrift();
	//printf("gyro drift = %f \n",gyrodrift);

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
	double angle = 0;
	move(300,300,0,angle);
}


void opcontrol() {
	//autonomous();
	double angle = 0;
	while(true){
		pros::delay(10);
		setDriveMotors(angle);
		printf("F");
	}
}

//printf("Rot intergral: %f \n", rot[2]);
//printf("Rot velocity: %f \n", rot[1]);
//printf("Rot derivative: %f \n", rot[0]);
//printf("X intergral: %f \n", x_int);
//printf("Rotation: %f \n\n", rot_vel);
//printf("Gyro Value = %f\n",gyrovalue);
//printf("\n");
