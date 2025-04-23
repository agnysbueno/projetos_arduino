#include <Ultrasonic.h>
Ultrasonic sensorDist(2,3);

int sensorUmidade = A0;
int buzzer = 11;

int motor = 7;

int nivel;
int distancia;

void setup() {
  Serial.begin(9600);
  pinMode(sensorUmidade, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  nivel = analogRead(sensorUmidade);
  Serial.println(nivel);

  if (nivel > 700) {
    tone(buzzer, 261);
  } else {
    noTone(buzzer);
  }

  distancia = sensorDist.read();
  if(distancia < 30){
    digitalWrite(motor, HIGH); 
  } else {
    digitalWrite(motor, LOW);
  }
}
