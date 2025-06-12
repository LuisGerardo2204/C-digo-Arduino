/*
Este programa permite la lectura de un canal convertidor analógico-digital (ADC)
de una tarjeta Arduino, basada en el ejemplo incluido en la IDE oficial Arduino
*/

//Inicialización general
void setup() {
  // Inicialización del puerto serie por defecto a 115200 bauds
  Serial.begin(115200);
}

// Lazo de ejecución constante
void loop() {
  // Lectura del canal analógico 0
  int lectura = analogRead(A0);
  // Se convierte la lectura digital a su equivalente analógico 
  //float voltaje = lectura * (3.0 / 1024.0); //Descomentar esta línea para
  //tarjetas arduino de 8 bits: arduino UNO, Mega, Nano, leonardo, micro
  float voltaje = lectura * (3.0 / 4096.0); // Usar esta línea en tarjetas de 32 bits 
  // y 12 bits de resolución ESP32, Arduino Due, arduino basado en SAMD21
  // Se imprime el voltaje analógico obtenido en el puerto serie
  Serial.println(voltaje);
}
