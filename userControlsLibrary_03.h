//all user 1 control functions

//user control function for the lift
void liftControls()
{
	motor[rightLift] = vexRT[Ch2];
	motor[leftLift] = vexRT[Ch2];
}

//user control function for the claw
void intakeControls()
{
	if(vexRT[Btn5D] == 1)
	{
		motor[intake] = -127;
	}
	else if(vexRT[Btn5U] == 1)
	{
		motor[intake] = 127;
		cone = false;
	}
	else
	{
		if(cone == false)
		{
			motor[intake] = 0;
		}
		else
		{
			motor[intake] = -40;
		}
	}

	if(SensorValue(coneButton) == 1)
	{
		cone = true;
	}
}

//user control function for arms
void armsControls()
{
	if(vexRT[Btn6U] == 1) //swings arms out
	{
		motor[leftArm] = -70;
		motor[rightArm] = -70;
	}
	else if(vexRT[Btn6D] == 1) //swings arms in
	{
		motor[leftArm] = 70;
		motor[rightArm] = 70;
	}
	else
	{
		motor[leftArm] = 0;
		motor[rightArm] = 0;
	}
}

//user control function to stack cones internally
void internal()
{
	//stacks a cone internally
	if(vexRT[Btn7D] == 1)
	{
		//release cone
		openClaw();
		holdOpen();

		//raise/drop lift to first height
		if(SensorValue[liftPot] < grabValues[0])
		{
			lift(grabValues[0], 60);
		}
		else
		{
			dropLift(grabValues[0], 20);
		}

		//swing arms out/in to grabbing levels
		if(SensorValue[armPot] < grabValues[1])
		{
			arms(grabValues[1], 60);
		}
		else
		{
			armsIn(grabValues[1], 60);
		}
	}
}

//returns all encoder values to a global variable so we have access in the debugger
void returnValues()
{
	liftTicks = SensorValue(liftEncoder);
	armTicks = SensorValue(armPot);
	mobileTicks = nMotorEncoder[mobile];
	blTicks = nMotorEncoder[backLeft];
	rangeFinderValue = SensorValue(rangeFinder);
	backLeftSpeed = motor[backLeft];
	frontRightSpeed = motor[frontRight];
	gyroTicks = SensorValue(gyro);
	leftLiftSpeed = motor[leftLift];
	rightLiftSpeed = motor[rightLift];
	leftArmSpeed = motor[leftArm];
	rightArmSpeed = motor[rightArm];
	potValue = SensorValue(liftPot);
}
