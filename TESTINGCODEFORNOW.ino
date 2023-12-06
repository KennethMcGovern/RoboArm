

#define dirPin 2 //direction
#define stepPin 3 //step-pulse
#define enaPin 4 //enable-motor
#define STPR 360 //steps-per-revolution
#define JOYSTICK_X_PIN A0

void setup() {

 pinMode(stepPin, OUTPUT);
 pinMode(dirPin, OUTPUT);
 pinMode(enaPin, OUTPUT);
}

void loop() {

 xMoveSteps(0, STPR*2);
 delay(200); //delay 4 seconds
}

void xMoveSteps(bool dir, int steps){

 digitalWrite(enaPin, LOW); //enable movement or lock
 digitalWrite(dirPin, dir);

 for (int i = 0; i < steps; i++) {
   digitalWrite(stepPin, HIGH);
   delayMicroseconds(1000);
   digitalWrite(stepPin, LOW);
   delayMicroseconds(1000);
 }

 digitalWrite(enaPin, HIGH); //disable movement or free
}