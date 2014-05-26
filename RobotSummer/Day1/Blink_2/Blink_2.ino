#include <Svante.h>
 
void setup() {                
  pinMode(DP0, OUTPUT);     
 }
 
void loop() {
  digitalWrite(DP0, HIGH);   
  delay(1000);               
  digitalWrite(DP0, LOW);    
  delay(1000);               
}
