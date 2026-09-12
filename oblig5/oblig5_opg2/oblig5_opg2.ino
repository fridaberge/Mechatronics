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
      Serial.print(""); //Insert your code in this block
    } 

    inputValue = '0';
   }

   delay(10); // Wait 10 milliseconds for next reading
}