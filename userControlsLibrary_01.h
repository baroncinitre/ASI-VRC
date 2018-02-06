//all user 1 control functions

//user control function for the lift
void liftControls()
{
	motor[rightLift] = vexRT[Ch2];
	motor[leftLift] = vexRT[Ch2];
}

//user control function for arcade control
void arcadeControls()
{
	if(vexRT[Ch3] > 0)
	{
		motor[frontLeft] = (vexRT[Ch4] + vexRT[Ch3]);
		motor[frontRight] = (vexRT[Ch4] - vexRT[Ch3]);
		motor[backLeft] = (vexRT[Ch4] + vexRT[Ch3]);
		motor[backRight] = (vexRT[Ch4] - vexRT[Ch3]);
	}
	else
	{
		motor[frontLeft] = (vexRT[Ch4] + vexRT[Ch3]) * 0.8;
		motor[frontRight] = (vexRT[Ch4] - vexRT[Ch3]) * 0.8;
		motor[backLeft] = (vexRT[Ch4] + vexRT[Ch3]) * 0.8;
		motor[backRight] = (vexRT[Ch4] - vexRT[Ch3]) * 0.8;
	}
}

//user control function for the claw
void clawControls()
{
	if(vexRT[Btn5D] == 1)	//opens claw
	{
		motor[intake] = -127;
	}
	else if(vexRT[Btn5U] == 1)
	{
		motor[intake] = 30;
	}
	else	//automatically closes due to rubber bands
	{
		motor[intake] = 0;
	}
}

//user control function for the mobile lift
void mobileControls()
{
	if(vexRT[Btn8R] == 1) //raises the mobile lift
	{
		motor[mobile] = 127;
	}
	else if(vexRT[Btn8D] == 1 && SensorValue(rangeFinder) > mobileLow) //drops the lift to the mobile goal height
	{
		if(SensorValue(rangeFinder) - mobileLow > 15)
		{
			motor[mobile] = -127;
		}
		else
		{
			motor[mobile] = -30;
		}
	}
	else if(vexRT[Btn8L] == 1) //drops the lift as low as possible
	{
		motor[mobile] = -127;
	}
	else if(vexRT[Btn8U] == 1 && SensorValue(rangeFinder) < mobileHigh)
	{
		motor[mobile] = 127;
	}
	else
	{
		motor[mobile] = 0;
	}
}

//user control function for arms
void armsControls()
{
	if(vexRT[Btn6U] == 1) //swings arms out
	{
		motor[leftArm] = -80;
		motor[rightArm] = -80;
	}
	else if(vexRT[Btn6D] == 1) //swings arms in
	{
		motor[leftArm] = 80;
		motor[rightArm] = 80;
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
	if(vexRT[Btn7U] == 1)
	{
		if(stackHeight < 5)
		{
			//declare variables that set the speed based on the encoder values relative to the desired values
			int armSpeed, liftSpeed;

			//set the arm speed positive if it needs to swing out, negative if otherwise
			if(stackValues[1][stackHeight] > SensorValue(armEncoder))
			{
				armSpeed = -30;
			}
			else
			{
				armSpeed = 30;
			}

			//set the lift speed positive if it needs to move up, negative if otherwise
			if(stackValues[0][stackHeight] > abs(SensorValue(liftEncoder)))
			{
				liftSpeed = 60;
			}
			else
			{
				liftSpeed = -60;
			}

			//while loop that runs the lift until it achieves the desired height based on the amount of stacked cones
			while(abs(SensorValue(pot)) < stackValues[0][stackHeight])
			{
				motor[leftLift] = liftSpeed;
				motor[rightLift] = liftSpeed;
			}
			motor[leftLift] = 0;
			motor[rightLift] = 0;

			//while loop that runs the arms until it achieves the desired value based on the amount of stacked cones
			while(abs(SensorValue(armEncoder)) < stackValues[1][stackHeight])
			{
				motor[leftArm] = armSpeed;
				motor[rightArm] = armSpeed;
			}
			motor[leftArm] = 0;
			motor[rightArm] = 0;

			//drops the cone onto the goal
			openClaw();

			//shifts the values used in stackValues over 1 to represent an additional cone on the mobile goal
			stackHeight++;
		}
	}

	//resets the values used in stackValues to represent 0 cones on the mobile goal
	if(vexRT[Btn7L] == 1)
	{
		stackHeight = 0;
	}
}

//returns all encoder values to a global variable so we have access in the debugger
void returnValues()
{
	liftTicks = SensorValue(liftEncoder);
	armTicks = SensorValue(armEncoder);
	mobileTicks = nMotorEncoder[mobile];
	flTicks = nMotorEncoder[frontLeft];
	rangeFinderValue = SensorValue(rangeFinder);
	backLeftSpeed = motor[backLeft];
	frontRightSpeed = motor[frontRight];
	gyroTicks = SensorValue(gyro);
	leftLiftSpeed = motor[leftLift];
	rightLiftSpeed = motor[rightLift];
	leftArmSpeed = motor[leftArm];
	rightArmSpeed = motor[rightArm];
	potValue = SensorValue(pot);
}
