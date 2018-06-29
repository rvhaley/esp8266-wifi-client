#include <Arduino.h>
#include <ESP8266WiFi.h>

extern "C" {
#include "user_interface.h"
}

/* Replace values in String constructor below with your network credentials */
const String STA_SSID = String("SSID"); // Network SSID
const String STA_PASS = String("PASSWORD"); // Network password

void setup() {
  Serial.begin(74880);
  Serial.setDebugOutput(true);

  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  
  Serial.print("Connecting to network ");
  Serial.println(STA_SSID);
  
  WiFi.begin(STA_SSID, STA_PASS);
  while (WiFi.status() != WL_CONNECTED) {
        delay(500);
  }
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    delay(10000);
    Serial.println("Disconnecting...");
    wifi_station_disconnect();
  }
}
