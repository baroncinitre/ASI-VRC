void preAutonTasks()
{
	//resets the gyroscope
	resetEncoders();
	SensorType[gyro] = sensorNone;
	SensorType[gyro] = sensorGyro;
	SensorType[liftEncoder] = sensorNone;
	SensorType[liftEncoder] = sensorQuadEncoder;
	nMotorEncoder[leftArm] = 0;
	wait1Msec(1000);
	SensorValue[gyro] = 0;
	SensorValue[liftEncoder] = 0;

	//while loop to enable lcd input
	while(enter != 1 && skip != 1)
	{
		switch(lcd)
		{
		case 0:
			//4 task side selection
			displayLCDCenteredString(0, "4 task side");
			displayLCDCenteredString(1, "Center = Park");
			waitForPress();
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				auton = 2;
				enter = 1;
			}
			else if(nLCDButtons == centerButton)
			{
				waitForRelease();
				lcd = 1;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				auton = 3;
				enter = 1;
			}
			break;
		case 1:
			//Park side selection
			displayLCDCenteredString(0, "Park");
			displayLCDCenteredString(1, "Pick side");
			waitForPress();
			if(nLCDButtons == leftButton)
			{
				//opens selection for blue side cones
				waitForRelease();
				auton = 0;
				enter = 1;
			}
			else if(nLCDButtons == rightButton)
			{
				//opens selection for blue side mobile goal
				waitForRelease();
				auton = 1;
				enter = 1;
			}
			break;
		}
	}
}
