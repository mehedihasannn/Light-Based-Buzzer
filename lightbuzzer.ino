int lightpin = A0;
int buzzpin = 8;
float lightval;
float dt;

void setup() {
  pinMode(lightpin, INPUT);
  pinMode(buzzpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightval = analogRead(lightpin);
  Serial.println(lightval);

  // Convert light value (200–550) to a delay of 10–1 ms
  dt = map(lightval, 200, 550, 10, 1);
  dt = constrain(dt, 1, 10);

  Serial.println(dt);

  digitalWrite(buzzpin, HIGH);
  delay(dt);
  digitalWrite(buzzpin, LOW);
  delay(dt);
}