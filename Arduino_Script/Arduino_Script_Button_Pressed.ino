const int buttonPin = D1;
bool lastState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up
  Serial.begin(9600);
}

void loop() {
  bool currentState = digitalRead(buttonPin);

  //Serial.println(currentState);

  if (currentState != lastState) {
    lastState = currentState;

    if (currentState == LOW) {
      Serial.println("pressed");
    } else {
      Serial.println("released");
    }

    delay(50); // Debounce
  }
}