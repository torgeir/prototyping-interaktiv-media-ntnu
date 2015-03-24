#include "Button.h"
#include "Arduino.h"

Button::Button(int pin) {
  _pin = pin;
  pinMode(_pin, INPUT);
  _state = 0;
  _startTime = 0;
}

void Button::onClick(callbackFunction callback) {
  _callback = callback;
}

void Button::tick() {
  int level = digitalRead(_pin);
  bool enoughTimeHasPassed = millis() > _startTime + 600;
  
  if (_state == 0 && level == HIGH) {
    _startTime = millis();
    _state = 1;
  }
  else if (_state == 1  && level == LOW) {
    _state = 2;
  }
  else if (_state == 2 && enoughTimeHasPassed) {
    _state = 0;
    if (_callback) _callback();
  }
}
