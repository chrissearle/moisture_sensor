#include <Arduino.h>

#include <PubSubClient.h>

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#else
#include <WiFi.h>
#include <WebServer.h>
#endif

#include <DNSServer.h>
#include <WiFiManager.h>

#include "Board.h"
#include "Sensor.h"

Board *board;

WiFiClient wifiClient;

long lastMsg = 0;

void setup()
{
  Serial.begin(115200);

  WiFiManager wifiManager;

  wifiManager.autoConnect("AutoConnectAP");

  board = new Board("Test", wifiClient);
  board->addSensor(new Sensor("TestSensor", 34));
}

void loop()
{
  board->keepAlive();

  long now = millis();

  if (now - lastMsg > (60 * 1000))
  {
    lastMsg = now;
    board->publish();
  }
}