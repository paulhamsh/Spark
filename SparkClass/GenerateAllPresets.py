from AllPresets import *
from SparkClass import *

msg = SparkMessage()

for i in range (len(preset_list)):
    b = msg.create_preset(preset_list[i])
    print ("preset_%dh=[" % (i+1))
    for x in b:
        print ("\"%s\"," % x.hex())
    print("]")
