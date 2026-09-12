//fotgjenger
volatile int ButtonValue = 0;
int BUTTON = 2;
int BLUE_P = 3;
int GREEN_P = 4;
int RED_P = 5;
int SOUND = 10;
//bil
int GREEN_CAR = 11;
int YELLOW_CAR = 12;
int RED_CAR = 13;

void setup() {
  //bil
  pinMode(YELLOW_CAR, OUTPUT);
  pinMode(GREEN_CAR, OUTPUT);
  pinMode(RED_CAR, OUTPUT);
  //fotgjenger
  pinMode(BLUE_P, OUTPUT);
  pinMode(GREEN_P, OUTPUT);
  pinMode(RED_P, OUTPUT);
  pinMode(SOUND, OUTPUT);
  pinMode(BUTTON, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON), buttonPressed, RISING);
}

void loop() {
  if(ButtonValue != 0){
    pressed();
  }
  else{
    notPressed();
  }
}

void notPressed(){
  //hvis knappen ikke er trykket
  //bil har grønt så lenge ingen fotgjengere er der
  digitalWrite(GREEN_CAR, HIGH);
  digitalWrite(RED_CAR, LOW);
  digitalWrite(YELLOW_CAR, LOW);

  //fotgjenger må trykke på knapp for å få grønt
  digitalWrite(RED_P, HIGH);
  digitalWrite(BLUE_P, LOW);
  digitalWrite(GREEN_P, LOW);

  // lyden skal gå 0.5 sek på og 0.5 sek av
  tone(SOUND, 60);
  delay(500);
  noTone(SOUND);
  delay(500);
}

void pressed(){
  //hvis knappen er trykket
  //ventelyset skrur på (blå)
  digitalWrite(RED_P, LOW);
  digitalWrite(BLUE_P, HIGH);
  //billyset gåt til gult etter 2 sek
  delay(2000);
  digitalWrite(GREEN_CAR, LOW);
  digitalWrite(YELLOW_CAR, HIGH);
  //billyset går til rødt etter 1 sek med gult lys
  delay(1000);
  digitalWrite(YELLOW_CAR, LOW);
  digitalWrite(RED_CAR, HIGH);
  //grønnt for fotgjengere etter bilene har hatt rødt i 1 sek
  delay(1000);
  digitalWrite(BLUE_P, LOW);
  digitalWrite(GREEN_P, HIGH);
  //48*125 = 6000, 48/2 = 24
  //piezo lyd mens fotgjengerne har grønt
  int j = 24;
  while(j > 0){
    tone(SOUND, 200);
    delay(125);
    noTone(SOUND);
    delay(125);
    j--;
  }
  //grønn blink for fotgjenger de siste 3 sekundene
  int i = 3;
  while(i >0){
    digitalWrite(GREEN_P, LOW);
    delay(500);
    digitalWrite(GREEN_P, HIGH);
    delay(500);
    i--;
  }
  //bytter tilbake til at bilene kan kjøre igjen
  digitalWrite(GREEN_P, LOW);
  digitalWrite(RED_P, HIGH);
  digitalWrite(YELLOW_CAR, HIGH);
  delay(1000);
  ButtonValue = 0;
}

void buttonPressed(){
  // stopper fra å klikke etter det allerede er gjort (på vei til grønt)
  if(ButtonValue == 0){
    ButtonValue = 1;
  }
}