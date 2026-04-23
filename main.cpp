#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

// IMPORTANT: Change this for each room (e.g., NHM_RED, NHM_GREEN)
#define BEACON_NAME "NHM_BLUE"

void setup() {
  Serial.begin(115200);
  Serial.println("Starting ESP32 NHM Beacon...");

  BLEDevice::init(BEACON_NAME);
  
  // We create a server so the iPhone sees it as a connectable device
  BLEServer *pServer = BLEDevice::createServer();
  
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  
  // Use a standard Battery Service UUID so Bluefy recognizes the profile
  pAdvertising->addServiceUUID(BLEUUID((uint16_t)0x180F)); 
  
  pAdvertising->setScanResponse(true);
  // These parameters help iOS discover the device faster
  pAdvertising->setMinPreferred(0x06);  
  pAdvertising->setMaxPreferred(0x12);
  
  BLEDevice::startAdvertising();
  Serial.print("Beacon is Live: ");
  Serial.println(BEACON_NAME);
}

void loop() {
  // Keep the CPU calm
  delay(2000);
}
