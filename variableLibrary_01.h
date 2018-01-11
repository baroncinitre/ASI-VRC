//all variable declarations and autonomous functions
const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;
int auton = 0;
int enter = 0;
int skip = 0;
int lcd = 0;
int mobileLow = 50;
int mobileHigh = 109;
int mobileMax = 135;
int rangeFinderValue, potValue;
int backLeftSpeed, frontRightSpeed, leftLiftSpeed, rightLiftSpeed, leftArmSpeed, rightArmSpeed;
int armTicks, mobileTicks, liftTicks, brTicks, flTicks, gyroTicks;
int autonTime;
bool finished = false;
bool slowdown = false;
bool drivetrainSlowdown = false;
bool partner = false;
bool driverSkills = false;
float tpd = 6.2222; //number of ticks per degree of rotation
float dtSlowdownFactor = 0.5;
string mainBattery, backupBattery;

//multidimensional array that stores values for the lift and arms respectively (rows) based on how many cones are already stacked (columns)
int stackValues[2][6] = {
	{-71, -67, -35, -46, -46, -46},	//lift values
	{-8, -11, -1, 17, 20, 0}	//arm values
};
int stackHeight = 0;
