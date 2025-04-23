int sensorLuz = A0;
int ledAzul = 2;

int sensorSom = 13;
int ledAlarme1 = 8;
int ledAlarme2 = 9;
int botao = 10;

int luz;
int som;
int estadoBotao;

void setup() {
  Serial.begin(9600);
  pinMode(sensorLuz, INPUT);
  pinMode(ledAzul, OUTPUT);

  pinMode(ledAlarme1, OUTPUT);
  pinMode(ledAlarme2, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  pinMode(sensorSom, INPUT);

  digitalWrite(ledAlarme1, LOW);
  digitalWrite(ledAlarme2, LOW);
}

void loop() {
  luz = analogRead(sensorLuz);
  Serial.println(luz);

  if (luz > 500) {
    digitalWrite(ledAzul, HIGH);
  } else {
    digitalWrite(ledAzul, LOW);
  }

  estadoBotao = digitalRead(botao);
  som = digitalRead(sensorSom);
  if (!som) {
    for (int cont = 0; cont <= 20; cont++) {
      digitalWrite(ledAlarme1, HIGH);
      digitalWrite(ledAlarme2, LOW);
      delay(100);
      digitalWrite(ledAlarme1, LOW);
      digitalWrite(ledAlarme2, HIGH);
      delay(100);
    }
    digitalWrite(ledAlarme1, HIGH);
    digitalWrite(ledAlarme2, HIGH);
  }
  if (estadoBotao == LOW) {
    digitalWrite(ledAlarme1, LOW);
    digitalWrite(ledAlarme2, LOW);
  }
}
