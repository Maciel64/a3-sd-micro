#include <Arduino.h>
#include "modules/wifi/wifi_service.h"
#include "modules/led/led_controller.h"
#include "modules/server/server.h"

int greenLed = 4; // D1
int redLed = 5;   // D2

WifiService wifiService;
LedController ledController(greenLed, redLed);

WebServerService webServer(ledController);

void setup()
{
  Serial.begin(115200);

  wifiService.connect();

  ledController.begin();

  webServer.begin();
}

void loop()
{
  webServer.loop();
  ledController.loop();
}