/*
  RobotClaw_2
 
 This example lets you control the Svante robot with a IR remote.
 (It's recommended to use a Tsop2238 IR receiver). The IR receiver 
 is connected to DP0. 
 
 A micro servo is connected to DP4 to open and close a claw. 
 The robot goes forward, backwards, turns left or right and opens or
 closes the claw according to the buttons you press.
 
 This is an example from the Svante robot summer camp.
 (c) 2014 Arduino LLC
 */


#include <Svante.h>
#include <EEPROM.h>
#include <IRremote.h>
#include <IRremoteTools.h>
#include <Servo.h>

const int RECV_PIN = DP0;            //Define the receiver pin
const unsigned long TIMER_MAX=200;   //Timeout for when no repeat frame is received

boolean pressed=false;
unsigned long IRtimer=0;	     //Timer for keep pressed key

int maxSpeed = 100;
int turnSpeed = 70;

Servo claw;                          //Claw variables
int servoPin = DP4;

void setup(){
  Serial.begin(9600);                //Initialize the serial communication
  beginIRremote(RECV_PIN);           //Initialze the remote
  IRtimer=millis();              
  
  robot.begin();  
}

void loop(){  
  //if a signal is received
  if(IRreceived()){   
    unsigned long command=getIRresult();  //decode the signal

    IRtimer=millis();    //Reset the timer
    pressed=true;        

    doStuff(command);    //Do you stuff here depending on the command
    resumeIRremote();    //resume the receiver
  }

  //If the button is released
  if(pressed && millis()-IRtimer>TIMER_MAX){ 
    pressed=false;
    Serial.println("released");
    robot.stop();                  //Stop robot when button is released
  }
}

void doStuff(unsigned long command){

  //Decide what to do depending on the received data
  //Here we print to the serial monitor what button is pressed.
  switch(command){
  case REMOTE_UP: 
    Serial.println("forward");
    robot.go(maxSpeed, maxSpeed);    //Move forward
    break;
    
  case REMOTE_DOWN:
    Serial.println("backwards");
    robot.go(-maxSpeed, -maxSpeed);  //Move backwards
    break;
    
  case REMOTE_LEFT:
    Serial.println("left");
    robot.go(0, turnSpeed);   //Turn left
    break;
    
  case REMOTE_RIGHT:
    Serial.println("right");
    robot.go(turnSpeed, 0);   //Turn right
    break;
    
  case REMOTE_MIDDLE:
    Serial.println("middle");
    break;
    
  case REMOTE_MINUS:
    Serial.println("minus");
    claw.attach(servoPin);
    claw.write(0);          //Open claw
    delay(200);
    claw.detach();
    stopServo();
    break;
    
  case REMOTE_PLUS:
    Serial.println("plus");
    claw.attach(servoPin); 
    claw.write(90);        //Close claw
    delay(500);
    claw.detach();
    stopServo();
    break;
  }

}


