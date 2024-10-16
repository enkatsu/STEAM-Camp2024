#define ECHO_PIN 2  // Echo Pin
#define TRIG_PIN 3  // Trigger Pin

void setup() {
  Serial.begin(9600);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  // 超音波を出力
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  // センサからの入力
  unsigned long duration = pulseIn(ECHO_PIN, HIGH);

  if (duration > 0) {
    // 往復距離を半分にする
    duration = duration / 2;
    // 音速を340m/sに設定
    byte distance = constrain(duration * 340 * 100 / 1000000, 0, 255);
    Serial.write(distance);
  }
  delay(100);
}
