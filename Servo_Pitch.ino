#include <Servo.h>

Servo myServo1;
Servo myServo2;

int joystick1X; // Analog pin for X axis
int joystick1Y; // Analog pin for Y axis

void setup() {
  myServo1.attach(9); // Servo signal pin
  myServo2.attach(10); // Servo signal pin
}

void loop() {
  joystick1X = analogRead(A0); // Read X axis
  joystick1Y = analogRead(A1); // Read Y axis

  int angle1X = map(joystick1X, 0, 1023, 0, 75); // Map X axis value to servo angle
  int angle1Y = map(joystick1Y, 0, 1023, 0, 75); // Map Y axis value to servo angle

  Serial.println(joystick1X);
  Serial.println(joystick1Y);

  myServo1.write(angle1X); // Set servo position based on X axis
  delay(15); // Small delay for smooth motion
  myServo2.write(angle1Y); // Set servo position based on Y axis
  delay(15); // Small delay for smooth motion
}



