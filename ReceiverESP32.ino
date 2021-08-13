// Sending/Receiving example

HardwareSerial Receiver(2); // Define a Serial port instance called 'Receiver' using serial port 2

#define Receiver_Txd_pin 13
#define Receiver_Rxd_pin 9

void setup()
{
  //Serial.begin(Baud Rate, Data Protocol, Txd pin, Rxd pin);
  Serial.begin(115200);                                                   // Define and start serial monitor
  Receiver.begin(115200, SERIAL_8N1, Receiver_Txd_pin, Receiver_Rxd_pin); // Define and start Receiver serial port
  pinMode(12, OUTPUT);
}

void loop()
  {
    while (Receiver.available())
      {                         // Wait for the Receiver to get the characters
          int value = Receiver.parseFloat(); // Display the Receivers characters
          Serial.println(value);               // Display the result on the serial monitor
        
            if (value==1)
              {
                Serial.println("H");
                digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)                             // Set an example value
              }
              else
              {
                Serial.println("L");
                digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
              }
          
      };
    //delay(50);
  }
