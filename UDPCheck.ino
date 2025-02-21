
// Funktion zum Überprüfen von UDP-Paketen
void checkForUdpPackets() 
{
  int packetSize = Udp.parsePacket();
  if (packetSize) 
  {
    Serial.printf("Paket empfangen! Größe: %d Bytes\n", packetSize);
    int len = Udp.read(incomingPacket, 255);
    if (len > 0) 
    {
      incomingPacket[len] = 0; // Nullterminierung für den String
    }
    Serial.printf("Von IP: %s, Port: %d\n", Udp.remoteIP().toString().c_str(), Udp.remotePort());
    Serial.printf("Inhalt: %s\n", incomingPacket);
  }
}