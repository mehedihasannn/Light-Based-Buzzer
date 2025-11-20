# Light-Based-Buzzer

This repo contains a small Arduino project where a buzzer changes its buzzing speed depending on how much light falls on an LDR. I made this mainly to get comfortable with analog signals, mapping values, and controlling outputs in a simple way.

## What this project does

* Reads light intensity from an LDR connected to **A0**
* Converts the reading into a delay value
* The buzzer on **pin 8** buzzes faster in bright light and slower in low light

It’s a beginner-friendly project but gives a good idea of how sensors interact with hardware (IMO).

## Components Used

* Arduino Uno
* LDR (light-dependent resistor)
* 10kΩ resistor (for the LDR voltage divider)
* Buzzer
* Breadboard and jumper wires

## Circuit Idea

1. The LDR forms a voltage divider with the 10k resistor
2. Output goes to analog pin A0
3. Arduino reads the value and adjusts buzzer delay

## Code

```cpp
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
```


Free to use or modify :)
