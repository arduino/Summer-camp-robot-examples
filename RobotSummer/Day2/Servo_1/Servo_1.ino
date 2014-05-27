
#include <Svante.h>
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
int servoPin = DP4;  
    
void setup() { 
  myservo.attach(servoPin);  // attaches the servo on pin DP8 to the servo object 
} 
 
 
void loop() { 
  myservo.write(180);              // tell servo to go to position in variable 'pos' 
  delay(1000);
  myservo.write(90);  
  delay(1000);
  myservo.write(0);  
  delay(1000);  
} 
