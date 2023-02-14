// Test program for the servo

#include <Servo.h>

const int PIN_SERVO = 8;
Servo myservo;

const byte GAUCHE = 47;
const byte DROIT = 77;
const byte DROITE = 107;


void setup() {
  myservo.attach(PIN_SERVO);
}
  

void loop() {  
  myservo.write(77);
  delay(2000);
  myservo.write(47);
  delay(3000);
  myservo.write(107);
  delay(5000);
}
