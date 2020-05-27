#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager
#include <ESP8266HTTPUpdateServer.h>
#include <ESP8266WebServer.h>
ESP8266HTTPUpdateServer httpUpdater;
ESP8266WebServer httpServer(80);

WiFiUDP udp;
const char *ssidu = "SmartFarmOTA555";
const char *passu = "password";
unsigned int localPort = 2000; // local port to listen for UDP packets
IPAddress ServerIP(0, 0, 0, 0);
IPAddress ClientIP(192, 168, 4, 2);
const char* update_path = "/firmware";
const char* update_username = "admin";
const char* update_password = "admin";

void udp_connect(){
  WiFi.softAP(ssidu, passu);    //Create Access point
  IPAddress myIP = WiFi.softAPIP(); delay(1000);
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  //Start UDP
  Serial.println("Starting UDP");
  udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(udp.localPort());
  httpUpdater.setup(&httpServer, update_path,update_username,update_password);
  httpServer.begin();
}
void wifi_manager(){
  WiFiManager wifiManager;
  wifiManager.autoConnect("SmartFarm1");
  Serial.println("connected...SmartHome1 :)");
}
