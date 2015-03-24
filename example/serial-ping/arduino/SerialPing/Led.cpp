#include "Arduino.h"
#include "Led.h"

Led::Led(int pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

void Led::on() {
  digitalWrite(_pin, HIGH);
}

void Led::off() {
  digitalWrite(_pin, LOW);
  _duration = 0;
}

void Led::onFor(long duration) {
  _duration = duration;
  _startTime = millis();
  on();
}

void Led::tick() {
  if (_duration == 0) {
    return;
  }

  if (millis() > _startTime + _duration) {
    off();
  }
}
