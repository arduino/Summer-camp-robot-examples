/*
*	Industry Robot
*	Make a robot that helps manufacturing in factories!
*	The robot follows a black line, across a few work stations.
*	Whenever it reaches a workstation(end line), it performs a 
*	Serials of logo movements to deliver raw materials into the
*	machine. 
*	You need to fine tune the logo movement so it both pushes 
*	the object to the right position, and returns to the track
*	afterwards. You can also fine tune the line follower 
*	parameters so it runs faster along the track.
*
*	This is an example from the Svante robot summer camp.
*	zgz.verkstad.cc 
*	(c) 2014 Arduino Verkstad
*
*/

#include <Svante.h>
#include <EEPROM.h>
void setup(){
	robot.begin();
	delay(1000);
	robot.lineFollowCalibrate();
	robot.lineFollowConfig(40,8,10,30);//KP, KD, integration time, max speed
	delay(1000);

}
void loop(){
	robot.startLineFollow();
	//Run the logo sequence here
	robot.go(50,50);	//move forward to engage the target
	delay(200);
        robot.stop();
        delay(500);
        
	robot.go(50,-50);	//turn around with the target grabbed
	delay(100);
        robot.stop();
        delay(500);

	robot.go(50,50);	//push the target out
	delay(200);
        robot.stop();
        delay(500);

	robot.go(-50,-50);	//the same way back
	delay(100);
        robot.stop();
        delay(500);

	robot.go(-50,50);	//turn around, facing the track
	delay(100);
        robot.stop();
        delay(500);

	robot.go(50,50);	//engage the track
	delay(200);
        robot.stop();
        delay(500);

}