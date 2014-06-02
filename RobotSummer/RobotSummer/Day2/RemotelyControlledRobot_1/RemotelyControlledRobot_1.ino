/*
  RemotelyControlledRobot_1
 
 This example shows how to use the Tinkerkit remote with an IR receiver 
 (It's recommended to use a Tsop2238). The IR receiver is connected to 
 DP0 on the Svante robot. The robot goes forward, backwards, and turns 
 left or right according to the buttons you press.
 
 This is an example from the Svante robot summer camp.
 zgz.verkstad.cc 
 (c) 2014 Arduino Verkstad
 */

#include <IRremote.h>
#include <IRremoteTools.h>
#include <Svante.h>
#include <EEPROM.h>

const int RECV_PIN = DP0;            //Define the receiver pin
const unsigned long TIMER_MAX=200;   //Timeout for when no repeat frame is received

boolean pressed=false;
unsigned long IRtimer=0;	     //Timer for keep pressed key

int maxSpeed = 100;
int turnSpeed = 70;

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
    break;
  case REMOTE_PLUS:
  
    Serial.println("plus");
    break;
  }

}


