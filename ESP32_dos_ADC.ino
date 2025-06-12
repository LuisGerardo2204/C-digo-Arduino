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
  int lectura1 = analogRead(A0);
  // Lectura del canal analógico 3
  int lectura2 = analogRead(A3);
   // Se convierte la lectura digital a su equivalente analógico 
  //float voltaje1 = lectura1 * (3.0 / 1024.0); 
   //float voltaje2 = lectura2 * (3.0 / 1024.0); 
  //Descomentar estas líneas para
  //tarjetas arduino de 8 bits: arduino UNO, Mega, Nano, leonardo, micro
  float voltaje1 = lectura1 * (3.0 / 4096.0);
  float voltaje2 = lectura2 * (3.0 / 4096.0);
  
  Serial.print(voltaje1);
  Serial.print(",");
  Serial.println(voltaje2);
}
