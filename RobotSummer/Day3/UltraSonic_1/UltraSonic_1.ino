
#include <Svante.h>
int trig = DP1;
int echo = DP0;

void setup(){  
  //Initialize the serial communication
  Serial.begin(9600); 
}

void loop(){
  //Get the distance in cm
  int dis = getDistance(trig, echo);
  
  Serial.println(dis);
  delay(100);
}


int getDistance(int triggerPin, int echoPin){
  
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin,LOW);
  delayMicroseconds(2);  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerPin, LOW);
  
  pinMode(echo, INPUT);
  int duration = pulseIn(echoPin, HIGH, 11800);
  int distance = duration/29/2;
  
  return distance;
}
