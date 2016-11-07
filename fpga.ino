// sinais do FPGA
int TX = 2;
const byte clk = 3;

// saidas de audio
int audio = 8;

// variaveis auxiliares
int jogadas = 0;
int acertos = 0;
int erros = 0;
bool dobradinhas = 0;

bool mustRead = false;

void setup() {
  Serial.begin(9600);
  Serial.flush();
  Serial.print("Bem-vindo ao jogo de Cara ou Coroa mais legal de todos os tempos\n");
  pinMode(TX, INPUT);
  pinMode(clk, INPUT_PULLUP);
  pinMode(audio, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(clk), bordered, FALLING);
}

void loop() {
  if(mustRead) {
    int tx = digitalRead(TX);
    if(tx == LOW) {
      Serial.print("Errroooooooooou\n");
      erros++;
      Serial.print(acertos);
      Serial.print(" acertos e ");
      Serial.print(erros);
      Serial.print(" erros\n");
      tone(audio, 300, 1000);
      mustRead = false;
    } else {
      Serial.print("Acertooooooooou miseravi\n");
      acertos++;
      Serial.print(acertos);
      Serial.print(" acertos e ");
      Serial.print(erros);
      Serial.print(" erros\n");
      tone(audio, 1500, 200);
      delay(50);
      tone(audio, 1500, 200);
      delay(50);
      tone(audio, 1500, 200);
      delay(50);
      mustRead = false;
    }
  }
}

void bordered() {
  if(dobradinhas) {
    mustRead = true;
    dobradinhas = !dobradinhas;
  } else {
    mustRead = false;
    dobradinhas = !dobradinhas;
  }
}

