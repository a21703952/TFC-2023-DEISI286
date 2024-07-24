const int pinoTMP = A0; // Pino analógico conectado ao TMP36

void setup() {
  Serial.begin(9600); // Inicialize a comunicação serial
  pinMode(12, OUTPUT);
}

void loop() {
  digitalWrite(12, LOW);
  // Leia o valor analógico do TMP36
  int valorSensor = analogRead(pinoTMP);

  // Converta o valor analógico em tensão (0-5V)
  float tensao = (valorSensor / 1024.0) * 5.0;

  // Converta a tensão em temperatura em graus Celsius
  float temperaturaC = (tensao - 0.5) * 100.0;

  // Converta a temperatura para Fahrenheit (opcional)
  float temperaturaF = (temperaturaC * 9.0 / 5.0) + 32.0;
  // Imprima os valores de temperatura no monitor serial
  // Converte o valor float para string com duas casas decimais (ajuste como necessário)

  // Envia a representação string pela serial
  Serial.println(temperaturaC);
  digitalWrite(12, HIGH);
  delay(1000); // Atraso de 1 segundo
}












