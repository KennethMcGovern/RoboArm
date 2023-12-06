#include <AccelStepper.h>

// Define the stepper motor connections
#define STEP_PIN 2
#define DIR_PIN 3

// Define the joystick connections
#define JOY_X_PIN A0
#define JOY_Y_PIN A1

// Define the home state values for the joystick
#define JOY_HOME_X -477
#define JOY_HOME_Y 21

// Create a stepper motor object
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup() {
  // Set up serial communication
  Serial.begin(9600);

  // Set up stepper motor properties
  stepper.setMaxSpeed(1000.0);
  stepper.setAcceleration(500.0);

  // Set up joystick pins
  pinMode(JOY_X_PIN, INPUT);
  pinMode(JOY_Y_PIN, INPUT);

  // Move the stepper motor to the home position
  stepper.moveTo(0);
}

void loop() {
  // Read joystick values
  int joyX = analogRead(JOY_X_PIN);
  int joyY = analogRead(JOY_Y_PIN);

  // Map joystick values to a range of -512 to 512
  int mappedJoyX = map(joyX, 0, 1023, -512, 512);
  int mappedJoyY = map(joyY, 0, 1023, -512, 512);

  // Move the stepper motor based on joystick input
  if (mappedJoyY != JOY_HOME_Y) {
    // Calculate the steps based on joystick Y-axis position
    int steps = mappedJoyY;

    // Move the stepper motor
    stepper.moveTo(steps);
    Serial.print("Steps: ");
    Serial.println(steps);

    // Update the stepper motor position
    stepper.run();
  } else {
    // If joystick is in the home position, stop the stepper motor
    stepper.stop();
    stepper.runToPosition();
  }

  // Print joystick values for debugging
  Serial.print("JoyX: ");
  Serial.print(mappedJoyX);
  Serial.print("\tJoyY: ");
  Serial.println(mappedJoyY);
  
  // Add a delay for stability
  delay(200);
}
