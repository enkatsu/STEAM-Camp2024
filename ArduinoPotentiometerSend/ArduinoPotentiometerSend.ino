#define INPUT_PIN A0  // Potentiometer

void setup() {
  Serial.begin(9600);
  pinMode(INPUT_PIN, INPUT);
}

void loop() {
  int val = analogRead(INPUT_PIN);
  val = map(val, 0, 1023, 0, 255);
  Serial.write(val);
  delay(100);
}
