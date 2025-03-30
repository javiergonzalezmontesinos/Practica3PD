#include <Arduino.h>

#include <WiFi.h>
#include <WebServer.h>

// SSID & Password
const char* ssid = "Oneplus";  // Enter your SSID here
const char* password = "159635741ja";  // Enter your Password here

WebServer server(80);  // Object of WebServer(HTTP port, 80 is default)

// Declaración de la función handle_root
void handle_root();

void setup() {
    Serial.begin(115200);
    Serial.println("Try Connecting to ");
    Serial.println(ssid);

    // Connect to your wi-fi modem
    WiFi.begin(ssid, password);

    // Check wi-fi is connected to wi-fi network
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected successfully");
    Serial.print("Got IP: ");
    Serial.println(WiFi.localIP());  // Show ESP32 IP on serial

    server.on("/", handle_root);

    server.begin();
    Serial.println("HTTP server started");
    delay(100);
}

void loop() {
    server.handleClient();
}

// HTML & CSS contents which display on web server
String HTML = R"=====(
  <!DOCTYPE html>
  <html>
  <head>
      <meta charset='UTF-8'>
      <title>Mi Página con ESP32</title>
  </head>
  <body>
      <h1>Mi Primera Página con ESP32 - Station Mode 😊</h1>
      <p>¡Hola! Esta es mi primera página web generada con una ESP32.</p>
      <h2>Características</h2>
      <ul>
          <li>Conexión WiFi.</li>
          <li>Servidor web integrado.</li>
          <li>Compatible con emojis 😊.</li>
      </ul>
      <h2>Cómo funciona</h2>
      <ol>
          <li>La ESP32 se conecta a una red WiFi.</li>
          <li>Crea un servidor web.</li>
          <li>Muestra esta página cuando accedes a su IP.</li>
      </ol>
  </body>
  </html>
  )=====";

// Implementación de la función handle_root
void handle_root() {
    server.send(200, "text/html", HTML);
}