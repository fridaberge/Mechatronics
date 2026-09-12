/*
  Precode for IN1080 - Assignment 1

  https://www.uio.no/studier/emner/matnat/ifi/IN1080/ 
*/

char inputValue; // Data received from the serial port

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT); // Set pin as OUTPUT
  Serial.begin(9600); // Start serial communication at 9600 bps

}

void loop() {
   if (Serial.available()) 
   { // If data is available to read,
    inputValue = Serial.read(); // read it and store it in val

    if (inputValue == '1') 
    { // If 1 was received
      Serial.print("1"); //printer 1 siden lyset er på
      digitalWrite(LED_BUILTIN, HIGH); //setter lyset på nå rman klikekr
    } 

    else if()
    
    inputValue = '0';
    digitalWrite(LED_BUILTIN, LOW); //skrur av lyset etter man har klikket
    Serial.print("\n0"); //printer ut 0 siden lsyet er av
   }

   delay(10); // Wait 10 milliseconds for next reading
}
