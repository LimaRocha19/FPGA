int TX = 2;
const byte clk = 3;
int right = 4;
int wrong = 5;
bool mustRead = false;

void setup() {
  Serial.begin(9600);
  Serial.flush();
  pinMode(TX, INPUT);
  pinMode(clk, INPUT_PULLUP);
  pinMode(right, OUTPUT);
  pinMode(wrong, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(clk), bordered, RISING);
}

void loop() {
  if(mustRead) {
    int tx = digitalRead(TX);
    if(tx == HIGH) {
      Serial.print("Acertooooooooou miserávi\n");
      digitalWrite(wrong, HIGH);
      digitalWrite(right, LOW);
      delay(500);
      digitalWrite(wrong, LOW);
      mustRead = false;
    } else {
      Serial.print("Errroooooou\n");
      digitalWrite(wrong, LOW);
      digitalWrite(right, HIGH);
      delay(500);
      digitalWrite(right, LOW);
      mustRead = false;
    }
  }
}

void bordered() {
  mustRead = true;
  Serial.print("CLOCKED\n");
}

