#include <IRremote.h>
int RECV_PIN = 9;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver

  Serial.println("Ready to receive...");
}

void loop()
{
  if (irrecv.decode(&results))
    {
     Serial.println(results.value);
     irrecv.resume(); // Receive the next value
    }
}
