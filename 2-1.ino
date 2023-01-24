#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); // Declare the device
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);

int led1 = 6;
int capteur = 4;

void setup()
{
  AFMS.begin();
  myMotor->setSpeed(150);
  pinMode(led1, OUTPUT);
  pinMode(capteur, INPUT);
}

void loop()
{
  int d = lire_distance(capteur);
  if (d < 10) {
    myMotor->run(BACKWARD);
  }
  else {
    myMotor->run(FORWARD);
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
