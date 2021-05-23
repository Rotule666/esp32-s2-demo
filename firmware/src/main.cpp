#include <Arduino.h>

#include <FS.h>
#include <SD.h>

#include "config.h"
#include "tft.h"
#include "sd_application.h"
#include "updater.h"
#include "wifi_application.h"
#include "webserver_application.h"

#define RED_LED_PIN 1
#define POWER_PIN 14


void setup() {

  pinMode(POWER_PIN, OUTPUT);
  digitalWrite(POWER_PIN, HIGH);

  
  Serial.begin(115200); // Setup serial for monitoring
  Serial.println("Booting");
  
  setup_tft();  // Setup tft needed first

  setup_sd();   // Setup SD is needed before loading config

  updateFromFS(SD);

  config.load("/settings.json"); // Load config needed before connecting to wifi

  setup_wifi(); // wifi needed before sebserver

  setup_webserver(); // web server and API routes
  
}


void loop() {


}

