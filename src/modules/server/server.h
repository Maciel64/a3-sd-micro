#pragma once

#include <ESP8266WebServer.h>
#include "../led/led_controller.h"
#include "../buzzer/buzzer_controller.h"

class WebServerService
{
public:
    explicit WebServerService(LedController &led, BuzzerController &buzzer);

    void begin();
    void loop();

private:
    ESP8266WebServer server;
    LedController &ledController;
    BuzzerController &buzzerController;

    void registerRoutes();
};