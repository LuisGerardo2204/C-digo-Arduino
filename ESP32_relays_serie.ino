//Progrma para el encendido y apagado de 4 leds o relevadores con ESP32 y protocolo Serial


//Defición de las terminales de los pines que activarán los relays
#define RELAY0 19
#define RELAY1 18
#define RELAY2 5
#define RELAY3 17


void setup() {
  pinMode(RELAY0, OUTPUT);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  delay(10);      
  digitalWrite(RELAY0, LOW); 
  digitalWrite(RELAY1, LOW); 
  digitalWrite(RELAY2, LOW); 
  digitalWrite(RELAY3, LOW); 
   //
  // Inicializa serial a 115200 bauds
  //
  Serial.begin(115200);
  //
}
    
void loop() {
 if (Serial.available() > 0) {
   int comando = Serial.read();
    Serial.println(comando);
    if (comando == 65) {
        digitalWrite(RELAY0,HIGH);
      } else if (comando == 66) {
        digitalWrite(RELAY0,LOW);
      } else if (comando == 67) {
        digitalWrite(RELAY1,HIGH);
      }else if (comando == 68) {
        digitalWrite(RELAY1,LOW);
      }else if (comando == 69) {
        digitalWrite(RELAY2,HIGH);
      }else if (comando == 70) {
        digitalWrite(RELAY2,LOW);
      }else if (comando == 71) {
        digitalWrite(RELAY3,HIGH);
      }else if (comando == 72) {
        digitalWrite(RELAY3,LOW);
      }else if (comando == 73) {
        digitalWrite(RELAY0,HIGH);
        digitalWrite(RELAY1,HIGH);
        digitalWrite(RELAY2,HIGH);
        digitalWrite(RELAY3,HIGH);  
      }else if (comando == 74) {
        digitalWrite(RELAY0,LOW);
        digitalWrite(RELAY1,LOW);
        digitalWrite(RELAY2,LOW);
        digitalWrite(RELAY3,LOW);  
      }
 }
}