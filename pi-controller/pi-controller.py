from __future__ import with_statement
import serial
from serial.serialutil import SerialException

def move_forward():
    try:
        with serial.Serial("/dev/ttyACM0", 9600, timeout=1) as ser:
            ser.write("w")
    except SerialException:
        print ("unable to communicate with the motor controller")

def move_backward():
    try:
        with serial.Serial("/dev/ttyACM0", 9600, timeout=1) as ser:
            ser.write("s")
    except SerialException:
        print ("unable to communicate with the motor controller")

def move_left():
    try:
        with serial.Serial("/dev/ttyACM0", 9600, timeout=1) as ser:
            ser.write("a")
    except SerialException:
        print ("unable to communicate with the motor controller")

def move_right():
    try:
        with serial.Serial("/dev/ttyACM0", 9600, timeout=1) as ser:
            ser.write("d")
    except SerialException:
        print ("unable to communicate with the motor controller")
    
move_forward()
move_backward()
move_left()
move_right()
