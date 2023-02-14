// Code final, faisant faire demi-tour au robot
// To access step-to-step programs: https://github.com/FireMKM/Meccano

// Required libraries to run this code
// First one is the dedicated library for the Adafruit MotorShield device, and the second one is a required library to run the first
// Adafruit MotorShield V2: https://github.com/adafruit/Adafruit_Motor_Shield_V2_Library
// Adafruit BusIO: https://github.com/adafruit/Adafruit_BusIO

//Libraries
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Servo.h>

// Declare the motorshield
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); // Declare the device
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);

// Declare the constants
int capteur = 4;

const int PIN_SERVO = 8;
const int mainrad = 95;
const int delta = 15;
Servo myservo;


// Setup fonction
void setup()
{
  //MOTOR
  AFMS.begin();
  myMotor->setSpeed(250);

  //PIN
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(3, INPUT);
  pinMode(capteur, INPUT);

  //SERVO
  myservo.attach(PIN_SERVO);
}

void loop() {
  //IF ON
  if (digitalRead(3)) {
    int d = lire_distance(capteur);
      //LEDS
    digitalWrite(6, d < 20);
    digitalWrite(7, d < 10);
      //TURN AROUND
    if (d < 10) {
      myMotor->run(BACKWARD);
      myservo.write(mainrad+delta);
      delay(8000);
      myMotor->run(FORWARD);
      myservo.write(mainrad-delta);
      delay(8000);
      myMotor->run(FORWARD);
      myservo.write(mainrad);
      delay(5000);
    }
    else {
      myMotor->run(FORWARD);
    } 
  }
  //IF OFF
  else {
    myMotor->run(RELEASE);
    myservo.write(mainrad);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
  }
}

// Lecture de la distance
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
