/*
* Arduino WakeUp
* Ricardo Dias
* Mark Young
*
* This sketch sends the "magic packet" to wake up
* a PC on Local Area Network when a push-button
* is pressed.
*/
#include <Ethernet.h>
#include <EthernetUdp.h>

EthernetUDP Udp;

//Please set the values first
int localPort = 5009;
IPAddress arduinoIp(192, 168, 1, 190);
IPAddress targetIp(192, 168, 1, 255);
byte arduinoMac[] = { 0xDE, 0xAD, 0xBE, 0x06, 0xFE, 0xED };
byte targetMac[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

void setup() {
  int i;
  Ethernet.begin(arduinoMac, arduinoIp);
  Udp.begin(localPort);
  delay(5000);
  for(i = 0; i < 5; i++) {
  sendPkt();
  delay(3000);
  }
}
void sendPkt(){
  byte data[102];
  int i, j, k=0;
  for(i = 0; i < 6; i++,k++){
  data[k] = 0xFF;
  }
  for(i = 0; i < 16; i++){
  for(j = 0; j < 6; j++, k++){
  data[k] = targetMac[j];
  }
  }
  Udp.beginPacket(targetIp, 5000);
  Udp.write(data, 102);
  Udp.endPacket();
}
void loop() {
  delay(10);
}
