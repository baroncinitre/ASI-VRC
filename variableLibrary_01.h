//all variable declarations and autonomous functions
const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;
int auton = 4;
int enter = 0;
int skip = 0;
int lcd = 0;
int mobileLow = 50;
int mobileHigh = 97;
int mobileMax = 135;
int rangeFinderValue, potValue;
int backLeftSpeed, frontRightSpeed, leftLiftSpeed, rightLiftSpeed, leftArmSpeed, rightArmSpeed;
int armTicks, mobileTicks, liftTicks, flTicks, gyroTicks;
int autonTime;
bool finished = false;
bool lifting = false;
bool skillsOn = true;

//multidimensional array that stores values for the lift and arms respectively (rows) based on how many cones are already stacked (columns)
int stackValues[3][5] = {
	{3300, 3300, 3500, 3600, 3840},	//raise lift values
	{1420, 1300, 1600, 1850, 1310},	//arm values
	{2685, 2800, 3100, 3280, 3400} //drop lift values
};
int stackHeight = 0;
