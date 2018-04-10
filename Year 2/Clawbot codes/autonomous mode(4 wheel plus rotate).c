#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rotate,        tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port5,           rotate2,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           leftBack,      tmotorNone, openLoop)
#pragma config(Motor,  port9,           rightBack,     tmotorNone, openLoop)

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"

void pre_auton()
{
	bStopTasksBetweenModes = true;
}

//Autonomous

task autonomous()
{
startMotor(leftMotor, 127);
startMotor(rightMotor, 127);
wait(5);
stopMotor(rightMotor);
stopMotor(leftMotor);
}

//User Control

task usercontrol()
{

	while (true)
	{
		//front wheels
		motor[leftMotor]  = (vexRT[Ch2] + vexRT[Ch1])/2;
		motor[rightMotor] = (vexRT[Ch2] - vexRT[Ch1])/2;
		//back wheels
		motor[leftBack]  = (vexRT[Ch2] + vexRT[Ch1])/2;
		motor[rightBack] = (vexRT[Ch2] - vexRT[Ch1])/2;

		//rotate
		motor[rotate]  = (vexRT[Ch3] + vexRT[Ch4])/2;
		motor[rotate] = (vexRT[Ch4] - vexRT[Ch4])/2;
		//rotate2
		motor[rotate2]  = (vexRT[Ch3] + vexRT[Ch4])/2;
		motor[rotate2] = (vexRT[Ch4] - vexRT[Ch4])/2;
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
