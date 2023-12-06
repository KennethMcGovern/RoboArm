#define joystickX A0
#define joystickY A1
#define joystickThreshold 60

#define dirPin 2   // direction
#define stepPin 3  // step-pulse
#define enaPin 4   // enable-motor
#define STPR 800   // steps-per-revolution (adjust this based on your motor)

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enaPin, OUTPUT);

  digitalWrite(enaPin, HIGH);  // disable movement initially
  Serial.begin(9600);
}

void loop() {
  int joystickYValue = analogRead(joystickY);

  if (abs(joystickYValue - 512) > joystickThreshold) {
    bool direction = (joystickYValue > 512) ? true : false;  // Set direction based on joystick movement
    moveStepper(direction, STPR * 2);  // Adjust the number of steps as needed
  }

  delay(40);  // delay for stability
}

void moveStepper(bool dir, int steps) {
  digitalWrite(enaPin, LOW);  // enable movement
  digitalWrite(dirPin, dir);

  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(20);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(20);
  }

  digitalWrite(enaPin, HIGH);  // disable movement
}
