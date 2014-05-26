
#include <Svante.h>

int trigR = DP10;
int echoR =DP9;
int trigL = DP1;
int echoL =DP0;

void setup(){  
  //Initialize the serial communication
  Serial.begin(9600); 
}

void loop(){
  //Get the distance in cm
  int disR = getDistance(trigR, echoR);
  int disL = getDistance(trigL, echoL);
  
  Serial.print("Left distance: ");
  Serial.print(disL);
  Serial.print("  Right distance: ");
  Serial.println(disR);
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
