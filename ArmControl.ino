#include <Servo.h>

Servo myServo;

int joystickX; // Analog pin for X axis
int joystickY; // Analog pin for Y axis

void setup() {
  myServo.attach(9); // Servo signal pin
}

void loop() {
  joystickX = analogRead(A0); // Read X axis
  joystickY = analogRead(A1); // Read Y axis

  int angleX = map(joystickX, 0, 1023, 0, 180); // Map X axis value to servo angle
  int angleY = map(joystickY, 0, 1023, 0, 180); // Map Y axis value to servo angle

  myServo.write(angleX); // Set servo position based on X axis
  delay(15); // Small delay for smooth motion
}
