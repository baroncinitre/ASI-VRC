#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    gyro,           sensorGyro)
#pragma config(Sensor, in2,    liftPot,        sensorPotentiometer)
#pragma config(Sensor, in3,    armPot,         sensorPotentiometer)
#pragma config(Sensor, dgtl1,  flEncoder,      sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  liftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  rangeFinder,    sensorSONAR_mm)
#pragma config(Sensor, I2C_1,  frontLeftEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           frontLeft,     tmotorVex393HighSpeed_HBridge, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port2,           backLeft,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftArm,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightLift,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           leftLift,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           rightArm,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           mobile,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           backRight,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          frontRight,    tmotorVex393HighSpeed_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(145)

//adds functions for use without cluttering main program
#include "Vex_Competition_Includes.c"
#include "variableLibrary_01.h"
#include "autonLibrary_01.h"
#include "userControlsLibrary_01.h"
#include "preAutonLibrary_01.h"

//FILE REVISION NOTES:
//dual joystick control

void pre_auton()
{
	preAutonTasks();
	bStopTasksBetweenModes = true;
}

/*
AUTONOMOUS SET UP NOTES:

ALWAYS cycle the cortex before each test
Push arms in until front of claw is just in line with front of 4bar
Drop mobile lift until just slightly above the ground
Drop lift so that it lies just on top of the mobile lift
Use spacing tool with one end (lengthwise) at the glass wall, pushed against 10 point bar
Push side of robot until it connects with the spacing tool
Use LCD to select which autonomous you want to run
Test, record values, and repeat
*/

task autonomous()
{
	//Clear LCD
	resetEncoders();
	clearLCDLine(0);
	clearLCDLine(1);

	//Switch Case that runs the user choice
	switch(auton)
	{
	case 0:
		//One cone then move left
		lift(170, 80);
		arms(110, 127);
		lift(92, -30);
		openClaw();
		holdOpen();
		timeDrop(100);
		arms(45, 90);
		closeClaw();
		turn(55, -60);
		move(350, 100);
		finished = true;
		break;
	case 1:
		//One cone then move right
		lift(170, 80);
		arms(110, 127);
		lift(92, -30);
		openClaw();
		holdOpen();
		timeDrop(100);
		arms(45, 90);
		closeClaw();
		turn(55, 60);
		move(350, 100);
		finished = true;
		break;
	case 2:
		//Blue side two cones
		lift(170, 80);
		arms(110, 127);
		lift(92, -30);
		openClaw();
		holdOpen();
		arms(45, 90);
		timeDrop(100);
		move(3, 60);
		brake(-20);
		turn(19, -60);
		turnBrake(60);
		arms(42, 30);
		move(12.25, 70);
		brake(-10);
		closeClaw();
		wait1Msec(500);
		lift(170, 80);
		arms(110, 127);
		turn(85, 60);
		turnBrake(-5);
		move(1.2, -60);
		lift(85, 30);
		openClaw();
		holdOpen();
		move(10, -60);
		finished = true;
		break;
	case 3:
		//Red side two cones
		lift(170, 60);
		arms(125, 100);
		lift(85, 30);
		openClaw();
		holdOpen();
		arms(45, 90);
		lift(5, 20);
		move(3, 60);
		brake(-20);
		turn(19, 60);
		turnBrake(-60);
		arms(42, 30);
		move(12.25, 70);
		brake(-10);
		closeClaw();
		wait1Msec(500);
		lift(180, 60);
		arms(130, 90);
		turn(85, -60);
		turnBrake(5);
		move(1.2, -60);
		lift(85, 30);
		openClaw();
		holdOpen();
		move(10, -60);
		finished = true;
		break;
	case 4:
		//Blue side 20 point mobile
		clearTimer(T1);
		SensorValue(liftEncoder) = 0;
		SensorValue(armPot) = 0;
		SensorValue(frontLeft) = 0;
		SensorValue(gyro) = 0;
		lift(2525, 80);
		tickMove(1700, 100);
		brake(-60);
		mobileLift(mobileCarry);
		openClaw();
		lift(3000, 80);
		tickBackUp(825, 120);
		turn(165, -120);
		turnBrake(120);
		tickMove(900, 120);
		tickMove(200, 60);
		turn(42, -120);
		turnBrake(120);
		tickMoveLift(1025, 127, mobileHigh, 60);
		tickBackUp(600, 127);
		autonTime = time1[T1];
		finished = true;
		break;
	case 5:
		//Red side 20 point mobile
		clearTimer(T1);
		SensorValue(liftEncoder) = 0;
		SensorValue(armPot) = 0;
		SensorValue(frontLeft) = 0;
		SensorValue(gyro) = 0;
		lift(2525, 80);
		move(1700, 100);
		brake(-60);
		mobileLift(mobileCarry);
		openClaw();
		lift(3000, 80);
		backUp(725, 120);
		backUp(100, 30);
		turn(165, 120);
		turnBrake(-120);
		move(900, 120);
		move(200, 60);
		turn(42, 120);
		turnBrake(-120);
		moveLift(925, 127, mobileHigh, 60);
		backUp(600, 127);
		autonTime = time1[T1];
		finished = true;
		break;
	case 6:
		//Blue side 10 point mobile
		clearTimer(T1);
		SensorValue(liftEncoder) = 0;
		SensorValue(armPot) = 0;
		SensorValue(frontLeft) = 0;
		SensorValue(gyro) = 0;
		wait1Msec(2000);
		lift(2500, 80);
		move(1700, 100);
		brake(-60);
		mobileLift(mobileCarry);
		openClaw();
		backUp(725, 120);
		backUp(100, 30);
		turn(165, -120);
		turnBrake(120);
		move(575, 60);
		turn(40, -120);
		turnBrake(120);
		moveLift(375, 127, mobileMax, 120);
		wait1Msec(500);
		backUp(400, 127);
		finished = true;
		autonTime = time1[T1];
		break;
	case 7:
		//Red side 10 point mobile
		clearTimer(T1);
		SensorValue(liftEncoder) = 0;
		SensorValue(armPot) = 0;
		SensorValue(frontLeft) = 0;
		SensorValue(gyro) = 0;
		wait1Msec(2000);
		lift(2500, 80);
		move(1700, 80);
		brake(-60);
		mobileLift(mobileCarry);
		openClaw();
		backUp(725, 120);
		backUp(100, 30);
		turn(165, 120);
		turnBrake(-120);
		move(575, 60);
		turn(40, 120);
		turnBrake(-120);
		moveLift(425, 127, mobileMax, 120);
		wait1Msec(500);
		backUp(415, 127);
		autonTime = time1[T1];
		finished = true;
		break;
	case 8:
		resetEncoders();
		mobileMax = 120;
		clearLCDLine(0);
		clearLCDLine(1);
		SensorValue(liftEncoder) = 0;
		SensorValue(armPot) = 0;
		SensorValue(gyro) = 0;
		SensorValue(frontLeft) = 0;
		lift(3300, 120);
		move(1050, 100);
		wait1Msec(500);
		mobileLift(mobileCarry);
		timeDrop(400);
		openClaw();
		holdOpen();
		lift(3300, 120);
		closeClaw();
		turn(180, -75);
		turnBrake(75);
		move(670, 100);
		turn(78, -90);
		turnBrake(90);
		move(550, 90);
		turn(75.5, 90);
		turnBrake(-90);
		moveLift(975, 127, mobileCarry, 75);//score 22
		backUp(600, 127);
		turn(96, -90);
		turnBrake(90);
		move(210, 90);
		turn(75, -90);
		turnBrake(90);
		mobileLift(mobileLow);
		move(850, 100);
		mobileLift(mobileCarry);
		turn(187, 90);
		turnBrake(-90);
		moveLift(1500, 120, 130,  127);//score 10
		backUp(150, 90);
		turn(90, -90);
		turnBrake(90);
		move(200, 100);
		mobileLift(mobileLow);
		turn(45, -90);
		turnBrake(90);//tre code
		move(900, 120);
		move(200, 20);
		brake(-60);
		move(400, 120);
		brake(-60);
		mobileLift(mobileCarry);
		openClaw();
		backUp(900, 120);
		backUp(100, 30);
		turn(165, -120);
		turnBrake(120);
		move(700, 60);
		turn(42, -120);
		turnBrake(120);
		backUp(250,120);
		moveLift(625, 127, 130, 127);
		wait1Msec(500);
		backUp(400, 127);
		break;
	}
	AutonomousCodePlaceholderForTesting();  // DO NOT REMOVE THIS
}

task usercontrol()
{
	SensorValue(armPot) = 0;
	while(true)
	{
		if(!skillsOn)
		{
			arcadeControls();

			liftControls();

			clawControls();

			mobileControls();

			armsControls();

			//internal();

			returnValues();
		}
		else
		{
			arcadeControls();

			liftControls();

			clawControls();

			mobileControls();

			armsControls();

			//internal();

			skillsMove();

			returnValues();
		}
	}
}
