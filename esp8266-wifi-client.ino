#include <Arduino.h>
#include <ESP8266WiFi.h>

extern "C" {
#include "user_interface.h"
}

/* Replace values below with your network credentials */
char sta_ssid[] = ""; // Network SSID
char sta_pass[] = ""; // Network password

void setup() {
  Serial1.begin(74880);
  Serial1.setDebugOutput(true);

  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
 
  Serial1.print("Connecting to network ");
  Serial1.println(sta_ssid);
   
  WiFi.begin(sta_ssid, sta_pass);
  while (WiFi.status() != WL_CONNECTED) {
        delay(500);
  }

  if (WiFi.status() == WL_CONNECTED) {
    delay(10000);
    Serial1.println("Disconnecting...");
    wifi_station_disconnect();
  }
}

void loop() {
  
}
