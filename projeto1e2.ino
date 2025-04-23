int sensorLuz = A0;
int ledAzul = 2;

int sensorSom = 13;
int ledAlarme1 = 8;
int ledAlarme2 = 9;

int luz;
int som;

void setup() {
  Serial.begin(9600);
  pinMode(sensorLuz, INPUT);
  pinMode(ledAzul, OUTPUT);

  pinMode(ledAlarme1, OUTPUT);
  pinMode(ledAlarme2, OUTPUT);
  pinMode(sensorSom, INPUT);
}

void loop() {
  luz = analogRead(sensorLuz);
  Serial.println(luz);

  if (luz > 500) {
    digitalWrite(ledAzul, HIGH);
  } else {
    digitalWrite(ledAzul, LOW);
  }

  som = digitalRead(sensorSom);
  if (!som) {
    digitalWrite(ledAlarme1, HIGH);
    digitalWrite(ledAlarme2, LOW);
    delay(100);
    digitalWrite(ledAlarme1, LOW);
    digitalWrite(ledAlarme2, HIGH);
    delay(100);
  } else {
    digitalWrite(ledAlarme1, LOW);
    digitalWrite(ledAlarme2, LOW);
  }

}
