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
  if (update_spark_state()) {
    // do your own checks and processing here    
  }
}
