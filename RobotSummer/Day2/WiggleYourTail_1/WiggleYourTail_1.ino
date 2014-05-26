
#include <Svante.h>
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
int servoPin = DP8;             
    
void setup() { 
  myservo.attach(servoPin);
} 
 
 
void loop() { 
  myservo.write(45);
  delay(200);
  myservo.write(135);  
  delay(200);  
} 
