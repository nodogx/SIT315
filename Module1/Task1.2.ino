const int tempSensorPin = A0;  // Analogue input pin connected to TMP36
const int ledPin = 12;         // Digital output pin connected to the red LED

unsigned long previousMillis = 0;  // Last time the temperature was checked
const long interval = 1000;        // Interval to check temperature (in milliseconds)

void setup() {
  Serial.begin(9600);  // Start serial communication
  pinMode(ledPin, OUTPUT);  // Set the LED pin as output
  previousMillis = millis();  // Initialise the timing
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Update the last check time
    checkTemperature();  // Call the temperature check function
  }
}

void checkTemperature() {
  int sensorValue = analogRead(tempSensorPin);  // Read the analogue value
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert to voltage
  float temperatureC = (voltage - 0.5) * 100.0;  // Convert to Celsius

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");
  
  if (temperatureC > 30.0) {  // Threshold temperature in Celsius
    digitalWrite(ledPin, HIGH);  // Turn on the LED
    Serial.println("Temperature exceeded 30°C, LED ON");
  } else {
    digitalWrite(ledPin, LOW);   // Turn off the LED
    Serial.println("Temperature below 30°C, LED OFF");
  }
}
