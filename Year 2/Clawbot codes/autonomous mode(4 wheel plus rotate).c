#pragma config(Sensor, dgtl1,  armup,          sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  armstill,       sensorLEDtoVCC)
#pragma config(Sensor, dgtl3,  armdown,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl6,  clawopen,       sensorLEDtoVCC)
#pragma config(Sensor, dgtl7,  clawstill,      sensorLEDtoVCC)
#pragma config(Sensor, dgtl8,  clawclose,      sensorLEDtoVCC)
#pragma config(Sensor, dgtl10, rotateleft,     sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, rotateno,       sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, rotateright,    sensorLEDtoVCC)
#pragma config(Motor,  port2,           fRightMotor,   tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port4,           rotate,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           leftMotor,     tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port6,           armMotor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           fLeftMotor,    tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port8,           clawMotor,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex platform  
#pragma platform(VEX)  
// Select Download method as "competition"  
#pragma competitionControl(Competition)  
//Main competition background code...do not modify!  
#include "Vex_Competition_Includes.c"  
void pre_auton()  
{  
	bStopTasksBetweenModes = true;
}  

task autonomous()  
{  
	AutonomousCodePlaceholderForTesting();
}  

task usercontrol()  
{  
	while (true)
	{
		//Tank Control
		//back control
		motor[leftMotor]  = vexRT[Ch3];   // Left Joystick Y value
		motor[rightMotor] = vexRT[Ch2];   // Right Joystick Y value
		//front control
		motor[fLeftMotor]  = vexRT[Ch3];   // Left Joystick Y value
		motor[fRightMotor] = vexRT[Ch2];   // Right Joystick Y value
		//rotate
		if(vexRT[Btn7L] == 1)       //If 7L is pressed
		{
			motor[rotate] = -100;    //rotate
			turnLEDOn(rotateleft);
		}
		else if(vexRT[Btn7R] == 1)  //if 7R is pressed
		{
			motor[rotate] = 100;   //rotate
			turnLEDOn(rotateright);
		}
		else                      //neither is pressed
		{
			motor[rotate] = 0;      //do nothing
			turnLEDOn(rotateno);
		}
		// arm
		if(vexRT[Btn7U] == 1)       //If 7U is pressed
		{
			motor[armMotor] = 100;    //raise arm.
			turnLEDOn(armup);
		}
		else if(vexRT[Btn7D] == 1)  //if 7D is pressed
		{
			motor[armMotor] = -100;   //lower arm
			turnLEDOn(armdown);
		}
		else                      //neither is pressed
		{
			motor[armMotor] = 17;      //hold arm
			turnLEDOn(armstill);
		}
		// claw
		if(vexRT[Btn6U] == 1)       //If 6U is pressed
		{
			motor[clawMotor] = 127;  //close claw
			turnLEDOn(clawclose);
		}
		else if(vexRT[Btn6D] == 1)  //if 6D is pressed
		{
			motor[clawMotor] = -127; //open claw
			turnLEDOn(clawopen);
		}
		else                      //if neather is pressed
		{
			motor[clawMotor] = 0;    //do nothing with claw
			turnLEDOn(clawstill);
		}
	}
}  
