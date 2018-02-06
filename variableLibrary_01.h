//all variable declarations and autonomous functions
const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;
int auton = 4;
int enter = 0;
int skip = 0;
int lcd = 0;
int mobileLow = 48;
int mobileHigh = 109;
int mobileMax = 135;
int rangeFinderValue, potValue;
int backLeftSpeed, frontRightSpeed, leftLiftSpeed, rightLiftSpeed, leftArmSpeed, rightArmSpeed;
int armTicks, flTicks, liftTicks, mobileTicks, gyroTicks;
bool finished = false;
bool partner = false;
bool driverSkills = false;
string mainBattery, backupBattery;

//multidimensional array that stores values for the lift and arms respectively (rows) based on how many cones are already stacked (columns)
int stackValues[2][5] = {
	{3150, 3200, 3340, 3260, 3260},	//lift values
	{10, 23, 19, 57, 57}	//arm values
};
int stackHeight = 0;
