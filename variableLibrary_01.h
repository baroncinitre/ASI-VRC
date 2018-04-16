//all variable declarations
const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;
int auton = 4;
int enter = 0;
int skip = 0;
int lcd = 0;
int mobileLow = 50;
int mobileCarry = 114;
int mobileHigh = 119;
int mobileMax = 135;
int mobileStack = 85;
int rangeFinderValue, potValue;
int backLeftSpeed, frontRightSpeed, leftLiftSpeed, rightLiftSpeed, leftArmSpeed, rightArmSpeed;
int armTicks, mobileTicks, liftTicks, blTicks, gyroTicks;
int autonTime1;
bool finished = false;
bool skillsOn = true;
bool cone = false;
//bool breakAuton = false;
//bool autonBroken = false;

//multidimensional array that stores values for the lift and arms respectively (rows) based on how many cones are already stacked (columns)
int stackValues[3][5] = {
	{2500, 3300, 3500, 3600, 3840},	//raise lift values
	{290, 1300, 1600, 1850, 1310},	//arm values
	{2685, 2800, 3100, 3280, 3400} //drop lift values
};
int stackHeight = 0;

int grabValues[3] = {3000, 1880, 2400};
