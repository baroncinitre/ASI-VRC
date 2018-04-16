//all user 1 control functions

//user control function for arcade control
void arcadeControls2()
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
	else if(vexRT[Btn8UXmtr2] == 1 && SensorValue(rangeFinder) < mobileCarry)
	{
		motor[mobile] = 127;
	}
	else if(vexRT[Btn7LXmtr2] == 1 && SensorValue(rangeFinder) < 99)//cams 20pnt button
	{
		motor[mobile] = 127;
	}
	else if(vexRT[Btn7RXmtr2] == 1 && SensorValue(rangeFinder) < mobileStack)
	{
		if(SensorValue(rangeFinder) - mobileStack > 10)
		{
			motor[mobile] = 127;
		}
		else
		{
			motor[mobile] = 60;
		}
	}
	else
	{
		motor[mobile] = 0;
	}
}

void user2()
{
	arcadeControls2();
	mobileControls2();
	returnValues();
}
