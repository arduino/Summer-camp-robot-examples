
#include <Svante.h>
#include <Servo.h>


int trigR = DP10;
int echoR =DP9;
int trigL = DP1;
int echoL =DP0;

int threshold = 50;

Servo tail;
int servoPin = DP4;

void setup(){  
  //Initialize the serial communication
  Serial.begin(9600); 
  robot.begin();
  tail.attach(servoPin);
}

void loop(){
  //Get the distance in cm
  int disR = getDistance(trigR, echoR);
  int disL = getDistance(trigL, echoL);
  
  if(disL<threshold && disR<threshold){
    Serial.println("In front!");
    robot.go(100, 100);
    wiggleTail();
  }
  else if(disL<threshold){
    Serial.println("To the left!");
    robot.go(10, 100);
    wiggleTail();
  }
  else if(disR<threshold) {
    Serial.println("To the right!");
    robot.go(100, 10);  
    wiggleTail();
  }
  else {
    Serial.println("Nothing there!");
    robot.stop();
  }
}

void wiggleTail(){
    tail.write(45); 
    delay(100);
    tail.write(135);
    delay(100);
}


int getDistance(int triggerPin, int echoPin){
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin,LOW);
  delayMicroseconds(2);  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerPin, LOW);
  
  pinMode(echoPin, INPUT);
  int duration = pulseIn(echoPin, HIGH, 11800);
  int distance = constrain(duration/29/2, 0, 200);
  if(distance==0)distance=200;

  return distance;
}
