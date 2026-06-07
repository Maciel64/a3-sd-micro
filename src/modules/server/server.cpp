#include "server.h"

#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include "../buzzer/music.h"

WebServerService::WebServerService(LedController &led, BuzzerController &buzzer)
    : server(80),
      ledController(led),
      buzzerController(buzzer) {}

void WebServerService::begin()
{
    registerRoutes();
    server.begin();

    Serial.println("Servidor iniciado");
}

void WebServerService::loop()
{
    server.handleClient();
}

void WebServerService::registerRoutes()
{

    server.on("/", HTTP_GET, [this]()
              { server.send(
                    200,
                    "application/json",
                    "{\"message\":\"API Online\"}"); });

    server.on("/gate", HTTP_GET, [this]()
              { server.send(
                    200,
                    "application/json",
                    "{\"success\":true}"); });

    server.on("/gate/open", HTTP_GET, [this]()
              { 
        ledController.setOpen(true);
        // play success melody
        buzzerController.play(SUCCESS_NOTES, SUCCESS_NOTES_LEN);
        server.send(
            200,
            "application/json",
            "{\"success\":true}"); });

    server.on("/gate/close", HTTP_GET, [this]()
              { 
                                ledController.setOpen(false);
                                // play failure melody
                                buzzerController.play(FAILURE_NOTES, FAILURE_NOTES_LEN);
                                server.send(
                                        200,
                                        "application/json",
                                        "{\"success\":true}"); });

    server.on("/gate", HTTP_POST, [this]()
              {

        String body = "";

        if (server.hasArg("plain")) {
            body = server.arg("plain");
        }

        if (body.length() == 0) {
            server.send(400, "application/json", "{\"error\":\"empty body\"}");
            return;
        }

        DynamicJsonDocument doc(1024);
        DeserializationError err = deserializeJson(doc, body); 

        if (err) {
            server.send(400, "application/json", "{\"error\":\"invalid json\"}");
            return;
        }

        serializeJsonPretty(doc, Serial);
        Serial.println();

        if (doc.containsKey("open")) {
            bool open = doc["open"];
            ledController.setOpen(open);
            if (open) {
                buzzerController.play(SUCCESS_NOTES, SUCCESS_NOTES_LEN);
            } else {
                buzzerController.play(FAILURE_NOTES, FAILURE_NOTES_LEN);
            }
        }

        String response = "{";
        response += "\"success\":true,";
        response += "\"data\":";
        response += body;
        response += "}";

        server.send(200, "application/json", response); });

    server.on("/status", HTTP_GET, [this]()
              {

        String json = "{";
        json += "\"led\":\"";
        json += ledController.status() ? "on" : "off";
        json += "\",";
        json += "\"ip\":\"";
        json += WiFi.localIP().toString();
        json += "\"";
        json += "}";

        server.send(
            200,
            "application/json",
            json
        ); });
}