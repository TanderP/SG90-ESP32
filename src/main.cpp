/*
  Controls three servos with different easing settings
  New position command after normalized output (ye) reaches set value.
  https://wokwi.com/projects/361237697368753153
  by dlloydev, March 2023.

  ⚪ The green servo moves from 0 to 90 deg at 70 deg/s with linear motion.
  ⚪ The orange servo moves from 0 to 180 deg at 140 deg/s with sigmoid motion.
  ⚪ The purple servo moves from 45 to 135 deg at 180 deg/s with steep sigmoid motion.
*/

#include <Servo.h>

const int servoPin1 = 32;


// units in degrees per second
double speed1 = 1;


// When easing constant (ke) < 1.0, return value is normalized, when 1.0, returns pulse width (μs)
// ke = 0.0 is linear, between 0.0 and 1.0 is tunable sigmoid, 1.0 is normal response
// Normalized Tunable Sigmoid: https://www.desmos.com/calculator/ejkcwglzd1
double ke1 = 0.0;


// go to position (degrees)
uint8_t pos1 = 0;
uint8_t pos2 = 190;

Servo myservo = Servo();

void setup() {
  Serial.begin(115200);
}

void loop() {
myservo.write(servoPin1, pos1, speed1, ke1);
delay(600);
myservo.write(servoPin1, pos2, speed1, ke1);
delay(600);

  delay(6);
}
