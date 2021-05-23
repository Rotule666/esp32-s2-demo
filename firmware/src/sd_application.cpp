#include <Arduino.h>

#include "sd_application.h"

#include <SPI.h>
#include <SD.h>
#include <FS.h>

SPIClass sdSpi(FSPI); // SD card spi

void setup_sd() {
  const int sdChipSelectPin = 10;
  const int sdSckPin = 12;
  const int sdMisoPin = 13;
  const int sdMosiPin = 11;

  pinMode(sdChipSelectPin,OUTPUT);

  Serial.println("Initializing SD card...");

  sdSpi.begin(sdSckPin, sdMisoPin, sdMosiPin, sdChipSelectPin);

  if(!SD.begin(sdChipSelectPin, sdSpi)){
    Serial.println("Card Mount Failed");
    return;
  }

  uint8_t cardType = SD.cardType();
  if(cardType == CARD_NONE){
    Serial.println("No SD_MMC card attached");
    return;
  }

  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
  Serial.printf("SD_MMC Card Size: %lluMB\n", cardSize);
  Serial.println("");
}
