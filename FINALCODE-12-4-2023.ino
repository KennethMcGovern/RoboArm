#include <Servo.h>

// Define the joystick and button pins
#define dirPin 2 // direction
#define stepPin 3 // step-pulse
#define enaPin 4  // enable-motor
#define STPR 150  // steps-per-revolution
#define JOYSTICK_Y_PIN A1
#define JOYSTICK_BUTTON_PIN 2

Servo myServo;

int joystickX; // Analog pin for X axis

void setup() {
  Serial.begin(9600);

  myServo.attach(9); // Servo signal pin

  // Set up the joystick and button pins
  pinMode(JOYSTICK_Y_PIN, INPUT);
  pinMode(JOYSTICK_BUTTON_PIN, INPUT_PULLUP);

  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enaPin, OUTPUT);
}

void loop() {
  // Read the joystick X-axis value
  int joystickValueY = analogRead(JOYSTICK_Y_PIN);

  // Read the button state
  bool buttonPressed = digitalRead(JOYSTICK_BUTTON_PIN) == LOW;

  joystickX = analogRead(A0); // Read X axis

  int angleX = map(joystickX, 0, 1023, 0, 180); // Map X axis value to servo angle

  myServo.write(angleX); // Set servo position based on X axis
  delay(15); // Small delay for smooth motion

  // Determine the joystick direction based on X-axis value
  if (joystickValueY <= 20) {
    Serial.println("Joystick Pressed to the Left");
    Serial.println(joystickValueY);
    xMoveSteps(0, STPR);
    delay(250);
  } else if (joystickValueY >= 900) {
    Serial.println("Joystick Pressed to the Right");
    Serial.println(joystickValueY);
    xMoveSteps(1, STPR);
    delay(250);
  } else {
    Serial.println("No Movement");
    Serial.println(joystickValueY);
    // If you want to stop the motor when there's no movement, add the code here
  }

  // Check if the button is pressed
  if (buttonPressed) {
    Serial.println("Button Pressed");
    // Add the code you want to execute when the button is pressed
  }

  delay(100); // Add a small delay to avoid rapid serial prints
}

void xMoveSteps(bool dir, int steps) {
  digitalWrite(enaPin, LOW); // enable movement or lock
  digitalWrite(dirPin, dir);

  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  digitalWrite(enaPin, HIGH); // disable movement or unlock
}
