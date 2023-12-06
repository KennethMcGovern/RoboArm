// Define the joystick and button pins
#define JOYSTICK_X_PIN A0
#define JOYSTICK_BUTTON_PIN 2

void setup() {
  Serial.begin(9600);

  // Set up the joystick and button pins
  pinMode(JOYSTICK_X_PIN, INPUT);
  pinMode(JOYSTICK_BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // Read the joystick X-axis value
  int joystickValueX = analogRead(JOYSTICK_X_PIN);

  // Read the button state
  bool buttonPressed = digitalRead(JOYSTICK_BUTTON_PIN) == LOW;

  // Determine the joystick direction based on X-axis value
  if (joystickValueX <= 20) {
    Serial.println("Joystick Pressed to the Left");
    Serial.println(joystickValueX);
    delay(1000);
  } else if (joystickValueX >= 900) {
    Serial.println("Joystick Pressed to the Right");
    Serial.println(joystickValueX);
    delay(1000);

  } else if (joystickValueX = 35) {
    Serial.println("No Movement");
    Serial.println(joystickValueX);
    delay(1000);
  }

  delay(100);  // Add a small delay to avoid rapid serial prints
}
