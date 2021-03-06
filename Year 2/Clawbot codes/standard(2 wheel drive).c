#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           rightMotor,    tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           armMotor2,     tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// this is for a robit with 2 wheel drive a calw and and 2 arm motors//

task main()
{
		while(vexRT[Btn8U]==1)
	{
			if(vexRT[Btn8U] == 1)
		//drive fword at half power for 5 sec
		motor[leftMotor] = 63;
		motor[rightMotor] = 63;
		wait(5000);
		//turn for 2.5 sec at half power
		motor[leftMotor] = 63;
		motor[rightMotor] = -63;
		wait(2500);
		//drive fword at half power for 5 sec
		motor[leftMotor] = 63;
		motor[rightMotor] = 63;
		wait(5000);
	}

	while(1 == 1)
	{
		//wheels
		motor[leftMotor]  = (vexRT[Ch2] + vexRT[Ch1])/2;
		motor[rightMotor] = (vexRT[Ch2] - vexRT[Ch1])/2;
		
		// arm right
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
		//arm left
		if(vexRT[Btn5U] == 1)       	//If 5U is pressed
		{
			motor[armMotor2] = 127;    	//raise arm.
		}
		else if(vexRT[Btn5D] == 1)  	//if 5D is pressed
		{
			motor[armMotor2] = -75;   	//lower arm.
		}
		else                      		//neither is pressed
		{
			motor[armMotor2] = 2;      	//hold arm
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
