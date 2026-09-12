/**
 * Oblig 5 oppgave 2
 * Samarbeid mellom: oscarab, fridatbe, eskilgh
 */

#include <Wire.h>
int i = 0;
int port = 7;

void setup() {
  Wire.begin();       
  Serial.begin(9600);  
}

void loop() {
  if (Serial.available()) {
    if (Serial.read() == '1') {
      i++;
      if (i % 2 == 0) {
        port = 8;     
      }
      if (i % 4 == 1) {
        Serial.print(i);
        Serial.print(". klikk: LED for Slave 1 slaas paa");
      } else if (i % 4 == 2) {
        Serial.print(i);
        Serial.print(". klikk: LED for Slave 2 slaas paa");
      } else if (i % 4 == 3) {
        Serial.print(i);
        Serial.print(". klikk: LED for Slave 1 slaas av");
      } else {
        Serial.print(i);
        Serial.print(". klikk: LED for Slave 2 slaas av");
      }
    }

    Wire.beginTransmission(port);  
    Wire.write(i);            
    Wire.endTransmission();    
    delay(500);      
    port = 7;           
  }
}
