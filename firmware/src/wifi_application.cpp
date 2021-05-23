#include "wifi_application.h"

#include "tft.h"
#include "config.h"

#include <WiFi.h>
#include <ESPmDNS.h>

void setup_wifi(){
  //connect to WiFi
    lcdStatus.setSsid(config.ssid);

	Serial.printf("Connecting to %s ", config.ssid);
    lcdStatus.setWifiStatus("Unceonnected");
	WiFi.disconnect(true);

    WiFi.setHostname(config.hostname);

	WiFi.mode(WIFI_OFF);
	delay(500);
	WiFi.begin(config.ssid, config.password);
	while (WiFi.status() != WL_CONNECTED) {
	    delay(500);
		Serial.print(".");
        lcdStatus.setWifiStatus("Connecting");
	}
	Serial.println("");
	Serial.println("WiFi connected");
    lcdStatus.setWifiStatus("Connected");
	Serial.print("IP address: ");
	Serial.print(WiFi.localIP());

    lcdStatus.setIp(WiFi.localIP().toString().c_str());
    Serial.println("");
    Serial.print("Hostname: ");
    Serial.print(WiFi.getHostname());
	Serial.println("");
    Serial.println("");

    if(!MDNS.begin(config.hostname)) {
        Serial.println("Error starting mDNS");
        return;
    }

    MDNS.addService("http", "tcp", 80);
}
