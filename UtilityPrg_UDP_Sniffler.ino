#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

// WLAN-Konfiguration
const char* ssid = "....";          // Ersetze mit deinem WLAN-Namen
const char* password = "....";      // Ersetze mit deinem WLAN-Passwort

// UDP-Konfiguration
WiFiUDP Udp;
unsigned int localUdpPort = 1555; // Lokaler Port zum Empfang von UDP-Paketen
char incomingPacket[255];         // Puffer für eingehende Pakete

/////////////////////SETUP/////////////////////////////////
void setup() 
{
  Serial.begin(9600);
  Serial.println();
  Serial.print("Programmdatei: ");
  Serial.println(__FILE__);
  Serial.print("Kompiliert am: ");
  Serial.print(__DATE__);
  Serial.print(" um ");
  Serial.println(__TIME__);
  // WLAN verbinden
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.println("Verbinde mit WLAN...");
  }
  Serial.println("WLAN verbunden!");
  Serial.print("IP-Adresse: ");
  Serial.println(WiFi.localIP());

  // Starte UDP
  Udp.begin(localUdpPort);
  Serial.printf("Hör auf UDP-Port %d\n", localUdpPort);
}

/////////////////////////////////////LOOP///////////////////////////////////////////////////
void loop() 
{
  checkForUdpPackets(); // Ruf die Funktion auf
}
