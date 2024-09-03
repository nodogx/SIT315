const int tempSensorPin = A0;  // Analog input pin connected to TMP36
const int ledPin = 12;         // Digital output pin connected to the red LED

void setup() {
  // Starting serial communication
  Serial.begin(9600);
  
  // Set the LED pin as output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Reading the analog value from the temperature sensor
  int sensorValue = analogRead(tempSensorPin);
  
  // Convert the analog value to a voltage
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // Convert the voltage to a temperature in Celsius
  float temperatureC = (voltage - 0.5) * 100.0;
  
  // Print the temperature to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");
  
  // Control the red LED based on the temperature
  if (temperatureC > 30.0) { // Threshold temperature in Celsius
    digitalWrite(ledPin, HIGH); // Turn on the LED if temperature exceeds 30°C
  } else {
    digitalWrite(ledPin, LOW);  // Turn off the LED if temperature is 30°C or lower
  }
  
  // Short delay to improve readability of Serial Monitor
  delay(500);
}
