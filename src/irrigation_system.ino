// Total number of plants/channels
const int NUM_CHANNELS = 4;

// Transistor control pins (connected to motors)
const int motorPins[NUM_CHANNELS] = {13, 12, 11, 10};  

// Analog input pins for moisture sensors
const int sensorPins[NUM_CHANNELS] = {A0, A1, A2, A3}; 

// ADJUST THESE: Calibrate your dry/wet baseline limits
const int dry_value = 0;          // Raw value when sensor is bone dry in air
const int wet_value = 539;        // Raw value when sensor is fully dipped in wet soil

// NEW: Custom moisture thresholds for each plant channel (0% to 100%)
// Adjust these numbers based on what each specific plant needs!
const int turn_on_thresholds[NUM_CHANNELS] = {
  30, // Plant 1 threshold (e.g., Cactus - likes it drier)
  45, // Plant 2 threshold (e.g., Monstera)
  45, // Plant 3 threshold
  60  // Plant 4 threshold (e.g., Fern - loves it wet)
}; 

void setup()
{
  Serial.begin(9600);
  
  // Dynamically set up all motor pins and ensure they start OFF
  for (int i = 0; i < NUM_CHANNELS; i++) {
    pinMode(motorPins[i], OUTPUT);
    digitalWrite(motorPins[i], LOW); 
  }
  
  delay(500);
}

void loop()
{
  Serial.println("=======================");
  
  // Process each plant channel sequentially using a loop
  for (int i = 0; i < NUM_CHANNELS; i++) {
    // Read the raw 0-1023 value
    int raw_value = analogRead(sensorPins[i]); 
    
    // Convert raw value to percentage and constrain between 0% and 100%
    int percent_moisture = map(raw_value, dry_value, wet_value, 0, 100);
    percent_moisture = constrain(percent_moisture, 0, 100);
    
    // Print human-readable output to the serial monitor
    Serial.print("Plant ");
    Serial.print(i + 1);
    Serial.print(" -> Raw: ");
    Serial.print(raw_value);
    Serial.print(" | Moisture: ");
    Serial.print(percent_moisture);
    Serial.print("% (Target: >");
    Serial.print(turn_on_thresholds[i]);
    Serial.print("%)");
    
    // Logic check: Turn motor ON if soil moisture drops below this specific plant's threshold
    if (percent_moisture < turn_on_thresholds[i]) {
      digitalWrite(motorPins[i], HIGH);  // Motor ON
      Serial.println(" [PUMPING]");
    } else {
      digitalWrite(motorPins[i], LOW);   // Motor OFF
      Serial.println(" [OK]");
    }
  }
  
  // Checking every few seconds or minutes is highly efficient for real plants!
  delay(2000); 
}
