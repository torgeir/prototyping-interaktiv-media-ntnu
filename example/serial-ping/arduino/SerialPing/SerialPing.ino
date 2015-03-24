#include "Led.h"
#include "Button.h"

Button button(2);
Led led(12);

void setup() {
  Serial.begin(9600);
  button.onClick(handleMsgPing);
}

void loop() {
  button.tick();
  led.tick();
  
  String data = readData();
  if (data.length() > 0) {
    
    if (data == "ping") {
      handleMsgPing();
    }
    else {
      handleMsgUnknown();
    }
  }
  
  delay(100);
}

void handleMsgPing() {
  Serial.println("pong");
  led.onFor(100);
}

void handleMsgUnknown() {
  Serial.println("unknown");
  led.onFor(400);
}

String readData() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    if (data.length() > 0) {
      return data;
    }
  }
  return "";
}

