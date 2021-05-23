#include "config.h"

#include <ArduinoJson.h>
#include <SD.h>

/*
Load JSON config
inspired by https://arduinojson.org/v6/example/config/
*/
void Config::load(const char *filename) {
  // Open file for reading
  File file = SD.open(filename);

  // Allocate a temporary JsonDocument
  // Don't forget to change the capacity to match your requirements.
  // Use arduinojson.org/v6/assistant to compute the capacity.
  StaticJsonDocument<512> doc;

  // Deserialize the JSON document
  DeserializationError error = deserializeJson(doc, file);
  if (error)
    Serial.println(F("Failed to read file, using default configuration"));

  // Copy values from the JsonDocument to the Config
  strlcpy(ssid,                  // <- destination
    doc["wifi"]["ssid"],   // <- source
    sizeof(ssid));         // <- destination's capacity

  strlcpy(password,                  // <- destination
    doc["wifi"]["password"],   // <- source
    sizeof(password));         // <- destination's capacity

  // Close the file (Curiously, File's destructor doesn't close the file)
  file.close();
}

Config config;
