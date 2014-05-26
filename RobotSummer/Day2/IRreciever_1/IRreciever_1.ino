#include <Svante.h>
#include <IRremote.h>

int recieverPin = DP0;

IRrecv reciever(recieverPin);

decode_results results;

void setup()
{
  Serial.begin(9600); //Starts serail communication
  reciever.enableIRIn(); // Start the receiver
}

void loop() {
  if (reciever.decode(&results)) {
    Serial.println(results.value, HEX); //Prints the readings to the serial monitor
    reciever.resume(); // Receive the next value
  }
}
