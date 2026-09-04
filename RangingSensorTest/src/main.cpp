#include <Arduino.h>

const int trigPin = 32;
const int echoPin = 23;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear the TRIG pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send a 10 microsecond pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the ECHO pin (returns sound wave travel time in microseconds)
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in cm (Speed of sound is ~343 m/s)
  float distanceCm = duration * 0.0343 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");
  
  delay(1000); // Wait 1 second before next reading
}