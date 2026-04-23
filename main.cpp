#include <Arduino.h> // <--- MUST BE AT THE TOP
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define BEACON_NAME "NHM_BLUE" 

void setup() {
  Serial.begin(115200);
  BLEDevice::init(BEACON_NAME);
  BLEServer *pServer = BLEDevice::createServer();
  
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(BLEUUID((uint16_t)0x180F)); 
  pAdvertising->setScanResponse(true);
  
  BLEDevice::startAdvertising();
  Serial.println("Beacon live!");
}

void loop() {
  delay(2000); // Now the compiler knows what this is!
}