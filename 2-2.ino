#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Servo.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); // Declare the device
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);

int capteur = 4;

const int PIN_SERVO = 8;
int mainrad = 95;
Servo myservo;

void setup()
{
  AFMS.begin();
  myMotor->setSpeed(150);
  pinMode(6, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(capteur, INPUT);
  myservo.attach(PIN_SERVO);
}

void loop()
{
  int d = lire_distance(capteur);
  digitalWrite(6, d < 20);
  digitalWrite(3, d < 10);
  if (d < 10) {
    myservo.write(mainrad+15);
    myMotor->run(BACKWARD);
    delay(4000);
    myservo.write(mainrad);
    myMotor->run(FORWARD);
    delay(5000);
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
