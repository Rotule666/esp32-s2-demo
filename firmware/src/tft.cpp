#include "tft.h"

#include <SPI.h>
#include <string>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7735

SPIClass tftSpi(HSPI);
Adafruit_ST7789 tft = Adafruit_ST7789(&tftSpi, TFT_CS, TFT_DC, TFT_RST);

statusScreen lcdStatus;

void statusScreen::setSsid(const char* newSsid){
  strncpy(ssid, newSsid, 24);
  tft_draw_status();
}

void statusScreen::setWifiStatus(const char* newStatus){
  strncpy(WifiStatus, newStatus, 24);
  tft_draw_status();
}
void statusScreen::setIp(const char* newIp){
  strncpy(IP, newIp, 15);
  tft_draw_status();
}

void tft_draw_status(){
  tft.fillScreen(ST77XX_BLACK);

  tft.drawLine(0, 0, 135, 0, ST77XX_WHITE);

  tft.setCursor(0, 2);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextWrap(false);

  tft.print("WiFi:");
 
  tft.setCursor(0, 20);
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextWrap(false);

  String statusStr = String() + lcdStatus.ssid + " : " + lcdStatus.WifiStatus;
  tft.print(statusStr.c_str());

  tft.setCursor(0, 30);
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextWrap(false);
  tft.print(lcdStatus.IP);

  tft.drawLine(0, 39, 135, 39, ST77XX_WHITE);
}


void setup_tft(){
  pinMode(TFT_BACKLIGHT, OUTPUT);
  digitalWrite(TFT_BACKLIGHT, HIGH);

  tftSpi.begin(TFT_SCK, TFT_MISO, TFT_MOSI, TFT_CS);

  tft.init(135, 240);
  tft.setRotation(2);

  tft.fillScreen(ST77XX_BLACK);
}
