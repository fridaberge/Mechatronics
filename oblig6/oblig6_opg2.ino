// some useful consts
const int DUTY_MAX = 255;
const int ENCODER_MAX = 1024;
const int SLACK = 15;

// TODO: define pins as consts
int reference = A5;
int encoder = A0;
int enable = 10;

// some useful variables
double errorSum = 0;
double errorLast = 0;

// TODO: define other relevant variable(s)
int periode = 100;

// Default PID gains
double Kp = 1.0;
double Ki = 0.00;
double Kd = 0.0;

void setup() {
  // TODO: set up pins here
  pinMode(10, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(reference, INPUT);
  pinMode(encoder, INPUT);
  

  Serial.begin(9600); // start the serial connection
}

void loop() {
  readPidGainsFromProcessing(); // read PID gains from Processing

  // TODO: read target position from the reference potentiometer
  int targetPos = analogRead(reference); // REPLACE
  // Serial.println("targetpos:");
  // Serial.println(targetPos);
  // TODO: read motor position from the "encoder" potentiometer
  int motorPos = analogRead(encoder); // REPLACE
  // Serial.println("motorpos");
  // Serial.println(motorPos);
 
  motorController(targetPos, motorPos);
}

// Function to read the PID gains from the Processing code
void readPidGainsFromProcessing() {
  if (Serial.available()) {
    String inputValue = Serial.readString();
    char type = inputValue.charAt(0);
    double gain = inputValue.substring(inputValue.indexOf(' '), inputValue.length()).toDouble();
    switch (type) {
      case 'p': 
        Kp = gain;
        break;
      case 'i':
        Ki = gain;
        errorSum = 0;
        break;
      case 'd':
        Kd = gain;
        break;
    }
  }
}

// Function that implements motor control
void motorController(int targetPos, int currentPos) {

  double error = targetPos - currentPos;

  // if error is less than the encoder slack, do not actuate the motor
  if(error < SLACK && error > 0 - SLACK){
    pwm(0);
    errorSum = 0;
    return;
  }
  
  // TODO: update errorSum
  errorSum += error; // REPLACE

  double command = pidController(Kp, Ki, Kd, error, errorSum, errorLast); // call PID controller

  // integrator anti-windup (do not accumulate sum of errors when output is saturated)
  if(command > ENCODER_MAX){
    command = ENCODER_MAX;
    errorSum = errorSum - error;
  } else if(command < -ENCODER_MAX){
    command = -ENCODER_MAX;
    errorSum = errorSum - error;
  }

  int dutyCycle = map(command, -ENCODER_MAX, ENCODER_MAX, -DUTY_MAX, DUTY_MAX); // map command to duty cycle

  pwm(dutyCycle);

  // TODO: update errorLast
  errorLast = error; // REPLACE
}

// Function that implements a PID controller
double pidController(double Kp, double Ki, double Kd, double error, double errorSum, double errorLast) {
  double P = Kp * error;
  double I = Ki * errorSum;
  double D = Kd * errorLast;
  double out = P + I + D;
  // TODO: implement the PID controller using the variables Kp, Ki, Kd, error, errorSum and errorLast
  //       hint 1: the integral component operates on the sum of errors (errorSum)
  //       hint 2: the derivative component operates on the error from the previous loop (errorLast)
  return out; // REPLACE
}
int duty;
unsigned long previous_time = micros();
// Function that implements PWM
void pwm(double dutyCycle){
  Serial.println(dutyCycle);

  if(dutyCycle > 0){ //negativ er mot klokka
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
  }
  else if (dutyCycle < 0) {
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
  }

  unsigned long mappedVal = map(abs(dutyCycle), 0, DUTY_MAX, 0, 100);
  unsigned long onPeriod = mappedVal/100;
  if(micros() % periode < onPeriod*periode){
    digitalWrite(10, HIGH);
  }
  else if(micros() % periode <= periode){
    digitalWrite(10, LOW);
  }
}