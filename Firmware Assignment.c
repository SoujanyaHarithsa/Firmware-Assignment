const int tempPin = A0;    // LM35 temperature sensor connected to analog pin A0
const int ledPin = 13;     // Onboard LED connected to digital pin 13
const int Threshold = 30;  // set thershold value to 30 degree celsius
int LED_ARRAY1;            // declare a variable for blinking LED
void setup()
 {
  // Initialize serial communication
  Serial.begin(9600);

  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}
void loop() 
{
  // Read the voltage from the temperature sensor
  int sensorValue = analogRead(tempPin);

  // Convert the voltage to temperature in Celsius
  float temperatureC = (sensorValue * 5.0 / 1023.0) * 100.0;
  	if (temperatureC<Threshold) 
    {
      LED_ARRAY1=0xFF;                       //LED is in ON state
      for(unsigned int wait=250000;wait--;); // equivalent to delay of 250 miliseconds
      LED_ARRAY1=0x00;                       // LED is in OFF state
    }
    else if(temperatureC>Threshold)
    {
      LED_ARRAY1=0xFF;
      for(unsigned int wait=500000;wait--;);
      LED_ARRAY1=0x00;
    }
  digitalWrite(ledPin, !digitalRead(ledPin));
}