// Tests pour le servomoteur

#include <Servo.h>

const int PIN_SERVO = 8;
int mainrad = 95;
Servo myservo;

void setup() {
  myservo.attach(PIN_SERVO);
}

void loop() {
  myservo.write(mainrad);
}
