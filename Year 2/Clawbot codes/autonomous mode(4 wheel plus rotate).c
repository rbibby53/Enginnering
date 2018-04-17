#pragma config(Sensor, dgtl1,  Encoder,        sensorQuadEncoder)
#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port4,           rotate,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           clawMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           armMotor,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           armMotor2,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"

void pre_auton()
{
	bStopTasksBetweenModes = false;
}

//Autonomous

task autonomous()
{
int repeatThisNumberOfTimes = 1; //this is how many times to repeat

for (int i = 0; i < repeatThisNumberOfTimes; i++){
SensorValue[Encoder] = 0;   //Clear the left encoder value


	//While the encoders have spun less than 3 rotations...
	while(SensorValue[Encoder] < 1080)
	{
		//Move Forward
		motor[rightMotor] = 63;
		motor[leftMotor] = 63;
	}

	//Stop for half a second
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
	wait1Msec(500);

	SensorValue[Encoder] = 0;   //Clear the left encoder value

	//While the right encoder has spun less than 1 rotation...
	while(SensorValue[Encoder] < 360)
	{
		//Turn Left
		motor[rightMotor] = -63;
		motor[leftMotor] = 63;
		wait(5);
		SensorValue[Encoder] = 360;
	}
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
}
}

//User Control

task usercontrol()
{

	while (true)
	{
		//front wheels
		motor[leftMotor]  = (vexRT[Ch2] + vexRT[Ch1])/2;
		motor[rightMotor] = (vexRT[Ch2] - vexRT[Ch1])/2;

		//rotate fine
		motor[rotate]  = (vexRT[Ch4] + vexRT[Ch4])/2;
		motor[rotate] = (vexRT[Ch4] - vexRT[Ch4])/2;

		//rotate fast
		if(vexRT[Btn7L] == 1)       	//If 5U is pressed
		{
			motor[rotate] = -100;    	//rotate
		}
		else if(vexRT[Btn7R] == 1)  	//if 5D is pressed
		{
			motor[rotate] = 100;   	//rotate
		}
		else                      		//neither is pressed
		{
			motor[rotate] = 0;      	//do nothing
		}
		
		//bumper
		// arm
		if(vexRT[Btn5U] == 1)       	//If 5U is pressed
		{
			motor[armMotor] = 127;    	//raise arm.
		}
		else if(vexRT[Btn5D] == 1)  	//if 5D is pressed
		{
			motor[armMotor] = -75;   	//lower arm
		}
		else                      		//neither is pressed
		{
			motor[armMotor] = 10;      	//hold arm
		}
		// arm2
		if(vexRT[Btn5U] == 1)       	//If 5U is pressed
		{
			motor[armMotor2] = 127;    	//raise arm.
		}
		else if(vexRT[Btn5D] == 1)  	//if 5D is pressed
		{
			motor[armMotor2] = -75;   	//lower arm
		}
		else                      		//neither is pressed
		{
			motor[armMotor2] = 10;      	//hold arm
		}
		//button
			// arm
		if(vexRT[Btn7U] == 1)       	//If 5U is pressed
		{
			motor[armMotor] = 60;    	//raise arm.
		}
		else if(vexRT[Btn7D] == 1)  	//if 5D is pressed
		{
			motor[armMotor] = -60;   	//lower arm
		}
		else                      		//neither is pressed
		{
			motor[armMotor] = 10;      	//hold arm
		}
		// arm2
		if(vexRT[Btn5U] == 1)       	//If 5U is pressed
		{
			motor[armMotor2] = 63;    	//raise arm.
		}
		else if(vexRT[Btn5D] == 1)  	//if 5D is pressed
		{
			motor[armMotor2] = -63;   	//lower arm
		}
		else                      		//neither is pressed
		{
			motor[armMotor2] = 10;      	//hold arm
		}
		// claw
		if(vexRT[Btn6U] == 1)       	//If 6U is pressed
		{
			motor[clawMotor] = 127;  		//close claw
		}
		else if(vexRT[Btn6D] == 1)  	//if 6D is pressed
		{
			motor[clawMotor] = -127; 		//open claw
		}
		else                      		//if neather is pressed
		{
			motor[clawMotor] = 0;    		//do nothing with claw
		}
	}
}
