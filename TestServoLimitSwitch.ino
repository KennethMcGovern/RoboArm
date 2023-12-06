/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>
#define LIMIT_SWITCH_PIN 7

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int H;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  pinMode(LIMIT_SWITCH_PIN, INPUT);
  int H = 0;
}
void loop() {

  if (digitalRead(LIMIT_SWITCH_PIN) == HIGH)
  {
    Serial.println("Activated!");
    H = 1;
  }
  else{
    Serial.println("Not activated.");
    delay(15)
    ;H = 0;
  }

  if (H = 1) {
    pos + 90;
    myservo.write(pos);
    delay(15);
  } 

  else {
    delay(15);
  }
  delay(100);
}
