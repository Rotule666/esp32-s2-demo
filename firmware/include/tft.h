
#ifndef _TFT_H_INCLUDED
#define _TFT_H_INCLUDED


/*
Control pins
*/
#define TFT_CS        34
#define TFT_DC        37
#define TFT_RST       38
#define TFT_BACKLIGHT 33


/*
SPI pins
*/
#define TFT_SCK  36
#define TFT_MISO 37
#define TFT_MOSI 35


/*
Status screen information
*/
class statusScreen {
  public:
    void setSsid(const char* newSsid);
    void setWifiStatus(const char* newStatus);
    void setIp(const char* newIp);
    char ssid[25] = "";
    char WifiStatus[25] = "Unknown";
    char IP[16] = "255.255.255.255";
};

extern statusScreen lcdStatus;

void tft_draw_status();

void setup_tft();

#endif
