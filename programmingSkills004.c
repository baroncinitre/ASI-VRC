#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    gyro,           sensorGyro)
#pragma config(Sensor, in2,    pot,            sensorPotentiometer)
#pragma config(Sensor, dgtl1,  armEncoder,     sensorQuadEncoder)
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

//FILE REVISION NOTES:
//dual joystick control

void pre_auton()
{
	auton = 0;
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
		resetEncoders();
		mobileMax= 120;
		clearLCDLine(0);
		clearLCDLine(1);
		SensorValue(liftEncoder) = 0;
		SensorValue(armEncoder) = 0;
		SensorValue(gyro) = 0;
		SensorValue(frontLeft) = 0;
		lift(3300, 120);
		move(1100, 100);
		wait1Msec(500);
		mobileLift(mobileHigh);
		dropLift(400);
		openClaw();
		holdOpen();
		lift(3500, 120);
		closeClaw();
		backUp(670, 100);
		turn(102, 90);
		turnBrake(-90);
		move(300, 90);
		turn(75.5, 90);
		turnBrake(-90);
		moveLift(975, 127, mobileHigh, 75);//score 22
		backUp(600, 127);
		turn(91, -90);
		turnBrake(90);
		move(210, 90);
		turn(73, -90);
		turnBrake(90);
		mobileLift(mobileLow);
		move(750, 100);//g2
		mobileLift(mobileHigh);
		backUp(300, 120);
		turn(195, 90);
		turnBrake(-90);
		moveLift(1200, 120, 150,  80);//score 32
		backUp(150, 90);
		turn(90, -90);
		turnBrake(90);
		move(200, 100);
		mobileLift(mobileLow);
		turn(41, -90);
		turnBrake(90);//tre code
		move(900, 120);
		move(200, 20);
		brake(-60);
		move(400, 120);
		brake(-60);
		mobileLift(mobileHigh);
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
	case 1:
		//One cone then move right
		resetEncoders();
		mobileMax= 120;
		clearLCDLine(0);
		clearLCDLine(1);
		SensorValue(liftEncoder) = 0;
		SensorValue(armEncoder) = 0;
		SensorValue(gyro) = 0;
		SensorValue(frontLeft) = 0;
		lift(3300, 120);
		move(1100, 100);
		wait1Msec(500);
		mobileLift(mobileHigh);
		dropLift(400);
		openClaw();
		holdOpen();
		lift(3500, 120);
		closeClaw();
		backUp(670, 100);
		turn(102, 90);
		turnBrake(-90);
		move(300, 90);
		turn(75.5, 90);
		turnBrake(-90);
		moveLift(975, 127, mobileHigh, 75);//score 22
		backUp(600, 127);
		turn(91, -90);
		turnBrake(90);
		move(210, 90);
		turn(73, -90);
		turnBrake(90);
		mobileLift(mobileLow);
		move(750, 100);//g2
		mobileLift(mobileHigh);
		backUp(300, 120);
		turn(195, 90);
		turnBrake(-90);
		moveLift(1250, 120, 150,  40);//score 32
		backUp(200, 90);
		turn(175, -90);
		turnBrake(90);
		mobileLift(60);
		moveLift(1650, 100, mobileLow, 120);//connect with g3
		turnBrake(75);
		move(670, 100);
		turn(78, -90);
		turnBrake(90);
		move(500, 90);
		turn(75.5, 90);
		turnBrake(-90);
		moveLift(975, 127, mobileHigh, 75);//score 52
		backUp(600, 127);
		turn(91, -90);
		turnBrake(90);
		move(210, 90);
		turn(73, -90);
		turnBrake(90);
		mobileLift(mobileLow);
		move(750, 100);//g4
		mobileLift(mobileHigh);
		backUp(100, 120);
		turn(195, 90);
		turnBrake(-90);
		moveLift(1500, 120, 150,  40);//score 62
		backUp(150, 90);
		finished = true;
		break;

	}
	AutonomousCodePlaceholderForTesting();  // DO NOT REMOVE THIS
}

task usercontrol()
{
	SensorValue(pot) = 0;
	while(true)
	{
		if(partner == false)
		{
			arcadeControls();

			liftControls();

			clawControls();

			mobileControls();

			armsControls();

			returnValues();

			//stack();
		}
		returnValues();
	}
}
