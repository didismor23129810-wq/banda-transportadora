#define DIR 2
#define STEP 3
#define ENABLE 4
#define JOYSTICK A0

int zonaMuertaMin = 400;
int zonaMuertaMax = 624;

void setup() {
  pinMode(DIR, OUTPUT);
  pinMode(STEP, OUTPUT);
  pinMode(ENABLE, OUTPUT);
  digitalWrite(ENABLE, HIGH); // Motor deshabilitado
}

void loop() {
  int lectura = analogRead(JOYSTICK);

  if (lectura < zonaMuertaMin) {
    digitalWrite(ENABLE, LOW);
    digitalWrite(DIR, LOW);
    moverMotor(map(lectura, 0, zonaMuertaMin, 800, 200));
  } 
  else if (lectura > zonaMuertaMax) {
    digitalWrite(ENABLE, LOW);
    digitalWrite(DIR, HIGH);
    moverMotor(map(lectura, zonaMuertaMax, 1023, 200, 800));
  } 
  else {
    digitalWrite(ENABLE, HIGH);
  }
}

void moverMotor(int delayMicros) {
  digitalWrite(STEP, HIGH);
  delayMicroseconds(delayMicros);
  digitalWrite(STEP, LOW);
  delayMicroseconds(delayMicros);
}
