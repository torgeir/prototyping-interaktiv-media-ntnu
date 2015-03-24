import serial
port = serial.Serial("/dev/cu.usbmodemfd13131", 9600)

from timer import Timer

def run():
  timer = Timer(5)
  while (True):

    if (timer.isDone()):
      print "sending ping"
      port.write("ping\n")
      timer = Timer(5)

    msg = read();
    if (msg == 'pong'):
      print "Oooh! got pong."

def read():
  if (port.inWaiting() > 0):
    line = port.readline()
    line = line.rstrip() # fjerner \r\n
    return line
  return ""

run()
