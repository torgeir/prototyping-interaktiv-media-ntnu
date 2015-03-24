extern "C" {
  typedef void (*callbackFunction)(void);
}

class Button {
  public:
    Button(int pin);
    void tick();
    void onClick(callbackFunction callback);
  private:
    int _pin;
    int _state;
    long _startTime;
    callbackFunction _callback;
};
