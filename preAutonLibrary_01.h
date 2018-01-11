void preAutonTasks()
{
	//resets the gyroscope
	resetEncoders();
	SensorType[gyro] = sensorNone;
	SensorType[gyro] = sensorGyro;
	SensorType[armEncoder] = sensorNone;
	SensorType[armEncoder] = sensorQuadEncoder;
	SensorType[liftEncoder] = sensorNone;
	SensorType[liftEncoder] = sensorQuadEncoder;
	nMotorEncoder[leftArm] = 0;
	wait1Msec(1000);
	SensorValue[gyro] = 0;
	SensorValue[armEncoder] = 0;
	SensorValue[liftEncoder] = 0;

	//while loop to enable lcd input
	while(enter != 1 && skip != 1)
	{
		switch(lcd)
		{
		case 0:
			//blue or red selection
			displayLCDCenteredString(0, "Left = Blue");
			displayLCDCenteredString(1, "Right = Red");
			waitForPress();
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				lcd = 1;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				lcd = 5;
			}
			else if(nLCDButtons == centerButton)
			{
				waitForRelease();
				driverSkills = true;
			}
			break;
		case 1:
			//blue side cones or mobile selection
			displayLCDCenteredString(0, "Left = Cones");
			displayLCDCenteredString(1, "Right = Mobile");
			waitForPress();
			if(nLCDButtons == leftButton)
			{
				//opens selection for blue side cones
				waitForRelease();
				lcd = 2;
			}
			else if(nLCDButtons == rightButton)
			{
				//opens selection for blue side mobile goal
				waitForRelease();
				lcd = 4;
			}
			break;
		case 2:
			//blue side cones selection
			displayLCDCenteredString(0, "Left: 1 Cone");
			displayLCDCenteredString(1, "Right: 2 Cones");
			waitForPress();
			if(nLCDButtons == leftButton)
			{
				//opens selection for blue side, one cone, left or right
				waitForRelease();
				lcd = 3;
			}
			else if(nLCDButtons == rightButton)
			{
				//sets autonomous to blue side two cones
				waitForRelease();
				auton = 2;
				enter = 1;
			}
			break;
		case 3:
			//blue side, one cone, left or right selection
			displayLCDCenteredString(0, "Move left");
			displayLCDCenteredString(1, "Move right");
			waitForPress();
			if(nLCDButtons == leftButton)
			{
				//sets autonomous to one cone, move left
				waitForRelease();
				auton = 0;
				enter = 1;
			}
			else if(nLCDButtons == rightButton)
			{
				//sets autonomous to one cone, move right
				waitForRelease();
				auton = 1;
				enter = 1;
			}
			break;
		case 4:
			//blue side, mobile goal, 10 or 20 points
			displayLCDCenteredString(0, "Left: 10");
			displayLCDCenteredString(1, "Right: 20");
			waitForPress();
			if(nLCDButtons == leftButton)
			{
				//sets autonomous to blue side ten point mobile goal drop
				waitForRelease();
				auton = 7;
				enter = 1;
			}
			else if(nLCDButtons == rightButton)
			{
				//sets autonomous to blue side twenty point mobile goal drop
				waitForRelease();
				auton = 4;
				enter = 1;
			}
			break;
		case 5:
			//red side mobile goal or cones selection
			displayLCDCenteredString(0, "Left: cones");
			displayLCDCenteredString(1, "Right: mobile");
			waitForPress();
			if(nLCDButtons == leftButton)
			{
				//opens selection for red side cones
				waitForRelease();
				lcd = 6;
			}
			else if(nLCDButtons == rightButton)
			{
				//opens selection for red side mobile goal
				waitForRelease();
				lcd = 8;
			}
			break;
		case 6:
			//red side cones selection
			displayLCDCenteredString(0, "Left: 1 cone");
			displayLCDCenteredString(1, "Right: 2 cones");
			waitForPress();
			if(nLCDButtons == leftButton)
			{
				//opens selection for red side one cone
				waitForRelease();
				lcd = 7;
			}
			else if(nLCDButtons == rightButton)
			{
				//sets autonomous to red side two cones
				waitForRelease();
				auton = 3;
			}
			break;
		case 7:
			//red side one cone selection
			displayLCDCenteredString(0, "Move left");
			displayLCDCenteredString(1, "Move right");
			waitForPress();
			if(nLCDButtons == leftButton)
			{
				//sets autonomout to red side, one cone, move left
				waitForRelease();
				auton = 0;
				enter = 1;
			}
			else if(nLCDButtons == rightButton)
			{
				//sets autonomous to red side, one cone, move right
				waitForRelease();
				auton = 1;
				enter = 1;
			}
			break;
		case 8:
			//red side mobile goal selection
			displayLCDCenteredString(0, "Left: 10");
			displayLCDCenteredString(1, "Right: 20");
			waitForPress();
			if(nLCDButtons == leftButton)
			{
				//sets autonomous to red side 10 point
				waitForRelease();
				//auton = ;
				enter = 1;
			}
			else if(nLCDButtons == rightButton)
			{
				//sets autonomous to red side 20 point
				waitForRelease();
				auton = 5;
				enter = 1;
			}
			break;
		}
	}
}
