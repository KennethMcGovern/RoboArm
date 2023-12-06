#define dirPin 2   //direction
#define stepPin 3  //step-pulse
#define enaPin 4   //enable-motor
int STPR;


void setup() {

  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enaPin, OUTPUT);
  Serial.begin(9600);
  Serial.println();
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();
    Serial.print("You entered: ");
    Serial.println(input); // Print the character back to the Serial monitor
  }
}

void xMoveSteps(bool dir, int steps) {

  digitalWrite(enaPin, LOW);  //enable movement or lock
  digitalWrite(dirPin, dir);

  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }

  digitalWrite(enaPin, HIGH);  //disable movement or free
}