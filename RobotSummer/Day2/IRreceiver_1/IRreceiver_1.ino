#include <Svante.h>
#include <IRremote.h>

int receiverPin = DP0;

IRrecv receiver(receiverPin);

decode_results results;

void setup()
{
  Serial.begin(9600); //Starts serail communication
  receiver.enableIRIn(); // Start the receiver
}

void loop() {
  if (receiver.decode(&results)) {
    Serial.println(results.value, HEX); //Prints the readings to the serial monitor
    receiver.resume(); // Receive the next value
  }
}
