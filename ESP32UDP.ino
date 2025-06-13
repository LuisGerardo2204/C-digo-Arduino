//Progrma para el encendido y apagado de 4 leds o relevadores con ESP32 y protocolo UDP
// Basado en el código:
// hello.ESP32-WROOM.UDP.ino
//
// ESP32 UDP hello-world
//
// Neil Gershenfeld 11/16/19
//
// This work may be reproduced, modified, distributed,
// performed, and displayed for any purpose, but must
// acknowledge this project. Copyright is retained and
// must be preserved. The work is provided as is; no
// warranty is provided, and users accept all liability.
//

#include "WiFi.h"
#include "AsyncUDP.h"

const char* ssid = "  "; // Usar SSID de la red local
const char* password = "  "; // Usar el password de la red

#define RELAY0_PIN 19
#define RELAY1_PIN 18
#define RELAY2_PIN 5
#define RELAY3_PIN 17

AsyncUDP udp;

void setup() {

  pinMode(RELAY0_PIN, OUTPUT);
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  pinMode(RELAY3_PIN, OUTPUT);
  delay(10);      
  digitalWrite(RELAY0_PIN, LOW); 
  digitalWrite(RELAY1_PIN, LOW); 
  digitalWrite(RELAY2_PIN, LOW); 
  digitalWrite(RELAY3_PIN, LOW); 

  
  //
  // Inicializa serial a 115200 bauds
  //
  Serial.begin(115200);
  //
  // Conectar a WIFI
  //
  Serial.print("\nConnecting ");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
    }
  Serial.print("\nConnected with local address ");
  Serial.print(WiFi.localIP());
  Serial.print("\n");
 
if (udp.listen(2020)) {
    Serial.print("UDP Listening on IP: ");
    Serial.println(WiFi.localIP());
    udp.onPacket([](AsyncUDPPacket packet) {
      Serial.print("Tipo de mensaje UDP: ");
      Serial.print(packet.isBroadcast() ? "Broadcast" : packet.isMulticast() ? "Multicast" : "Unicast");
      Serial.print(", De: ");
      Serial.print(packet.remoteIP());
      Serial.print(":");
      Serial.print(packet.remotePort());
      Serial.print(", Para: ");
      Serial.print(packet.localIP());
      Serial.print(":");
      Serial.print(packet.localPort());
      Serial.print(", Length: ");
      Serial.print(packet.length());
      Serial.print(", Datos: ");
      Serial.write(packet.data(), packet.length());
      Serial.println();
      //Respuesta al cliente o conexión
      packet.printf("llegaron %u bytes de datos", packet.length());
      String myString = (const char*)packet.data();
      if (myString == "E1") {
        digitalWrite(RELAY0_PIN,HIGH);
      } else if (myString == "A1") {
        digitalWrite(RELAY0_PIN,LOW);
      } else if (myString == "E2") {
        digitalWrite(RELAY1_PIN,HIGH);
      }else if (myString == "A2") {
        digitalWrite(RELAY1_PIN,LOW);
      }else if (myString == "E3") {
        digitalWrite(RELAY2_PIN,HIGH);
      }else if (myString == "A3") {
        digitalWrite(RELAY2_PIN,LOW);
      }else if (myString == "E4") {
        digitalWrite(RELAY3_PIN,HIGH);
      }else if (myString == "A4") {
        digitalWrite(RELAY3_PIN,LOW);
      }else if (myString == "Et") {
        digitalWrite(RELAY0_PIN,HIGH);
        digitalWrite(RELAY1_PIN,HIGH);
        digitalWrite(RELAY2_PIN,HIGH);
        digitalWrite(RELAY3_PIN,HIGH);  
      }else if (myString == "At") {
        digitalWrite(RELAY0_PIN,LOW);
        digitalWrite(RELAY1_PIN,LOW);
        digitalWrite(RELAY2_PIN,LOW);
        digitalWrite(RELAY3_PIN,LOW);  
      }
    });
  }  
}
    
void loop() {
 
   delay(1000);

  udp.broadcast("Esperando instrucción...");

  }
