#include <Servo.h>

Servo myservo;
int value;
int transistor = A0;

void setup() {
  myservo.attach(9);
}

void loop() {
  value = analogRead(transistor); //måler lystransistoren sin styrke
  value = map(value, 0, 1023, 0, 180); //skalerer så laveste verdi er 0 og høyeste 180
  myservo.write(value); //setter servo-posisjonen etter skaleringen (i grader)
  delay(100);
}
