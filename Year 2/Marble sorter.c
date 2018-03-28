#pragma config(Sensor, in1,    linefollow,     sensorLineFollower)
#pragma config(Sensor, dgtl1,  green,          sensorLEDtoVCC)
#pragma config(Sensor, dgtl7,  yellow,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, red,            sensorLEDtoVCC)
#pragma config(Motor,  port1,           flashlight,    tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port2,           turntable,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port3,           feedmotor,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port4,           stopper,       tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while (true)
	{
		turnFlashlightOn(flashlight, 127);
		wait1Msec(700);

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

		wait1Msec(500);
		turnFlashlightOff(flashlight);

		wait1Msec(500);
		setServo(stopper, 127);
		wait(1);
		setServo(stopper, -127);
		wait1Msec(200);
		wait(3);

		setServo(turntable, 0);
		wait1Msec(200);

		setServo(feedmotor,-127);
		turnLEDOn(yellow);
		wait1Msec(750);
		setServo(feedmotor,127);
		turnLEDOff(yellow);
	}
}
