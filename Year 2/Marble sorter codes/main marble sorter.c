#pragma config(Sensor, in1,    linefollow,     sensorLineFollower)
#pragma config(Sensor, dgtl1,  green,          sensorLEDtoVCC)
#pragma config(Sensor, dgtl7,  yellow,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, red,            sensorLEDtoVCC)
#pragma config(Motor,  port1,           flashlight,    tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port2,           turntable,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port3,           feedmotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           stopper,       tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while (1 == 1)
	{
		turnFlashlightOn(flashlight, 127);
		wait(5);

		if (SensorValue[linefollow] > 2000 )
		{
			turnLEDOn(green);
			setServo(turntable, 75);
			wait1Msec(700);
			turnLEDOff(green);
		}
		else
		{
			turnLEDOn(red);
			setServo(turntable, -75);
			wait1Msec(700);
			turnLEDOff(red);
		}

		wait1Msec(100);
		turnFlashlightOff(flashlight);

		wait1Msec(100);
		startMotor(stopper, 127);
		wait(4);
		startMotor(stopper, -127);
		wait1Msec(100);

		wait1Msec(100);
		setServo(turntable, 0);
		wait1Msec(150);

		turnLEDOn(yellow);
		startMotor(feedmotor, 60);
		wait1Msec(890);
		stopMotor(feedmotor);
		turnLEDOff(yellow);
	}
}
