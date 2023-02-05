int led1 = 6;
int led2 = 7;
int capteur = 4;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(capteur, INPUT);
}

void loop()
{
  int d = lire_distance(capteur);
  digitalWrite(led1, d < 10);
  digitalWrite(led2, d < 20);
}

int lire_distance(int numero_broche) {
  pinMode(numero_broche, OUTPUT);
  digitalWrite(numero_broche, LOW);
  delayMicroseconds(2);
  digitalWrite(numero_broche, HIGH);
  delayMicroseconds(10);
  digitalWrite(numero_broche, LOW);
  pinMode(numero_broche, INPUT);
  return 0.01723 * pulseIn(numero_broche, HIGH);
}
