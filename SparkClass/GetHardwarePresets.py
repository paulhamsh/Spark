import serial
import struct
import socket
import time

from SparkReaderClass import *
from SparkCommsClass import *



reader = SparkReadMessage()

comms = SparkComms("bluetooth")
comms.connect()


for i in [0,1,2,3]:
    print("Get preset %d" % i)

    comms.send_preset_request(i)

    dat = comms.get_data()
    reader.set_message(dat)
    reader.read_message()
    
    print ("================")
    #print (reader.python)
    print (reader.text)
    #print (reader.raw)



