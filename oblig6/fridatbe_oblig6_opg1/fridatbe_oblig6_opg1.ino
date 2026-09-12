int potentiometer = A5;
int enable = 10;
int periode = 100; //1/0.01 sek = 100Hz -> 1000000/10000 = 100 Hz

void setup() {
  pinMode(potentiometer, INPUT);
  pinMode(enable, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
  Serial.begin(2400);
}

void loop() {
  float val = analogRead(potentiometer);
  float mappedVal = map(val, 0, 1023, 0, 100);
  float onPeriod = mappedVal/100;
  if(micros() % periode < onPeriod*periode){
    digitalWrite(enable, HIGH);
  }
  else if(micros() % periode <= periode){
    digitalWrite(enable, LOW);
  }
}
