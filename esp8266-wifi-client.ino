#include <Arduino.h>
#include <ESP8266WiFi.h>

extern "C" {
#include "user_interface.h"
}

/* Replace values below with your network credentials */
char sta_ssid[] = "SSID"; // Network SSID
char sta_pass[] = "PASSWORD"; // Network password

void setup() {
  Serial.begin(74880);
  Serial.setDebugOutput(true);

  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  
  Serial.print("Connecting to network ");
  Serial.println(sta_ssid);
  
  WiFi.begin(sta_ssid, sta_pass);
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
