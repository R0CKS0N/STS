#include <Arduino.h>
#include <Stepper.h>

// Define the number of steps per revolution for the stepper motors
const int stepsPerRevolution = 2048;

// Define the pins for the stepper motor control
const int motor1Pin1 = 8;
const int motor1Pin2 = 9;
const int motor1Pin3 = 10;
const int motor1Pin4 = 11;
const int motor2Pin1 = 4;
const int motor2Pin2 = 5;
const int motor2Pin3 = 6;
const int motor2Pin4 = 7;

// Define the LDR pins
const int ldr1Pin = A0;
const int ldr2Pin = A1;
const int ldr3Pin = A2;
const int ldr4Pin = A3;

// Create instances of the stepper motors
Stepper motor1(stepsPerRevolution, motor1Pin1, motor1Pin3, motor1Pin2, motor1Pin4);
Stepper motor2(stepsPerRevolution, motor2Pin1, motor2Pin3, motor2Pin2, motor2Pin4);

void setup() {

  // Initialize Serial communication
  Serial.begin(9600);

  // Set the motor control pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor1Pin3, OUTPUT);
  pinMode(motor1Pin4, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motor2Pin3, OUTPUT);
  pinMode(motor2Pin4, OUTPUT);
}

void loop() {
  // Read the LDR values
  int ldr1Value = analogRead(ldr1Pin);
  int ldr2Value = analogRead(ldr2Pin);
  int ldr3Value = analogRead(ldr3Pin);
  int ldr4Value = analogRead(ldr4Pin);

  // Determine the movement direction for each motor based on the LDR readings
  int motor1Direction = (ldr1Value + ldr2Value) > (ldr3Value + ldr4Value) ? -1 : 1;
  int motor2Direction = (ldr1Value + ldr3Value) > (ldr2Value + ldr4Value) ? -1 : 1;

  // Move the motors
  motor1.setSpeed(100);  // Adjust the speed as needed
  motor2.setSpeed(100);  // Adjust the speed as needed
  motor1.step(motor1Direction);
  motor2.step(motor2Direction);

  delay(100);
}