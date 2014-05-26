#include <Svante.h>
#include <IRremote.h>

const long PLUS = 0xE4B3B847;
const long MINUS = 0xE4B3F00F;
const long UP = 0xE4B308F7;
const long DOWN = 0xE4B3D827;
const long LEFT = 0xE4B350AF;
const long RIGHT = 0xE4B3F807;
const long MIDDLE = 0xE4B310EF;

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
  robot.begin();
}

void loop() {
  if (reciever.decode(&results)) {

    //Decide what to do
    if(results.value == PLUS){ 
      //Do nothing
    }
    else if(results.value == MINUS){
      //Do nothing
    }
    else if(results.value == UP){ 
      robot.go(100, 100); //Move forward
    }
    else if(results.value == DOWN){ 
      robot.go(-100, -100); //Move backwards
    }
    else if(results.value == LEFT){ 
      robot.go(-100, 100); //Spin left
    }
    else if(results.value == RIGHT){ 
      robot.go(100, -100); //Spin Right
    }
    else if(results.value == MIDDLE){ 
      //Do nothing
    }

    reciever.resume(); // Receive the next value
    
    //reset timer
    previousMillis = millis();
    checkTimer = true;
  }
  else{
    //If all buttons are releasede, stop the robot
    if(millis()-previousMillis > timeOut && checkTimer){
      robot.stop();
      checkTimer = false;
    }     
  }
}
