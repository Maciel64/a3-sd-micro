#include <Arduino.h>
#include "modules/wifi/wifi_service.h"
#include "modules/led/led_controller.h"
#include "modules/server/server.h"
#include "modules/buzzer/buzzer_controller.h"

int greenLed = 4; // D1
int redLed = 5;   // D2

WifiService wifiService;
LedController ledController(greenLed, redLed);

BuzzerController buzzerController(12);
WebServerService webServer(ledController, buzzerController);

void setup()
{
  Serial.begin(115200);

  wifiService.connect();

  ledController.begin();
  buzzerController.begin();

  webServer.begin();
}

void loop()
{
  webServer.loop();
  ledController.loop();
}