int ledMotM = 14;
int ledMotD = 15;
int ledEt1 = 45;
int ledDetecEt1 =13;
int ledEt2 = 44;
int ledEt3 = 43;
int ledEt4 = 42;
int ledEt5 = 41;
int ledDetecEt2 =12;
int ledDetecEt3 =11;
int ledDetecEt4 =10;
int ledDetecEt5 =9;
int ledUrgence = 46;

int ledEt4M = 26;
int ledEt4D = 24;
int boutonEt4M = 34;
int boutonEt4D = 31;

int bit0 = 5;
int bit1 = 4;
int bit2 = 3;

void setup() {
  pinMode(ledUrgence, OUTPUT);
  pinMode(ledUrgence, INPUT);
  pinMode(ledMotM, OUTPUT);
  pinMode(ledMotD,OUTPUT);
  pinMode(ledEt1,OUTPUT);
  pinMode(ledEt1,INPUT);
  pinMode(ledEt2,INPUT);
  pinMode(ledEt3,INPUT);
  pinMode(ledEt4,OUTPUT);
  pinMode(ledEt4M,OUTPUT);
  pinMode(ledEt4D,OUTPUT);
  pinMode(boutonEt4M,INPUT);
  pinMode(boutonEt4D,INPUT);
  pinMode(ledDetecEt1,OUTPUT);
  pinMode(ledDetecEt2,OUTPUT);
  pinMode(ledDetecEt3,OUTPUT);
  pinMode(ledDetecEt4,OUTPUT);
  pinMode(ledDetecEt5,OUTPUT);
  pinMode(bit0,OUTPUT);
  pinMode(bit1,OUTPUT);
  pinMode(bit2,OUTPUT);
}

void arret_urgence() {
    digitalWrite(ledMotM,LOW);
    digitalWrite(ledMotD,LOW);
}

void descendreEtage1() {
  if(digitalRead(ledEt1) == HIGH){
      digitalWrite(ledEt1,HIGH);
      digitalWrite(ledMotD,HIGH); 
  }
  if(digitalRead(ledDetecEt1) == HIGH){
      digitalWrite(ledMotD,LOW);
  }
}

void allerEtage2() {
  if(digitalRead(ledDetecEt3)== HIGH || digitalRead(ledDetecEt4)== HIGH || digitalRead(ledDetecEt5)== HIGH){
    if(digitalRead(ledEt2) == HIGH){
        digitalWrite(ledEt2,HIGH);
        digitalWrite(ledMotD,HIGH); 
    }
  }else {
    if(digitalRead(ledEt2) == HIGH){
        digitalWrite(ledEt2,HIGH);
        digitalWrite(ledMotM,HIGH); 
    }
  }
  if(digitalRead(ledDetecEt2) == HIGH){
        digitalWrite(ledMotD,LOW);
        digitalWrite(ledMotM,LOW);
    }
}

void allerEtage3() {
  if(digitalRead(ledDetecEt1)== HIGH || digitalRead(ledDetecEt2)== HIGH){
    if(digitalRead(ledEt3) == HIGH){
        digitalWrite(ledEt3,HIGH);
        digitalWrite(ledMotM,HIGH); 
    }
  }else {
    if(digitalRead(ledEt3) == HIGH){
        digitalWrite(ledEt3,HIGH);
        digitalWrite(ledMotD,HIGH); 
    }
  }
  if(digitalRead(ledDetecEt3) == HIGH){
       digitalWrite(ledMotD,LOW);
       digitalWrite(ledMotM,LOW);
  }
}
void allerEtage4() {
  if(digitalRead(ledDetecEt1)== HIGH || digitalRead(ledDetecEt2)== HIGH || digitalRead(ledDetecEt3)== HIGH){
    if(digitalRead(ledEt4) == HIGH){
        digitalWrite(ledEt4,HIGH);
        digitalWrite(ledMotM,HIGH); 
    }
  }else {
    if(digitalRead(ledEt4) == HIGH){
        digitalWrite(ledEt4,HIGH);
        digitalWrite(ledMotD,HIGH); 
    }
  }
  if(digitalRead(ledDetecEt4) == HIGH){
        digitalWrite(ledMotD,LOW);
        digitalWrite(ledMotM,LOW);
    }
}
void monterDepuisEtage4(){
  if(digitalRead(ledDetecEt1)== HIGH || digitalRead(ledDetecEt2)== HIGH || digitalRead(ledDetecEt3)== HIGH){
    if (digitalRead(ledEt4M) == HIGH){
        digitalWrite(ledEt4M,HIGH);
        digitalWrite(ledMotM,HIGH); 
    }
  }else {
    if(digitalRead(ledEt4M) == HIGH){
        digitalWrite(ledEt4M,HIGH);
        digitalWrite(ledMotD,HIGH); 
    }
  }
  if(digitalRead(ledDetecEt4) == HIGH){
        digitalWrite(ledMotD,LOW);
        digitalWrite(ledMotM,LOW);
  }
}

void descendreDepuisEtage4() {
  if(digitalRead(ledDetecEt1)== HIGH || digitalRead(ledDetecEt2)== HIGH || digitalRead(ledDetecEt3)== HIGH){
    if(digitalRead(ledEt4D) == HIGH){
        digitalWrite(ledEt4D,HIGH);
        digitalWrite(ledMotM,HIGH); 
    }
  }else {
    if (digitalRead(ledEt4D) == HIGH){
        digitalWrite(ledEt4D,HIGH);
        digitalWrite(ledMotD,HIGH); 
    }
  }
  if(digitalRead(ledDetecEt4) == HIGH){
        digitalWrite(ledMotD,LOW);
        digitalWrite(ledMotM,LOW);
  }
}
void allerEtage5() {
    if(digitalRead(ledEt5) == HIGH){
        digitalWrite(ledEt5,HIGH);
        digitalWrite(ledMotM,HIGH);
    }
    if(digitalRead(ledDetecEt5) == HIGH){
        digitalWrite(ledMotM,LOW);
    }
}

void afficheurEtage(int numeroEtage){
  switch(numeroEtage){
    case 1 : digitalWrite(bit0,HIGH);
             break;
    case 2 : digitalWrite(bit1,HIGH);
             break;
    case 3 : digitalWrite(bit0,HIGH);
             digitalWrite(bit1,HIGH);
             break;
    case 4 : digitalWrite(bit2,HIGH);
             break;
    default : digitalWrite(bit2,HIGH);
              digitalWrite(bit0,HIGH);
              break;
  }
}

void loop(){
 if(digitalRead(ledUrgence) == HIGH){
    arret_urgence();
  }else{
    descendreEtage1();
    allerEtage2();
  }
  digitalWrite(ledDetecEt1,HIGH);
  if(digitalRead(38) == HIGH){
    digitalWrite(ledDetecEt2,HIGH);
  }else {
    digitalWrite(ledDetecEt2,LOW);
  }
}
