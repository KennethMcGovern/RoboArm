#define dirPin 2 //direction
#define stepPin 3 //step-pulse
#define enaPin 4 //enable-motor
#define STPR 800 //steps-per-revolution

void setup() {

 pinMode(stepPin, OUTPUT);
 pinMode(dirPin, OUTPUT);
 pinMode(enaPin, OUTPUT);
}

void loop() {

 xMoveSteps(true, STPR*2);
 delay(4000); //delay 4 seconds
}

void xMoveSteps(bool dir, int steps){

 digitalWrite(enaPin, LOW); //enable movement or lock
 digitalWrite(dirPin, dir);

 for (int i = 0; i < steps; i++) {
   digitalWrite(stepPin, HIGH);
   delayMicroseconds(2000);
   digitalWrite(stepPin, LOW);
   delayMicroseconds(2000);
 }

 digitalWrite(enaPin, HIGH); //disable movement or free
}