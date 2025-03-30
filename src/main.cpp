#include <Arduino.h>

#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

void handle_root() {
  String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'><title>Modo AP</title></head><body>";
  html += "<h1>🛜 ESP32 en modo Access Point</h1>";
  html += "<p>Conectado a: <strong>" + WiFi.softAPSSID() + "</strong></p>";
  html += "<p>IP: " + WiFi.softAPIP().toString() + "</p>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  
  // Configuración como AP (¡sin necesidad de router!)
  WiFi.softAP("ESP32_AP", "password123");  // SSID + Contraseña
  
  Serial.println("\nRed creada:");
  Serial.print("SSID: "); Serial.println(WiFi.softAPSSID());
  Serial.print("IP: "); Serial.println(WiFi.softAPIP());
  
  server.on("/", handle_root);
  server.begin();
}

void loop() {
  server.handleClient();
}