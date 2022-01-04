

// if CLASSIC is defined, will compile with BLE stack which allows serial bluetooth - if not defined will use NimBLE which has no serial bluetooth
// it matters because Android Spark apps use serial bluetooth
// but BLE doesn't handle Spark disconnection well, whereas NimBLE does
//#define CLASSIC

// define this if using a bluetooth controller like Akai LPD8 Wireless or IK Multimedia iRig Blueboard
#define BT_CONTROLLER


#include "Spark.h"


SparkPreset my_preset{0x0,0x7f,"F00DF00D-FEED-0123-4567-987654321004","Paul Preset Test","0.7","Nothing Here","icon.png",120.000000,{ 
  {"bias.noisegate", true, 2, {0.316873, 0.304245}}, 
  {"Compressor", false, 2, {0.341085, 0.665754}}, 
  {"Booster", true, 1, {0.661412}}, 
  {"Bassman", true, 5, {0.768152, 0.491509, 0.476547, 0.284314, 0.389779}}, 
  {"UniVibe", false, 3, {0.500000, 1.000000, 0.700000}}, 
  {"VintageDelay", true, 4, {0.152219, 0.663314, 0.144982, 1.000000}}, 
  {"bias.reverb", true, 7, {0.120109, 0.150000, 0.500000, 0.406755, 0.299253, 0.768478, 0.100000}} },0x00 };


void setup() {
  spark_state_tracker_start();  // set up data to track Spark and app state
}


void loop() {
  if (update_spark_state()) {
    // do your own checks and processing here    
  }
}
