// Définition des numéros de port
const int trigPin = 4;  // Trigger (emission)
const int echoPin = 5;  // Echo    (réception)

// Variables utiles
float duree;   // durée de l'echo
int dist; // distance


void setup() {
pinMode(trigPin, OUTPUT); // Configuration du port du Trigger comme une SORTIE
pinMode(echoPin, INPUT);  // Configuration du port de l'Echo  comme une ENTREE

Serial.begin(9600); // Démarrage de la communication série
}

void loop() {
  // Émission d'un signal de durée 10 microsecondes
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Écoute de l'écho 
  duree = pulseIn(echoPin, HIGH);

  // Calcul de la distance
  dist = duree*340/2;

  if (dist < 0.01) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
  }
  else {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
  }
}
