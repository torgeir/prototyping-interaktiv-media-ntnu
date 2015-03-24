import processing.serial.*;
import java.util.Date;

import http.requests.*;

Serial port;

void setup() {
  size(640, 480);
  frameRate(30);
  resetBackground();
  connectToArduino();
  
  GetRequest get = new GetRequest("http://vg.no");
  get.send();
  println("Reponse Content: " + get.getContent());
}

long lastdata = millis();
void draw() {
  if (millis() - lastdata > 1000) {
    resetBackground();
  }
  
  String data = readData();
  if (data.length() > 0) {
    lastdata = millis();
    println("got: " + data);
    if (data.equals("pong")) {
      handleMsgPong();
    } else {
      handleMsgUnknown();
    }
  }
}

void keyPressed() {
  background(241, 255, 0);
  if (key == 'p') {
    writeData("ping");
  }
  else {
    writeData("unknown");
  }
}

void handleMsgPong() {
  background(0, 255, 0);
}

void handleMsgUnknown() {
  background(255, 0, 0);
}

void resetBackground() {
  background(51);
}

void writeData(String data) {
   port.write(data + "\n");
}

String readData() {
  if (port.available() > 0) {
    String read = port.readStringUntil('\n');
    if (read != null) {
      return read.replace("\r\n", "");
    }
  }

  return "";
}

void connectToArduino() {
  String device = findDevice();
  port = new Serial(this, device, 9600);
  port.clear();
  port.bufferUntil('\n');
}

String findDevice() {
  for (String device : Serial.list()) {
    if (device.indexOf("tty.usbmodem") != -1) {
      return device;
    }
  }

  println(Serial.list());
  throw new RuntimeException("Could not find arduino");
}

