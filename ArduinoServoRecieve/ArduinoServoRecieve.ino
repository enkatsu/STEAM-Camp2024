#include <Servo.h>
#define SERVO_PIN 7

Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(SERVO_PIN, 500, 2400);
}

void loop() {
  if (Serial.available()) {
    int val = Serial.read();
    val = map(val, 0, 255, 0, 180);
    servo.write(val);
  }
}
