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
  serial = new Serial(this, "/dev/cu.usbmodem1101", 9600);
  serial.write(255);
}

void draw() {
  background(0);
  if (client.available() > 0) {
    val = client.read();
    serial.write(val);
  }
  ellipse(width/2, height/2, val, val);
}
