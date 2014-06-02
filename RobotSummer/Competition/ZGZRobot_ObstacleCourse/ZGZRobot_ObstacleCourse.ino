#include <Svante.h>
#include <IRremote.h>
#include <IRremoteTools.h>
#include <EEPROM.h>
#include <Servo.h>

Servo claw;

const int SERVO_PIN = DP4;
const int RECV_PIN = DP0;

const int SERVO_MAX = 170;
const int SERVO_SPEED = 10;
long signalTimer;

#define IDLE_MODE 0
#define MOVE_MODE 1
#define SERVO_MODE 2

int currentMode=IDLE_MODE;

int currentSDir;//current servo direction
int currentSPos;//current servo position

const unsigned long TIME_OUT=200;
const int ROBOT_SPEED=100;

void setup()
{
  robot.begin();
  Serial.begin(9600);
  claw.attach(SERVO_PIN);
  beginIRremote(RECV_PIN); // Start the receiver
  currentSDir=0;
  currentSPos=0;
}

void loop() {
  getCommand();
  
  checkTimer();
}


void getCommand(){
  if (IRreceived()) {
    unsigned long command=getIRresult();
    //Serial.println(command,HEX);

    if(command!=REMOTE_CONTINUE){
      switch(command){
        case REMOTE_UP:
          moveRobot(ROBOT_SPEED,ROBOT_SPEED);
          break;
        case REMOTE_DOWN:
          moveRobot(-ROBOT_SPEED,-ROBOT_SPEED);
          break;
        case REMOTE_LEFT:
          moveRobot(0,ROBOT_SPEED);
          break;
        case REMOTE_RIGHT:
          moveRobot(ROBOT_SPEED,0);
          break;
        case REMOTE_PLUS:
          moveServo(SERVO_SPEED);
          break;
        case REMOTE_MINUS:
          moveServo(-SERVO_SPEED);
          break;
      }
    }else{
      repeat();
    }
    signalTimer=millis();
    resumeIRremote(); // Receive the next value
  }
}
void moveRobot(int speedL, int speedR){
  stopAll();
  currentMode=MOVE_MODE;
  robot.go(speedL,speedR);
}
void moveServo(int sDirection){
  
  if(sDirection!=0){
    stopAll();
    currentMode=SERVO_MODE;
    currentSDir=sDirection;
  }
  currentSPos+=currentSDir;
  if(currentSPos<0)currentSPos=0;
  else if(currentSPos>SERVO_MAX)currentSPos=SERVO_MAX;
  
  Serial.print("Servo move ");
  Serial.println(currentSPos);
  
  claw.write(currentSPos);
//move servo here
}
void repeat(){
  switch(currentMode){
    case MOVE_MODE:
      break;
    case SERVO_MODE:
      moveServo(0);
      break;
  }
}
void stopAll(){
  //stop all current actions
  robot.stop();
}

void checkTimer(){
  if(millis()-signalTimer>=TIME_OUT){
    stopAll();
    currentMode=IDLE_MODE;
  }
}
