/* Pin des moteurs */
int MotM = 14;
int MotD = 15;

/* Pin des LED des boutons de la cabine */
int etage1 = 13;
int etage2 = 12;
int etage3 = 11;
int etage4 = 10;
int etage5 = 9;

/* Pin des boutons de la cabine */
int cab1 = 48;
int cab2 = 47;
int cab3 = 38;
int cab4 = 39;
int cab5 = 40;

/* Pin des detecteurs de cabine aux étages 1 à 5 */
int ledDetecEt1 = 53;
int ledDetecEt2 = 52;
int ledDetecEt3 = 51;
int ledDetecEt4 = 50;
int ledDetecEt5 = 49;
int ledUrgence = 46;

/* Pin des LED des boutons Poussoirs */
int ledEt1M = 29;
int ledEt2M = 28;
int ledEt3M = 27;
int ledEt4M = 26;

int ledEt2D = 22;
int ledEt3D = 23;
int ledEt4D = 24;
int ledEt5D = 25;

/* Pin des bits pour l'affichage 7 segments */
int bit0 = 5;
int bit1 = 4;
int bit2 = 3;

/* Pin des boutons poussoirs */
int BPEtage1M = 37;
int BPEtage2M = 36;
int BPEtage3M = 35;
int BPEtage4M = 34;

int BPEtage2D = 33;
int BPEtage3D = 32;
int BPEtage4D = 31;
int BPEtage5D = 30;

/* Pin des détecteurs des portes */
int porteEt1 = 45;
int porteEt2 = 44;
int porteEt3 = 43;
int porteEt4 = 42;
int porteEt5 = 41;

/* Booleen vrai si la cabine est à l'étage */
bool cabineEstAEtage1;
bool cabineEstAEtage2;
bool cabineEstAEtage3;
bool cabineEstAEtage4;
bool cabineEstAEtage5;

/* 
 *  Initialisation des différents pins,
 *  Si c'est un bouton, il sera initialisé en INPUT
 *  Si c'est un cpateur il sera initialisé en OUTPUT
 */
void setup() {
  pinMode(ledUrgence, INPUT);
  
  pinMode(MotM,OUTPUT);
  pinMode(MotD,OUTPUT);
  
  pinMode(etage1,OUTPUT);
  pinMode(etage2,OUTPUT);
  pinMode(etage3,OUTPUT);
  pinMode(etage4,OUTPUT);
  pinMode(etage5,OUTPUT);
  
  pinMode(cab1,INPUT);
  pinMode(cab2,INPUT);
  pinMode(cab3,INPUT);
  pinMode(cab4,INPUT);
  pinMode(cab5,INPUT);
  
  pinMode(ledEt1M,OUTPUT);
  pinMode(ledEt2M,OUTPUT);
  pinMode(ledEt3M,OUTPUT);
  pinMode(ledEt4M,OUTPUT);
  
  pinMode(ledEt2D,OUTPUT); 
  pinMode(ledEt3D,OUTPUT); 
  pinMode(ledEt4D,OUTPUT);
  pinMode(ledEt5D,OUTPUT);
  
  pinMode(ledDetecEt1,INPUT);
  pinMode(ledDetecEt2,INPUT);
  pinMode(ledDetecEt3,INPUT);
  pinMode(ledDetecEt4,INPUT);
  pinMode(ledDetecEt5,INPUT);
  
  pinMode(bit0,OUTPUT);
  pinMode(bit1,OUTPUT);
  pinMode(bit2,OUTPUT);

  pinMode(BPEtage1M,INPUT);
  pinMode(BPEtage2M,INPUT);
  pinMode(BPEtage3M,INPUT);
  pinMode(BPEtage4M,INPUT);
  
  pinMode(BPEtage2D,INPUT);
  pinMode(BPEtage3D,INPUT);
  pinMode(BPEtage4D,INPUT);
}
/*
 * Méthode arrêt d'urgence qui coupe tout.
 * Elle arrête les moteurs et annule le parcours prévu
 */
void arret_urgence() {
    digitalWrite(MotM,LOW);
    digitalWrite(MotD,LOW);
    digitalWrite(ledEt1M,LOW);
    digitalWrite(ledEt2M,LOW);
    digitalWrite(ledEt3M,LOW);
    digitalWrite(ledEt4M,LOW);
    digitalWrite(ledEt2D,LOW);
    digitalWrite(ledEt3D,LOW);
    digitalWrite(ledEt4D,LOW);
    digitalWrite(ledEt5D,LOW);
    digitalWrite(etage1,LOW);
    digitalWrite(etage2,LOW);
    digitalWrite(etage3,LOW);
    digitalWrite(etage4,LOW);
    digitalWrite(etage5,LOW);
}

/*
 * Pemet d'aller à l'étage 1 lorsqu'on appuie sur le bouton 1 dans la cabine
 */
void allerEtage1() {
  
  if(digitalRead(etage1) == HIGH){ // si le bouton cabine 1 est allumé 
      digitalWrite(MotD,HIGH);     // allumé le moteur pour descendre
  }
  if(digitalRead(ledDetecEt1) == HIGH){ // si on detecte la cabine à l'étage 1
      digitalWrite(MotD,LOW);           // on eteint le moteur
      digitalWrite(etage1,LOW);         // on eteint le led cabine 1
  }
}

/*
 * Pemet d'aller à l'étage 2 lorsqu'on appuie sur le bouton 2 dans la cabine
 */
void allerEtage2() {
  if(cabineEstAEtage3 || cabineEstAEtage4 || cabineEstAEtage5){ // si la cabine est à l'étage 3, 4 ou 5
    if(digitalRead(etage2) == HIGH){                            // si la led du bouton cabine 2 est allumé
        digitalWrite(MotD,HIGH);                                // on allume le moteur pour descendre
    }
  }else {
    if(digitalRead(etage2) == HIGH){                            // si la led du bouton cabine 2 est allumé
        digitalWrite(MotM,HIGH);                                // on allume le moteur pour monter
    }
  }
  if(digitalRead(ledDetecEt2) == HIGH){                         // si on detecte la cabine à l'étage 2
        digitalWrite(MotD,LOW);                                 // on eteint le moteur 
        digitalWrite(MotM,LOW);                                 
        digitalWrite(etage2,LOW);                               // on eteint la led du bouton cabine 2
    }
}

/*
 * Pemet d'aller à l'étage 3 lorsqu'on appuie sur le bouton 3 dans la cabine
 */
void allerEtage3() {
  if(cabineEstAEtage4 || cabineEstAEtage5){  // si l'ascenseur est à l'étage 4 ou 5
    if(digitalRead(etage3) == HIGH){         // si la led du bouton cabine 3 est allumé
        digitalWrite(MotD,HIGH);             // on allume le moteur pour descendre
    }
  }else{
    if(digitalRead(etage3) == HIGH){         // si la led du bouton cabine 3 est allumé
        digitalWrite(MotM,HIGH);             // on allume le moteur pour monter
    }
  }
  if(digitalRead(ledDetecEt3) == HIGH){      // si la cabine est detecté a l'étage 3
       digitalWrite(MotD,LOW);               // on eteint le moteur
       digitalWrite(MotM,LOW);
       digitalWrite(etage3,LOW);             //on eteint la led du bouton cabine 3
  }
}

/*
 * Pemet d'aller à l'étage 4 lorsqu'on appuie sur le bouton 4 dans la cabine
 */
void allerEtage4() {
  if(cabineEstAEtage1 || cabineEstAEtage2 || cabineEstAEtage3){  // si la cabine est à l'étage 1, 2 ou 3 
    if(digitalRead(etage4) == HIGH){                             // si la led de bouton cabine 4 est allumé
        digitalWrite(MotM,HIGH);                                 // on allume le moteur pour monter
    }
  }else {
    if(digitalRead(etage4) == HIGH){                             // si la led du bouton cabine 4 est allumé
        digitalWrite(MotD,HIGH);                                 // on allume le moteur pour descendre
    }
  }
  if(digitalRead(ledDetecEt4) == HIGH){                          // si la cabine est detecté à l'étage 4
        digitalWrite(MotD,LOW);                                  // on eteint les moteurs
        digitalWrite(MotM,LOW);
        digitalWrite(etage4,LOW);                                // on eteint la led cabine 4
    }
}

/*
 * Pemet d'aller à l'étage 5 lorsqu'on appuie sur le bouton 5 dans la cabine
 */
void allerEtage5() {
    if(digitalRead(etage5) == HIGH){          // si la led bouton cabine 5 est allumé
        digitalWrite(MotM,HIGH);              // on allume le moteur pour monter
    }
    if(digitalRead(ledDetecEt5) == HIGH){     // si la cabine est detecté à l'étage 5
        digitalWrite(MotM,LOW);               // on eteint le moteur
        digitalWrite(etage5,LOW);             // on eteint le bouton cabine 5
    }
}

/*
 * Appelle l'ascenseur à l'étage 1. En indiquant que l'on souhaite monter (pour les priotités)
 */
void monterDepuisEtage1(){
  if(cabineEstAEtage2 || cabineEstAEtage3 || cabineEstAEtage4 || cabineEstAEtage5){ // si la cabine n'est pas à l'étage 1
    if (digitalRead(ledEt1M) == HIGH){                                              // si la led palier 1 est allumé
        digitalWrite(MotD,HIGH);                                                    // on allume le moteur pour descendre
    }
  }
  if(digitalRead(ledDetecEt1) == HIGH){                                             // si la cabine est détecté a l'etage 1 
        digitalWrite(MotD,LOW);                                                     // on eteint le moteur
        digitalWrite(ledEt1M,LOW);                                                  // on eteint la led du palier 1
  }
}

/*
 * Appelle l'ascenseur à l'étage 2. En indiquant que l'on souhaite monter (pour les priotités)
 */
void monterDepuisEtage2(){
  if(cabineEstAEtage1){                     // si la cabine est à l'étage 1
    if (digitalRead(ledEt2M) == HIGH){      // si la led palier de l'étage 2 pour monter est allumé
        digitalWrite(MotM,HIGH);            // on allume le moteur pour monter
    }
  }else {
    if(digitalRead(ledEt2M) == HIGH){       // si la led palier de l'étage 2 pour monter est allumé
        digitalWrite(MotD,HIGH);            // on allume le moteur pour descendre
    }
  }
  if(digitalRead(ledDetecEt2) == HIGH){     // si la cabine est détecté à l'étage 2 
        digitalWrite(MotD,LOW);             // on eteint les moteurs
        digitalWrite(MotM,LOW);           
        digitalWrite(ledEt2M,LOW);          // on eteint la led palier de l'étage 2 pour monter
  }
}

/*
 * Appelle l'ascenseur à l'étage 3. En indiquant que l'on souhaite monter (pour les priotités)
 */
void monterDepuisEtage3() {
  if (digitalRead(ledEt3M) == HIGH) {                               // si la led palier de l'étage 3 pour monter est allumé
    if (cabineEstAEtage1 || cabineEstAEtage2 ||cabineEstAEtage3) {  // si la cabine est à l'étage 1, 2 ou 3
      digitalWrite(MotM,HIGH);                                      // on allume le moteur pour monter
    } else {                                                        // sinon
      if(digitalRead(ledEt3M) == HIGH){                             // si la led palier de l'étage 3 pour monter est allumé
        digitalWrite(MotD,HIGH);                                    // on allume le moteur pour descendre
      }
    }
  }

  if (digitalRead(ledDetecEt3) == HIGH) {        // si la cabine est détecté à l'étage 3
    digitalWrite(ledEt3M,LOW);                  // on eteint la led palier de l'étage 3 pour monter
    digitalWrite(MotM,LOW);                     // on eteint les moteurs
    digitalWrite(MotD,LOW);
  }
}

/*
 * Appelle l'ascenseur à l'étage 4. En indiquant que l'on souhaite monter (pour les priotités)
 */
void monterDepuisEtage4(){
  if(cabineEstAEtage1 || cabineEstAEtage2 || cabineEstAEtage3 || cabineEstAEtage4){     // si la cabine est à l'étage 1, 2, 3 ou 4
    if (digitalRead(ledEt4M) == HIGH){                                                  // si la led palier de l'étage 4 pour monter est allumé
        digitalWrite(MotM,HIGH);                                                        // on allume le moteur pour monter
    }
  }else {                                                                               // sinon
    if ( digitalRead(ledEt4M) == HIGH){                                                 // si la led palier de l'étage 4 pour monter est allumé
      digitalWrite(MotD,HIGH);                                                          // on allume le moteur pour descendre
    } 
  }
  if(digitalRead(ledDetecEt4) == HIGH ){                                                // si la cabine est détecté à l'étage 4
        digitalWrite(MotD,LOW);                                                         // on eteint les moteurs
        digitalWrite(MotM,LOW);
        digitalWrite(ledEt4M,LOW);                                                      // on eteint la led palier de l'étage 4 pour monter
  }
}

/*
 * Appelle l'ascenseur à l'étage 2. En indiquant que l'on souhaite descendre (pour les priotités)
 */
void descendreDepuisEtage2() {
  if(cabineEstAEtage1){                                   // si la cabine est à l'étage 1
    if(digitalRead(ledEt2D) == HIGH){                     // si la led palier de l'étage 2 pour descendre est allumé
        digitalWrite(MotM,HIGH);                          // on allume le moteur pour monter
    }
  }else {                                                 // sinon
    if (digitalRead(ledEt2D) == HIGH){                    // si la led palier de l'étage 2 pour descendre est allumé
        digitalWrite(MotD,HIGH);                          // on allume le moteur pour descendre
    }
  }
  if(digitalRead(ledDetecEt2) == HIGH){                   // si la cabine est détecté à l'étage 2
        digitalWrite(MotD,LOW);                           // on eteint les moteurs
        digitalWrite(MotM,LOW);
        digitalWrite(ledEt2D,LOW);                        // on eteint la led palier de l'étage 2 pour descendre
  }
}

/*
 * Appelle l'ascenseur à l'étage 3. En indiquant que l'on souhaite descendre (pour les priotités)
 */
void descendreDepuisEtage3() {
  if (digitalRead(ledEt3D) == HIGH) {                                   // si la led palier de l'étage 3 pour descendre est allumé
    if (cabineEstAEtage3 || cabineEstAEtage4 || cabineEstAEtage5) {     // si la cabine est à l'étage 3, 4 ou 5
      digitalWrite(MotD,HIGH);                                          // on allume le moteur pour descendre
    } else {                                                            // sinon
      if(digitalRead(ledEt3D) == HIGH){                                 // si la led palier de l'étage 3 pour descendre est allumé
       digitalWrite(MotM,HIGH);                                         // on allume le moteur pour monter
      }
    }
  }

  if (digitalRead(ledDetecEt3) == HIGH) {                               // si la cabine est détecté à l'étage 3
    digitalWrite(ledEt3D,LOW);                                          // on eteint la led palier de l'étage 3 pour descendre                               
    digitalWrite(MotM,LOW);                                             // on eteint les moteurs
    digitalWrite(MotD,LOW);
  }
}

/*
 * Appelle l'ascenseur à l'étage 4. En indiquant que l'on souhaite descendre (pour les priotités)
 */
void descendreDepuisEtage4() {
  if(cabineEstAEtage1 || cabineEstAEtage2 || cabineEstAEtage3){         // si la cabine est à l'étage 1, 2 ou 3
    if(digitalRead(ledEt4D) == HIGH){                                   // si la led palier de l'étage 4 pour descendre est allumé
        digitalWrite(MotM,HIGH);                                        // on allume le moteur pour monter
    }
  }else {                                                               // sinon
    if (digitalRead(ledEt4D) == HIGH){                                  // si la led palier de l'étage 4 pour descendre est allumé
        digitalWrite(MotD,HIGH);                                        // on allume le moteur pour descendre
    }
  }
  if(digitalRead(ledDetecEt4) == HIGH){                                 // si la cabine est détecté à l'étage 4
        digitalWrite(MotD,LOW);                                         // on eteint les moteurs
        digitalWrite(MotM,LOW);
        digitalWrite(ledEt4D,LOW);                                      // on eteint la led palier de l'étage 4 pour descendre
  }
}

/*
 * Appelle l'ascenseur à l'étage 5. En indiquant que l'on souhaite descendre (pour les priotités)
 */
void descendreDepuisEtage5() {
  if(cabineEstAEtage1 || cabineEstAEtage2 || cabineEstAEtage3 || cabineEstAEtage4){       // si la cabine est à l'étage 1, 2, 3 ou 4
    if (digitalRead(ledEt5D) == HIGH){                                                    // si la led palier de l'étage 5 pour descendre est allumé
        digitalWrite(MotM,HIGH);                                                          // on allume le moteur pour monter
    }   
  }
    if(digitalRead(ledDetecEt5) == HIGH){                                                 // si la cabine est détecté à l'étage 5
        digitalWrite(MotM,LOW);                                                           // on eteint le moteur
        digitalWrite(ledEt5D,LOW);                                                        // si la led palier de l'étage 5 pour descendre est allumé
  }
}
/*
 * Affiche sur l'afficheur 7 segments l'étage où se trouve la cabine. 
 * Prend en argument l'étage pour allumer ou éteindre les bits.
 * Par exemple : 1 en binaire = 0(bit2) 0(bit 1) 1(bit 0)
 */
void afficheurEtage(int numeroEtage){
  switch(numeroEtage){
    case 1 : digitalWrite(bit0,HIGH); // 001
             digitalWrite(bit1,LOW);
             digitalWrite(bit2,LOW);
             break;
    case 2 : digitalWrite(bit0,LOW);  // 010
             digitalWrite(bit1,HIGH);
             digitalWrite(bit2,LOW);
             break;
    case 3 : digitalWrite(bit0,HIGH); // 011
             digitalWrite(bit1,HIGH);
             digitalWrite(bit2,LOW);
             break;
    case 4 : digitalWrite(bit0,LOW); // 100
             digitalWrite(bit1,LOW);
             digitalWrite(bit2,HIGH);
             break;
    default : digitalWrite(bit0,HIGH); // 5 = 101
              digitalWrite(bit1,LOW);
              digitalWrite(bit2,HIGH);
              break;
  }
}
/*
 * Amène la cabine à un étage si cette dernière se trouve entre 2 étages lors d'un arrêt d'urgence
 */
void initialisation(){
   do{ 
      digitalWrite(MotD,HIGH); // On allume le moteur pour descendre
   }while (digitalRead(ledDetecEt5) != HIGH && digitalRead(ledDetecEt4) != HIGH && digitalRead(ledDetecEt3) != HIGH && digitalRead(ledDetecEt2) != HIGH && digitalRead(ledDetecEt1) != HIGH); // Tant qu'on est pas dans un étage, on boucle 
      digitalWrite(MotD,LOW); // Un étage a été trouvé donc on éteint le moteur
}

/*
 * Si une porte s'ouvre pendant le fonctionnement de la cabine, 
 * les moteurs s'éteignent sans pour autant effacer le parcours prévu
 */
void porte(){
    if(digitalRead(porteEt5) != HIGH || digitalRead(porteEt4) != HIGH || digitalRead(porteEt3) != HIGH || digitalRead(porteEt2) != HIGH || digitalRead(porteEt1) != HIGH){ // Si une porte s'ouvre pendant que l'ascenseur fonctionne
      digitalWrite(MotM,LOW); // on eteint les moteurs
      digitalWrite(MotD,LOW);
    }  
}

void loop(){
  
  cabineEstAEtage1 = (digitalRead(bit0) == HIGH && digitalRead(bit1) == LOW && digitalRead(bit2) == LOW);
  cabineEstAEtage2 = (digitalRead(bit0) == LOW && digitalRead(bit1) == HIGH && digitalRead(bit2) == LOW);
  cabineEstAEtage3 = (digitalRead(bit0) == HIGH && digitalRead(bit1) == HIGH && digitalRead(bit2) == LOW);
  cabineEstAEtage4 = (digitalRead(bit0) == LOW && digitalRead(bit1) == LOW && digitalRead(bit2) == HIGH);
  cabineEstAEtage5 = (digitalRead(bit0) == HIGH && digitalRead(bit1) == LOW && digitalRead(bit2) == HIGH);
  
  if(digitalRead(ledUrgence) == LOW){
    arret_urgence();
    initialisation();
  }else if(digitalRead(porteEt5) != HIGH || digitalRead(porteEt4) != HIGH || digitalRead(porteEt3) != HIGH || digitalRead(porteEt2) != HIGH || digitalRead(porteEt1) != HIGH){
    porte();
  }else {
    if(digitalRead(etage1)== HIGH){
      allerEtage1();
    }
    if(digitalRead(etage2)== HIGH){
      allerEtage2();
    }
    if(digitalRead(etage3)== HIGH){
      allerEtage3();
    }
    if(digitalRead(etage4)== HIGH){
      allerEtage4();
    }
    if(digitalRead(etage5)== HIGH){
      allerEtage5();
    }
  
  
  if((digitalRead(MotD) == LOW 
  && (digitalRead(ledEt2D) == LOW || digitalRead(ledEt3D) == LOW || digitalRead(ledEt4D) == LOW || digitalRead(ledEt5D) == LOW)) || digitalRead(MotM) == HIGH
  || (digitalRead(MotD) == HIGH
  && (digitalRead(ledEt2D) == LOW || digitalRead(ledEt3D) == LOW || digitalRead(ledEt4D) == LOW || digitalRead(ledEt5D) == LOW))){
  
    if(digitalRead(ledEt1M)== HIGH){
      monterDepuisEtage1();
    }
    if(digitalRead(ledEt2M)== HIGH && digitalRead(etage1) == LOW){
      monterDepuisEtage2();
    }
    if(digitalRead(ledEt3M)== HIGH && digitalRead(etage1) == LOW && digitalRead(etage2) == LOW){
      monterDepuisEtage3();
    }
    if(digitalRead(ledEt4M)== HIGH && digitalRead(etage1) == LOW && digitalRead(etage2) == LOW && digitalRead(etage3) == LOW){
      monterDepuisEtage4();
    }
   }

     if((digitalRead(MotM) == LOW 
  && (digitalRead(ledEt1M) == LOW || digitalRead(ledEt2M) == LOW || digitalRead(ledEt3M) == LOW || digitalRead(ledEt4M) == LOW)) || digitalRead(MotD) == HIGH
  || (digitalRead(MotM) == HIGH
  && (digitalRead(ledEt1M) == LOW || digitalRead(ledEt2M) == LOW || digitalRead(ledEt3M) == LOW || digitalRead(ledEt4M) == LOW))){
  
    if(digitalRead(ledEt5D)== HIGH){
      descendreDepuisEtage5();
    }
    if(digitalRead(ledEt4D)== HIGH && digitalRead(etage5) == LOW){
      descendreDepuisEtage4();
    }
    if(digitalRead(ledEt3D)== HIGH && digitalRead(etage5) == LOW && digitalRead(etage4) == LOW){
      descendreDepuisEtage3();
    }
    if(digitalRead(ledEt2D)== HIGH && digitalRead(etage5) == LOW && digitalRead(etage4) == LOW && digitalRead(etage3) == LOW){
      descendreDepuisEtage2();
    }
   }
  }
  
  if(digitalRead(ledDetecEt5) == HIGH){
    afficheurEtage(5);
  }else if(digitalRead(ledDetecEt4) == HIGH) {
    afficheurEtage(4);
  }else if(digitalRead(ledDetecEt3) == HIGH) {
    afficheurEtage(3);
  }else if(digitalRead(ledDetecEt2) == HIGH) {
    afficheurEtage(2);
  }else if(digitalRead(ledDetecEt1) == HIGH) {
    afficheurEtage(1);
  }
  if(digitalRead(cab1) == HIGH){
    digitalWrite(etage1,HIGH);
  }
  if(digitalRead(cab2) == HIGH){
    digitalWrite(etage2,HIGH);
  }
  if(digitalRead(cab3) == HIGH){
    digitalWrite(etage3,HIGH);
  }
  if(digitalRead(cab4) == HIGH){
    digitalWrite(etage4,HIGH);
  }
  if(digitalRead(cab5) == HIGH){
    digitalWrite(etage5,HIGH);
  }
  if(digitalRead(BPEtage1M) == HIGH){
    digitalWrite(ledEt1M,HIGH);
  }
  if(digitalRead(BPEtage2M) == HIGH){
    digitalWrite(ledEt2M,HIGH);
  }
  if(digitalRead(BPEtage3M) == HIGH){
    digitalWrite(ledEt3M,HIGH);
  }
  if(digitalRead(BPEtage4M) == HIGH){
    digitalWrite(ledEt4M,HIGH);
  }
  if(digitalRead(BPEtage2D) == HIGH){
    digitalWrite(ledEt2D,HIGH);
  }
  if(digitalRead(BPEtage3D) == HIGH){
    digitalWrite(ledEt3D,HIGH);
  }
  if(digitalRead(BPEtage4D) == HIGH){
    digitalWrite(ledEt4D,HIGH);
  }
  if(digitalRead(BPEtage5D) == HIGH){
    digitalWrite(ledEt5D,HIGH);
  }
}
