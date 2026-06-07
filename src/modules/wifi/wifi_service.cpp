#include "wifi_service.h"
#include "../../config/wifi_config.h"

#include <ESP8266WiFi.h>

void WifiService::connect()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    Serial.print("Conectando");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi conectado");
    Serial.println(WiFi.localIP());
}