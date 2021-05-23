#ifndef _CONFIG_H_INCLUDED
#define _CONFIG_H_INCLUDED

class Config {
    public:

        void load(const char *);

        char ssid[33] = "";
        char password[33] = "";
        const char* hostname = "esp32s2";
};

extern Config config;

#endif
