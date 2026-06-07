#pragma once

#include <ESP8266WebServer.h>
#include "../led/led_controller.h"

class WebServerService
{
public:
    explicit WebServerService(LedController &led);

    void begin();
    void loop();

private:
    ESP8266WebServer server;
    LedController &ledController;

    void registerRoutes();
};