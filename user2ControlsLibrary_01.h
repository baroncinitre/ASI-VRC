//all user 2 control functions

void liftControls2()
{
	if(vexRT[Btn7DXmtr2] == 1) //turns on slowdown if off, off if on
	{
		if(slowdown == false)
		{
			slowdown = true;
		}
		else if(slowdown == true)
		{
			slowdown = false;
		}
	}

	if(slowdown == true) //half speed if slowdown is true
	{
		motor[rightLift] = (vexRT[Ch2Xmtr2])/2;
		motor[leftLift] = (vexRT[Ch2Xmtr2])/2;
	}
	else //normal full speed if its not
	{
		motor[rightLift] = vexRT[Ch2Xmtr2];
		motor[leftLift] = vexRT[Ch2Xmtr2];
	}
}

//user control function for arcade control
void arcadeControls2()
{
	if(vexRT[Btn7LXmtr2] == 1) //turns on slowdown if off, off if on
	{
		if(drivetrainSlowdown == false)
		{
			drivetrainSlowdown = true;
		}
		else if(drivetrainSlowdown == true)
		{
			drivetrainSlowdown = false;
		}
	}

	if(drivetrainSlowdown == false)
	{
		if(vexRT[Ch3] > 0)
		{
			motor[frontLeft] = (vexRT[Ch4Xmtr2] + vexRT[Ch3Xmtr2]);
			motor[frontRight] = (vexRT[Ch4Xmtr2] - vexRT[Ch3Xmtr2]);
			motor[backLeft] = (vexRT[Ch4Xmtr2] + vexRT[Ch3Xmtr2]);
			motor[backRight] = (vexRT[Ch4Xmtr2] - vexRT[Ch3Xmtr2]);
		}
		else
		{
			motor[frontLeft] = (vexRT[Ch4Xmtr2] + vexRT[Ch3Xmtr2]) * 0.8;
			motor[frontRight] = (vexRT[Ch4Xmtr2] - vexRT[Ch3Xmtr2]) * 0.8;
			motor[backLeft] = (vexRT[Ch4Xmtr2] + vexRT[Ch3Xmtr2]) * 0.8;
			motor[backRight] = (vexRT[Ch4Xmtr2] - vexRT[Ch3Xmtr2]) * 0.8;
		}
	}
	else if(drivetrainSlowdown == true)
	{
		if(vexRT[Ch3] > 0)
		{
			motor[frontLeft] = (vexRT[Ch4Xmtr2] + vexRT[Ch3Xmtr2]) * dtSlowdownFactor;
			motor[frontRight] = (vexRT[Ch4Xmtr2] - vexRT[Ch3Xmtr2]) * dtSlowdownFactor;
			motor[backLeft] = (vexRT[Ch4Xmtr2] + vexRT[Ch3Xmtr2]) * dtSlowdownFactor;
			motor[backRight] = (vexRT[Ch4Xmtr2] - vexRT[Ch3Xmtr2]) * dtSlowdownFactor;
		}
		else
		{
			motor[frontLeft] = ((vexRT[Ch4Xmtr2] + vexRT[Ch3Xmtr2]) * 0.8) * dtSlowdownFactor;
			motor[frontRight] = ((vexRT[Ch4Xmtr2] - vexRT[Ch3Xmtr2]) * 0.8) * dtSlowdownFactor;
			motor[backLeft] = ((vexRT[Ch4Xmtr2] + vexRT[Ch3Xmtr2]) * 0.8) * dtSlowdownFactor;
			motor[backRight] = ((vexRT[Ch4Xmtr2] - vexRT[Ch3Xmtr2]) * 0.8) * dtSlowdownFactor;
		}
	}
}

//user control function for the claw
void clawControls2()
{
	if(vexRT[Btn5DXmtr2] == 1)	//opens claw
	{
		motor[intake] = -127;
	}
	else if(vexRT[Btn5UXmtr2] == 1)
	{
		motor[intake] = 30;
	}
	else	//automatically closes due to rubber bands
	{
		motor[intake] = 0;
	}
}

//user control function for the mobile lift
void mobileControls2()
{
	if(vexRT[Btn8RXmtr2] == 1) //raises the mobile lift
	{
		motor[mobile] = 127;
	}
	else if(vexRT[Btn8DXmtr2] == 1 && SensorValue(rangeFinder) > mobileLow) //drops the lift to the mobile goal height
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
	else if(vexRT[Btn8LXmtr2] == 1) //drops the lift as low as possible
	{
		motor[mobile] = -127;
	}
	else if(vexRT[Btn8UXmtr2] == 1 && SensorValue(rangeFinder) < mobileHigh)
	{
		motor[mobile] = 127;
	}
	else
	{
		motor[mobile] = 0;
	}
}

//user control function for arms
void armsControls2()
{
	if(vexRT[Btn6UXmtr2] == 1) //swings arms out
	{
		motor[leftArm] = -127;
		motor[rightArm] = -127;
	}
	else if(vexRT[Btn6DXmtr2] == 1) //swings arms in
	{
		motor[leftArm] = 127;
		motor[rightArm] = 127;
	}
	else
	{
		motor[leftArm] = 0;
		motor[rightArm] = 0;
	}
}
