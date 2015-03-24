class Led {
  public:
    Led(int pin);
    void on();
    void off();
    void tick();
    void onFor(long ms);
  private:
    int _pin;
    long _duration;
    long _startTime;
};
