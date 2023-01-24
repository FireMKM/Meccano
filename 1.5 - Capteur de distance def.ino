int led1 = 6;
int capteur = 4;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(capteur, INPUT);
}

void loop()
{
  int d = lire_distance(capteur);
  digitalWrite(led1, d < 40);
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
