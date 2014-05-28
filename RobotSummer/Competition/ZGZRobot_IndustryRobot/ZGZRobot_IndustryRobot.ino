#include <Svante.h>
#include <EEPROM.h>
void setup(){
	robot.begin();
	delay(1000);
	robot.lineFollowCalibrate();
	robot.lineFollowConfig(40,8,10,30);
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