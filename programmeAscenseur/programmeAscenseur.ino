int MotM = 14;
int MotD = 15;

int etage1 = 13;
int etage2 = 12;
int etage3 = 11;
int etage4 = 10;
int etage5 = 9;

int cab1 = 48;
int cab2 = 47;
int cab3 = 38;
int cab4 = 39;
int cab5 = 40;

int ledDetecEt1 = 53;
int ledDetecEt2 = 52;
int ledDetecEt3 = 51;
int ledDetecEt4 = 50;
int ledDetecEt5 = 49;
int ledUrgence = 46;

int ledEt1M = 29;
int ledEt2M = 28;
int ledEt3M = 27;
int ledEt4M = 26;

int ledEt2D = 22;
int ledEt3D = 23;
int ledEt4D = 24;
int ledEt5D = 25;

int bit0 = 5;
int bit1 = 4;
int bit2 = 3;

int BPEtage1M = 37;
int BPEtage2M = 36;
int BPEtage3M = 35;
int BPEtage4M = 34;

int BPEtage2D = 33;
int BPEtage3D = 32;
int BPEtage4D = 31;
int BPEtage5D = 30;

int porteEt1 = 45;
int porteEt2 = 44;
int porteEt3 = 43;
int porteEt4 = 42;
int porteEt5 = 41;

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
  pinMode(BPEtage5D,INPUT);
}

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

void allerEtage1() {
 
  if(digitalRead(etage1) == HIGH){
      digitalWrite(MotD,HIGH);
  }
  if(digitalRead(ledDetecEt1) == HIGH){
      digitalWrite(MotD,LOW);
      digitalWrite(etage1,LOW);
  }
}

void allerEtage2() {
  if(digitalRead(ledDetecEt3)== HIGH || digitalRead(ledDetecEt4)== HIGH || digitalRead(ledDetecEt5)== HIGH){
    if(digitalRead(etage2) == HIGH){
        digitalWrite(MotD,HIGH); 
    }
  }else {
    if(digitalRead(etage2) == HIGH){
        digitalWrite(MotM,HIGH); 
    }
  }
  if(digitalRead(ledDetecEt2) == HIGH){
        digitalWrite(MotD,LOW);
        digitalWrite(MotM,LOW);
        digitalWrite(etage2,LOW);
    }
}

void allerEtage3() {
  if(digitalRead(ledDetecEt4)== HIGH || digitalRead(ledDetecEt5)== HIGH){
    if(digitalRead(etage3) == HIGH){
        digitalWrite(MotD,HIGH); 
    }
  }else{
    if(digitalRead(etage3) == HIGH){
        digitalWrite(MotM,HIGH); 
    }
  }
  if(digitalRead(ledDetecEt3) == HIGH){
       digitalWrite(MotD,LOW);
       digitalWrite(MotM,LOW);
       digitalWrite(etage3,LOW);
  }
}

void allerEtage4() {
  if(digitalRead(ledDetecEt1)== HIGH || digitalRead(ledDetecEt2)== HIGH || digitalRead(ledDetecEt3)== HIGH){
    if(digitalRead(etage4) == HIGH){
        digitalWrite(MotM,HIGH); 
    }
  }else {
    if(digitalRead(etage4) == HIGH){
        digitalWrite(MotD,HIGH); 
    }
  }
  if(digitalRead(ledDetecEt4) == HIGH){
        digitalWrite(MotD,LOW);
        digitalWrite(MotM,LOW);
        digitalWrite(etage4,LOW);
    }
}

void allerEtage5() {
    if(digitalRead(etage5) == HIGH){
        digitalWrite(MotM,HIGH);
    }
    if(digitalRead(ledDetecEt5) == HIGH){
        digitalWrite(MotM,LOW);
        digitalWrite(etage5,LOW);
    }
}

void monterDepuisEtage1(){
  if(digitalRead(ledDetecEt2)== HIGH || digitalRead(ledDetecEt3)== HIGH || digitalRead(ledDetecEt4)== HIGH || digitalRead(ledDetecEt5)== HIGH){
    if (digitalRead(ledEt1M) == HIGH){
        digitalWrite(MotD,HIGH); 
    }
  }
  if(digitalRead(ledDetecEt1) == HIGH){
        digitalWrite(MotD,LOW);
        digitalWrite(ledEt1M,LOW);
  }
}

void monterDepuisEtage2(){
  if(digitalRead(ledDetecEt1)== HIGH){
    if (digitalRead(ledEt2M) == HIGH){
        digitalWrite(MotM,HIGH); 
    }
  }else {
    if(digitalRead(ledEt2M) == HIGH){
        digitalWrite(MotD,HIGH); 
    }
  }
  if(digitalRead(ledDetecEt2) == HIGH){
        digitalWrite(MotD,LOW);
        digitalWrite(MotM,LOW);
        digitalWrite(ledEt2M,LOW);
  }
}

void monterDepuisEtage3() {
  if (digitalRead(ledEt3M) == HIGH) {
    if (digitalRead(ledDetecEt1) == HIGH || digitalRead(ledDetecEt2) == HIGH) {
      digitalWrite(MotM,HIGH);
    } else {
      if(digitalRead(ledEt3M) == HIGH){
        digitalWrite(MotD,HIGH);
      }
    }
  }

  if (digitalRead(ledDetecEt3) == HIGH) {
    digitalWrite(ledEt3M,LOW);
    digitalWrite(MotM,LOW);
    digitalWrite(MotD,LOW);
  }
}

void monterDepuisEtage4(){
  if(digitalRead(ledDetecEt1)== HIGH || digitalRead(ledDetecEt2)== HIGH || digitalRead(ledDetecEt3)== HIGH){
    if (digitalRead(ledEt4M) == HIGH){
        digitalWrite(MotM,HIGH); 
    }
  }else {
    if ( digitalRead(ledEt4M) == HIGH){
      digitalWrite(MotD,HIGH);
    } 
  }
  if(digitalRead(ledDetecEt4) == HIGH ){
        digitalWrite(MotD,LOW);
        digitalWrite(MotM,LOW);
        digitalWrite(ledEt4M,LOW);
  }
}

void descendreDepuisEtage2() {
  if(digitalRead(ledDetecEt1)== HIGH){
    if(digitalRead(ledEt2D) == HIGH){
        digitalWrite(MotM,HIGH); 
    }
  }else {
    if (digitalRead(ledEt2D) == HIGH){
        digitalWrite(MotD,HIGH); 
    }
  }
  if(digitalRead(ledDetecEt2) == HIGH){
        digitalWrite(MotD,LOW);
        digitalWrite(MotM,LOW);
        digitalWrite(ledEt2D,LOW);
  }
}

void descendreDepuisEtage3() {
  if (digitalRead(ledEt3D) == HIGH) {
    if (digitalRead(ledDetecEt4) == HIGH || digitalRead(ledDetecEt5) == HIGH) {
      digitalWrite(MotD,HIGH);
    } else {
      if(digitalRead(ledEt3D) == HIGH){
       digitalWrite(MotM,HIGH); 
      }
    }
  }

  if (digitalRead(ledDetecEt3) == HIGH) {
    digitalWrite(ledEt3D,LOW);
    digitalWrite(MotM,LOW);
    digitalWrite(MotD,LOW);
  }
}

void descendreDepuisEtage4() {
  if(digitalRead(ledDetecEt1)== HIGH || digitalRead(ledDetecEt2)== HIGH || digitalRead(ledDetecEt3)== HIGH){
    if(digitalRead(ledEt4D) == HIGH){
        digitalWrite(MotM,HIGH); 
    }
  }else {
    if (digitalRead(ledEt4D) == HIGH){
        digitalWrite(MotD,HIGH); 
    }
  }
  if(digitalRead(ledDetecEt4) == HIGH){
        digitalWrite(MotD,LOW);
        digitalWrite(MotM,LOW);
        digitalWrite(ledEt4D,LOW);
  }
}

void descendreDepuisEtage5() {
  if(digitalRead(ledDetecEt1)== HIGH || digitalRead(ledDetecEt2)== HIGH || digitalRead(ledDetecEt3)== HIGH || digitalRead(ledDetecEt4)== HIGH){
    if (digitalRead(ledEt5D) == HIGH){
        digitalWrite(MotM,HIGH); 
    }
  }
  if(digitalRead(ledDetecEt5) == HIGH){
        digitalWrite(MotM,LOW);
        digitalWrite(ledEt5D,LOW);
  }
}

void afficheurEtage(int numeroEtage){
  switch(numeroEtage){
    case 1 : digitalWrite(bit0,HIGH);
             digitalWrite(bit1,LOW);
             digitalWrite(bit2,LOW);
             break;
    case 2 : digitalWrite(bit1,HIGH);
             digitalWrite(bit0,LOW);
             digitalWrite(bit2,LOW);
             break;
    case 3 : digitalWrite(bit0,HIGH);
             digitalWrite(bit1,HIGH);
             digitalWrite(bit2,LOW);
             break;
    case 4 : digitalWrite(bit2,HIGH);
             digitalWrite(bit1,LOW);
             digitalWrite(bit0,LOW);
             break;
    default : digitalWrite(bit2,HIGH);
              digitalWrite(bit0,HIGH);
              digitalWrite(bit1,LOW);
              break;
  }
}

void initialisation(){
   do{
      digitalWrite(MotD,HIGH);
   }while (digitalRead(ledDetecEt5) != HIGH && digitalRead(ledDetecEt4) != HIGH && digitalRead(ledDetecEt3) != HIGH && digitalRead(ledDetecEt2) != HIGH && digitalRead(ledDetecEt1) != HIGH);
      digitalWrite(MotD,LOW);
}

void porte(){
    if(digitalRead(porteEt5) != HIGH || digitalRead(porteEt4) != HIGH || digitalRead(porteEt3) != HIGH || digitalRead(porteEt2) != HIGH || digitalRead(porteEt1) != HIGH){
      digitalWrite(MotM,LOW);
      digitalWrite(MotD,LOW);
    }  
}

void loop(){
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
<<<<<<< HEAD
  }
  if(digitalRead(ledEt1M)== HIGH || digitalRead(ledEt2M)== HIGH || digitalRead(ledEt3M)== HIGH || digitalRead(ledEt4M)== HIGH || digitalRead(MotM) != HIGH && digitalRead(ledDetecEt1) == HIGH){
   if(digitalRead(ledEt1M)== HIGH){
      monterDepuisEtage1();
    }
    if(!(digitalRead(MotD) == HIGH && (digitalRead(etage1) == HIGH) && digitalRead(ledEt2M)== HIGH)){
  
    if(digitalRead(ledEt1M)== HIGH){
      monterDepuisEtage1();
    }
    if(!(digitalRead(MotD) == HIGH && (digitalRead(etage1) == HIGH) && digitalRead(ledEt2M)== HIGH){

      monterDepuisEtage2();
    }
    if(!(digitalRead(MotD) == HIGH && (digitalRead(etage1) == HIGH || digitalRead(etage2) == HIGH) && digitalRead(ledEt3M)== HIGH)){
      monterDepuisEtage3();
    }
    if(!(digitalRead(MotD) == HIGH && (digitalRead(etage1) == HIGH || digitalRead(etage2) == HIGH || digitalRead(etage3) == HIGH) && digitalRead(ledEt4M)== HIGH)){
      monterDepuisEtage4();
    }

   
    if(digitalRead(ledEt2D)== HIGH){
      descendreDepuisEtage2();
    }
    if(digitalRead(ledEt3D)== HIGH){
      descendreDepuisEtage3();
    }
    if(digitalRead(ledEt4D)== HIGH){
      descendreDepuisEtage4();
    }
    if(digitalRead(ledEt5D)== HIGH){
      descendreDepuisEtage5();
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
