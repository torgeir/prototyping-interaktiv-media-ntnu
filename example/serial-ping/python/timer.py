import time

class Timer:
  "Checks when amount of time has passed"

  def __init__(self, seconds):
    self.seconds = seconds;
    self.startTime = time.time();

  def isDone(self):
    return time.time() - self.startTime > self.seconds;
