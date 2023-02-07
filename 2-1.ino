#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); // Declare the device
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);

int capteur = 4;

void setup()
{
  AFMS.begin();
  myMotor->setSpeed(150);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(capteur, INPUT);
  pinMode(3, INPUT);
}

void loop()
{
  if (digitalRead(3)) {
   int d = lire_distance(capteur);
    digitalWrite(7, d < 20);
    digitalWrite(6, d < 10);
    if (d < 10) {
      myMotor->run(RELEASE);
    }
    else {
      myMotor->run(FORWARD);
    } 
  }
  else {
    myMotor->run(RELEASE);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
  }
}

int lire_distance(int numero_broche) {
  pinMode(numero_broche, OUTPUT);
  digitalWrite(numero_broche, LOW);
  delayMicroseconds(2);
  digitalWrite(numero_broche, HIGH);
  delayMicroseconds(10);
  digitalWrite(numero_broche, LOW);
  pinMode(numero_broche, INPUT);
  return 0.01723 * pulseIn(numero_broche, HIGH);
}
