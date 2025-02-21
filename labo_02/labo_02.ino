unsigned long currentTime = 0;

void setup() {
  Serial.begin(9600);

  // Ton code ici



  Serial.println("Setup completed");
}

void loop() {const int pinBouton = 2;
const int brochesDel[] = {8, 9, 10, 11};
const int brochePotentiometre = A1;
const unsigned long tempsAntiRebond = 50;

bool etatPrecedent = HIGH;
unsigned long dernierTempsPression = 0;

void setup() {
    Serial.begin(9600);
    pinMode(pinBouton, INPUT_PULLUP);
    for (int i = 0; i < 4; i++) {
        pinMode(brochesDel[i], OUTPUT);
    }
}

void loop() {
    int valeur = map(analogRead(brochePotentiometre), 0, 1023, 0, 20);
    

    // Si le bouton est appuyé, afficher la barre de progression
    if (digitalRead(pinBouton) == LOW && etatPrecedent == HIGH && millis() - dernierTempsPression > tempsAntiRebond) {
        afficherProgression(valeur);
        dernierTempsPression = millis();
    }
    etatPrecedent = digitalRead(pinBouton);
}

void afficherProgression(int valeur) {
    int pourcentage = map(valeur, 0, 20, 0, 100);
    Serial.print(pourcentage);
    Serial.print("% [");

    for (int i = 0; i < 20; i++) {
        if (i < pourcentage / 5) {  
            Serial.print("@");  
        } else {
            Serial.print(".");  
        }
    }
    
    Serial.println("]");
}



  currentTime = millis();

}
