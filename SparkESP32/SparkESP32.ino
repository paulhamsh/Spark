// if CLASSIC is defined, will compile with BLE stack which allows serial bluetooth - if not defined will use NimBLE which has no serial bluetooth
// it matters because Android Spark apps use serial bluetooth
// but BLE doesn't handle Spark disconnection well, whereas NimBLE does
#define CLASSIC

// define this if using a bluetooth controller like Akai LPD8 Wireless or IK Multimedia iRig Blueboard
#define BT_CONTROLLER

#include "Spark.h"

void setup() {
  spark_state_tracker_start();  // set up data to track Spark and app state
}


void loop() {
  // create commands to send to the Spark amp
  /*
  change_amp_param(AMP_GAIN, mi3/127.0); 
  change_amp_param(AMP_MASTER, mi3/127.0); 
  change_drive_toggle();    
  change_delay_toggle();  
  change_reverb_toggle();  
  change_hardware_preset(0);  
  change_hardware_preset(1); 
  change_hardware_preset(2); 
  change_hardware_preset(3);     
  */
  
  
  if (update_spark_state()) { // this sends those commands and picks up incoming messages
    // do your own checks and processing here to respond to the incoming messages - only one message per call of this function
    /*
    if (cmdsub == 0x0301) {
      // an example - do something on message 0x0301
    }
    */
  }

}
