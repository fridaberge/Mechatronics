#include <Wire.h>

/*
 oblig 5 oppagve 2
 brukernavn: fridatbe, eskilgh, oscarab
*/

bool paa = false;

void setup() {
  Wire.begin(7);
  Wire.onReceive(r);
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  delay(1000);
}

void r(){
  int signal = Wire.read();
    Serial.print("Slave 1 fikk signal: ");
    Serial.print(signal);
    Serial.print("\n");

    if(paa){
      digitalWrite(LED_BUILTIN, LOW);
      paa = !paa;
    }
    else{
      digitalWrite(LED_BUILTIN, HIGH);
      paa = !paa;
    }


}
