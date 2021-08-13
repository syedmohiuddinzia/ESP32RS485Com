// Sending/Receiving example

HardwareSerial Sender(1);   // Define a Serial port instance called 'Sender' using serial port 1

#define Sender_Txd_pin 13
#define Sender_Rxd_pin 9
int count= 0;

void setup() {
  //Serial.begin(Baud Rate, Data Protocol, Txd pin, Rxd pin);
  Serial.begin(115200);                                             // Define and start serial monitor
  Sender.begin(115200, SERIAL_8N1, Sender_Txd_pin, Sender_Rxd_pin); // Define and start Sender serial port
  pinMode(12, OUTPUT);
}

void loop() {
  if ((count%2)==0)
  {
    Serial.println("H");
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)                             // Set an example value
    //float high = 1.0;                               // Set an example value
    Sender.print(1);                                // Send it to Sender serial port
  }
  else
  {
    Serial.println("L");
    digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
    //float low = 0.0;                               // Set an example value
    Sender.print(0);                                // Send it to Sender serial port
  }
  delay(2000);
  Serial.println();
  count++;
}
