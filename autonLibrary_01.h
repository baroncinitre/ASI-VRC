void preAutonTasks();
void waitForPress();
void waitForRelease();
void cut();
void resetEncoders();
void returnValues();

//waits until an LCD button or controller button is pressed
void waitForPress()
{
	while(nLCDButtons == 0)
	{
		if(vexRT[Btn7L] == 1)
		{
			auton = 0;
			skip = 1;
			break;
		}
		if(vexRT[Btn7R] == 1)
		{
			auton = 1;
			skip = 1;
			break;
		}
		if(vexRT[Btn7U] == 1)
		{
			auton = 2;
			skip = 1;
			break;
		}
		if(vexRT[Btn7D] == 1)
		{
			auton = 3;
			skip = 1;
			break;
		}
	}
}

//waits until the LCD button is released
void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}

//turns off the drivetrain motors
void cut()
{
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backLeft] = 0;
	motor[backRight] = 0;
}

//resets the motor encoders
void resetEncoders()
{
	nMotorEncoder[frontLeft] = 0;
	nMotorEncoder[frontRight] = 0;
	nMotorEncoder[backLeft] = 0;
	nMotorEncoder[backRight] = 0;
	SensorValue(liftEncoder) = 0;
	SensorValue(armPot) = 0;
	SensorValue(frontLeft) = 0;
	SensorValue(gyro) = 0;
}

//rotates the robot
void turn(float degree, int speed)
{
	SensorValue(gyro) = 0;
	float degree10 = degree * 10;
	while(abs(SensorValue(gyro)) < degree10)
	{
		motor[frontLeft] = speed;
		motor[frontRight] = speed;
		motor[backLeft] = speed;
		motor[backRight] = speed;
		gyroTicks = SensorValue(gyro);
	}
	SensorValue(gyro) = 0;
	cut();
}

//opens the claw
void openClaw()
{
	motor[intake] = -60;
	wait1Msec(650);
	motor[intake] = 0;
}

//brings the arms out
void arms(int ticks, int speed)
{
	while(SensorValue(armPot) < ticks)
	{
		motor[leftArm] = -speed;
		motor[rightArm] = -speed;
		armTicks = SensorValue(armPot);
	}
	motor[leftArm] = 0;
	motor[rightArm] = 0;
}

//brings the arms in
void armsIn(int ticks, int speed)
{
	while(SensorValue(armPot) > ticks)
	{
		motor[leftArm] = speed;
		motor[rightArm] = speed;
		armTicks = SensorValue(armPot);
	}
	motor[leftArm] = 0;
	motor[rightArm] = 0;
}

//raises the lift
void lift(int height, int speed)
{
	motor[leftLift] = speed;
	motor[rightLift] = speed;
	while(SensorValue(liftPot) < height)
	{
		returnValues();
	}
	motor[leftLift] = 0;
	motor[rightLift] = 0;
}

//drops the lift
void dropLift(int height, int speed)
{
	motor[leftLift] = -speed;
	motor[rightLift] = -speed;
	while(SensorValue(liftPot) > height)
	{
		returnValues();
	}
	motor[leftLift] = 0;
	motor[rightLift] = 0;
}

//drops the lift based off of time
void timeDrop(int time)
{
	motor[leftLift] = -127;
	motor[rightLift] = -127;
	wait1Msec(time);
	motor[leftLift] = 0;
	motor[rightLift] = 0;
}

//lifts up a mobile goal
void mobileLift(int height)
{
	if(height > SensorValue(rangeFinder))
	{
		while(height > SensorValue(rangeFinder))
		{
			if(SensorValue(rangeFinder) - height < 10)
			{
				motor[mobile] = 127;
			}
			else
			{
				motor[mobile] = 30;
			}
		}
	}
	else if(height < SensorValue(rangeFinder))
	{
		while(height < SensorValue(rangeFinder))
		{
			if(height - SensorValue(rangeFinder) < 10)
			{
				motor[mobile] = -127;
			}
			else
			{
				motor[mobile] = -30;
			}
		}
	}
	motor[mobile] = 0;
}

//holds the claw open as other functions are run
void holdOpen()
{
	motor[intake] = -35;
}

//closes the claw (inverse of holdOpen)
void closeClaw()
{
	motor[intake] = 0;
}

//slight brake to reduce drift from turning
void turnBrake(int speed)
{
	motor[frontRight] = speed;
	motor[frontLeft] = speed;
	motor[backRight] = speed;
	motor[backLeft] = speed;
	wait1Msec(100);
	SensorValue(gyro) = 0;
	cut();
}

//slight brake to reduce drift from moving forward/backward
void brake(int speed)
{
	motor[frontRight] = -speed;
	motor[frontLeft] = speed;
	motor[backRight] = -speed;
	motor[backLeft] = speed;
	wait1Msec(100);
	cut();
}

//moves the robot forward
void tickMove(float distance, int speed)
{
	SensorValue(flEncoder) = 0;

	motor[frontLeft] = speed;
	motor[frontRight] = -speed;
	motor[backLeft] = speed;
	motor[backRight] = -speed;

	SensorValue(gyro) = 0;

	while(abs(SensorValue(flEncoder)) <= distance)
	{
		//gyroscopic error correction
		if(SensorValue(gyro) > 0)
		{
			motor[frontRight] = -speed - abs(SensorValue(gyro));
			motor[backRight] = -speed - abs(SensorValue(gyro));
		}
		else if(SensorValue(gyro) < 0)
		{
			motor[frontLeft] = speed + abs(SensorValue(gyro));
			motor[backLeft] = speed + abs(SensorValue(gyro));
		}
		if(SensorValue(gyro) == 0)
		{
			motor[frontLeft] = speed;
			motor[frontRight] = -speed;
			motor[backLeft] = speed;
			motor[backRight] = -speed;
		}
		returnValues();
	}
	cut();
}

void move(float distance, int speed)
{
	resetEncoders();

	motor[frontLeft] = speed;
	motor[frontRight] = -speed;
	motor[backLeft] = speed;
	motor[backRight] = -speed;

	SensorValue(gyro) = 0;

	while(abs(nMotorEncoder[frontLeft]) <= distance)
	{
		//gyroscopic error correction
		if(SensorValue(gyro) > 0)
		{
			motor[frontRight] = -speed - abs(SensorValue(gyro));
			motor[backRight] = -speed - abs(SensorValue(gyro));
		}
		else if(SensorValue(gyro) < 0)
		{
			motor[frontLeft] = speed + abs(SensorValue(gyro));
			motor[backLeft] = speed + abs(SensorValue(gyro));
		}
		if(SensorValue(gyro) == 0)
		{
			motor[frontLeft] = speed;
			motor[frontRight] = -speed;
			motor[backLeft] = speed;
			motor[backRight] = -speed;
		}
		returnValues();
	}
	cut();
}

//backs the robot up
void backUp(int ticks, int speed)
{
	resetEncoders();
	motor[frontLeft] = -speed;
	motor[frontRight] = speed;
	motor[backLeft] = -speed;
	motor[backRight] = speed;
	while(abs(nMotorEncoder[frontLeft]) < ticks){}
	cut();
}

void tickBackUp(int ticks, int speed)
{
	SensorValue(flEncoder) = 0;
	motor[frontLeft] = -speed;
	motor[frontRight] = speed;
	motor[backLeft] = -speed;
	motor[backRight] = speed;
	while(abs(SensorValue(flEncoder)) < ticks){}
	cut();
}

//moves forward while raising the mobile goal lift
void moveLift(int distance, int speed, int height, int lSpeed)
{
	resetEncoders();
	motor[frontLeft] = speed;
	motor[frontRight] = -speed;
	motor[backLeft] = speed;
	motor[backRight] = -speed;
	while(abs(nMotorEncoder[frontLeft]) < distance)
	{
		if(SensorValue(rangeFinder) < height)
		{
			motor[mobile] = lSpeed;
		}
		else
		{
			motor[mobile] = 0;
		}
	}
	motor[mobile] = 0;
	cut();
}

void tickMoveLift(int distance, int speed, int height, int lSpeed)
{
	SensorValue(flEncoder) = 0;
	motor[frontLeft] = speed;
	motor[frontRight] = -speed;
	motor[backLeft] = speed;
	motor[backRight] = -speed;
	while(abs(SensorValue(flEncoder)) < distance)
	{
		if(SensorValue(rangeFinder) < height)
		{
			motor[mobile] = lSpeed;
		}
		else
		{
			motor[mobile] = 0;
		}
	}
	motor[mobile] = 0;
	cut();
}
