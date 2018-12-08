#pragma config(Motor,  port1,           armMotor,      tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           fRightMotor,   tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port5,           leftMotor,     tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port7,           fLeftMotor,    tmotorVex393_MC29, openLoop, driveLeft)

#pragma  platform(VEX)

#pragma competitionControl(Competition)

#include "Vex_Competition_Includes.c"
void pre_auton()
{
	bStopTasksBetweenModes = true;
}

task autonomous()
{
motor[fRightMotor] = 127;
motor[rightMotor] = 127;
motor[fLeftMotor] = 120;
motor[leftMotor] = 120;
wait(0.8);
motor[fRightMotor] = -127;
motor[rightMotor] = -127;
motor[fLeftMotor] = 120;
motor[leftMotor] = 120;
wait(1.85);
motor[fRightMotor] = 127;
motor[rightMotor] = 127;
motor[fLeftMotor] = 120;
motor[leftMotor] = 120;
wait(2.15);
motor[fRightMotor] = 0;
motor[rightMotor] = 0;
motor[fLeftMotor] = 0;
motor[leftMotor] = 0;
}

task usercontrol()
{
	while (true)
	{
		//Tank Control
		//back
		motor[leftMotor]  = vexRT[Ch3];   // Left Joystick Y value
		motor[rightMotor] = vexRT[Ch2];   // Right Joystick Y value
		//front
		motor[fLeftMotor]  = vexRT[Ch3];   // Left Joystick Y value
		motor[fRightMotor] = vexRT[Ch2];   // Right Joystick Y value

		if(vexRT[Btn6U] == 1)       //If 6U is pressed
		{
			motor[armMotor] = -127;    //raise arm.
		}
		else if(vexRT[Btn5U] == 1)  //if 5D is pressed
		{
			motor[armMotor] = 127;   //lower arm
		}
		else                      //neither is pressed
		{
			motor[armMotor] = 0;      //hold arm
		}
	}
}
