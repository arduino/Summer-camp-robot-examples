#include <Svante.h>
#include <IRremote.h>

int recieverPin = DP0;

IRrecv reciever(recieverPin);

decode_results results;

//Timeout variables
long currentMillis, previousMillis = 0;
long timeOut = 150;
boolean checkTimer = false;

void setup(){
  Serial.begin(9600);
  reciever.enableIRIn(); // Start the receiver
}

void loop() {
  
  if (reciever.decode(&results)) {
    if(results.value == 0xE4B3B847) Serial.println("+");
    else if(results.value == 0xE4B3F00F) Serial.println("-");
    else if(results.value == 0xE4B308F7) Serial.println("UP");
    else if(results.value == 0xE4B3D827) Serial.println("DOWN");
    else if(results.value == 0xE4B350AF) Serial.println("LEFT");
    else if(results.value == 0xE4B3F807) Serial.println("RIGHT");
    else if(results.value == 0xE4B310EF) Serial.println("MIDDLE");
    
    reciever.resume(); // Receive the next value
    
    //reset timer
    previousMillis = millis();
    checkTimer = true;
  }
  else{
    if(millis()-previousMillis > timeOut && checkTimer){
      Serial.println("RELEASED"); 
      checkTimer = false;
    }
  }
  
}
