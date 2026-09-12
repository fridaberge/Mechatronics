//Oblig 5 oppgave 2
//Samarbeid mellom: oscarab, fridatbe, eskilgh

#include <Wire.h>

bool paa = false;

void setup() {
  Wire.begin(8);
  Wire.onReceive(r);
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  delay(1000);
}

void r(){

  int signal = Wire.read();

    Serial.print("Slave 2 Fikk signal:");
    Serial.print(signal);
    Serial.print("\n");

    if (paa){
      digitalWrite(LED_BUILTIN, LOW);
      paa = !paa;
    }else{
      digitalWrite(LED_BUILTIN, HIGH);
      paa = !paa;
    }
}