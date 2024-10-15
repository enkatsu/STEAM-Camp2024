import processing.serial.*;
import processing.net.*;

Client client;
String host = "153.121.33.11";

Serial serial;
int val = 0;

void setup() {
  size(400, 400);
  client = new Client(this, host, 32000);

  println(Serial.list());
  serial = new Serial(this, "/dev/cu.usbmodem1301", 9600);
}

void draw() {
  background(0);
  if (serial.available() > 0) {
    val = serial.read();
    client.write(val);
  }
  ellipse(width/2, height/2, val, val);
}
