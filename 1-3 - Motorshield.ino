// Programme de test du moteur

// Required libraries to run this code
// First one is the dedicated library for the Adafruit MotorShield device, and the second one is a required library to run the first
// Adafruit MotorShield V2: https://github.com/adafruit/Adafruit_Motor_Shield_V2_Library
// Adafruit BusIO: https://github.com/adafruit/Adafruit_BusIO

#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); // Declare the device
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);

void setup() {
  AFMS.begin();
  myMotor->setSpeed(150);
}

void loop() {
  myMotor->run(FORWARD);
}
