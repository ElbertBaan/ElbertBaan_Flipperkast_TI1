#include <Servo.h>

Servo motorlinks;
Servo motorrechts;

const int flipperlinks = 11;
const int flipperrechts = 10;

void setup() {
  pinMode(flipperlinks, INPUT_PULLUP);
  pinMode(flipperrechts, INPUT_PULLUP);

  motorlinks.attach(9);
  motorrechts.attach(8);

  motorlinks.write(0);
  motorrechts.write(0);

  Serial.begin(9600);
}

void loop() {

  // Linker flipper
  if (digitalRead(flipperlinks) == LOW) {
    motorlinks.write(95);
    Serial.println("Links");
  } else {
    motorlinks.write(0);
  }

  // Rechter flipper
  if (digitalRead(flipperrechts) == LOW) {
    motorrechts.write(95);
    Serial.println("Rechts");
  } else {
    motorrechts.write(0);
  }

  delay(10);
}