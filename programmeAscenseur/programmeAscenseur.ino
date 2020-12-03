int ledMotM = 14;
int ledMotD = 15;
int ledEt1 = 48;
int ledDetecEt1 = 53;
int ledEt2 = 47;
int ledEt3 = 38;
int ledEt4 = 39;
int ledEt5 = 40;
int ledDetecEt2 = 52;
int ledDetecEt3 = 51;
int ledDetecEt4 = 50;
int ledDetecEt5 = 49;
int ledUrgence = 46;
int ledEt4M = 26;
int ledEt4D = 24;
int ledEt1M = 29;
int ledEt2M = 28;
int ledEt2D = 22;
int ledEt5D = 25;

int bit0 = 5;
int bit1 = 4;
int bit2 = 3;
int ledBPEtage3D = 23;
int BPEtage3M = 35;
int BPEtage3D = 32;

void setup() {
  pinMode(ledUrgence, OUTPUT);
  pinMode(ledUrgence, INPUT);
  pinMode(ledMotM, OUTPUT);
  pinMode(ledMotD,OUTPUT);
  pinMode(ledEt1,OUTPUT);
  pinMode(ledEt2,OUTPUT);
  pinMode(ledEt3,OUTPUT);
  pinMode(ledEt4,OUTPUT);
  pinMode(ledEt5,OUTPUT);
  pinMode(ledEt1,INPUT);
  pinMode(ledEt2,INPUT);
  pinMode(ledEt3,INPUT);
  pinMode(ledEt4,INPUT);
  pinMode(ledEt5,INPUT);
  pinMode(ledEt4M,OUTPUT);
  pinMode(ledEt4D,OUTPUT);
  pinMode(ledEt1M,OUTPUT);
  pinMode(ledEt2M,OUTPUT);
  pinMode(ledEt2D,OUTPUT);  
  pinMode(ledEt5D,OUTPUT);
  pinMode(ledDetecEt1,OUTPUT);
  pinMode(ledDetecEt2,OUTPUT);
  pinMode(ledDetecEt3,OUTPUT);
  pinMode(ledDetecEt4,OUTPUT);
  pinMode(ledDetecEt5,OUTPUT);
  pinMode(ledDetecEt1,INPUT);
  pinMode(ledDetecEt2,INPUT);
  pinMode(ledDetecEt3,INPUT);
  pinMode(ledDetecEt4,INPUT);
  pinMode(ledDetecEt5,INPUT);
  pinMode(bit0,OUTPUT);
  pinMode(bit1,OUTPUT);
  pinMode(bit2,OUTPUT);

  pinMode(ledBPEtage3M,OUTPUT);
  pinMode(ledBPEtage3D,OUTPUT);
  pinMode(BPEtage3M,INPUT);
  pinMode(BPEtage3D,INPUT);
}

void arret_urgence() {
    digitalWrite(ledMotM,LOW);
    digitalWrite(ledMotD,LOW);
}

void monterDepuisEtage3() {
  if (digitalRead(BPEtage3M) == HIGH) {
    if (digitalRead(ledDetecEt1) == HIGH || digitalRead(ledDetecEt2) == HIGH) {
      digitalWrite(ledBPEtage3M,HIGH);
      digitalWrite(ledMotM,HIGH);
    } else {
      digitalWrite(ledBpEtage3M,HIGH);
      digitalWrite(ledMotD,HIGH);
    }
  }

  if (digitalRead(ledDetecEt3) == HIGH) {
    digitalWrite(ledBPEtage3M,LOW);
    digitalWrite(ledMotM,LOW);
    digitalWrite(ledMotD,LOW);
  }
}

void descendreDepuisEtage3() {
  if (digitalRead(BPEtage3D) == HIGH) {
    if (digitalRead(ledDetecEt4) == HIGH || digitalRead(ledDetecEt5) == HIGH) {
      digitalWrite(ledBPEtage3D,HIGH);
      digitalWrite(ledMotD,HIGH);
    } else {
      digitalWrite(ledBpEtage3D,HIGH);
      digitalWrite(ledMotM,HIGH);
    }
  }

  if (digitalRead(ledDetecEt3) == HIGH) {
    digitalWrite(ledBPEtage3D,LOW);
    digitalWrite(ledMotM,LOW);
    digitalWrite(ledMotD,LOW);
  }
}

void descendreEtage1() {
  if(digitalRead(ledEt1) == HIGH){
      digitalWrite(ledEt1,HIGH);
      digitalWrite(ledMotD,HIGH); 
  }
  if(digitalRead(ledDetecEt1) == HIGH){
      digitalWrite(ledMotD,LOW);
      digitalWrite(ledEt1,LOW);
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
void monterDepuisEtage1(){
  if(digitalRead(ledDetecEt2)== HIGH || digitalRead(ledDetecEt3)== HIGH || digitalRead(ledDetecEt4)== HIGH || digitalRead(ledDetecEt5)== HIGH){
    if (digitalRead(ledEt1M) == HIGH){
        digitalWrite(ledEt1M,HIGH);
        digitalWrite(ledMotD,HIGH); 
    }
  }
  if(digitalRead(ledDetecEt4) == HIGH){
        digitalWrite(ledMotD,LOW);
        digitalWrite(ledMotM,LOW);
  }
}

void descendreDepuisEtage5() {
  if(digitalRead(ledDetecEt1)== HIGH || digitalRead(ledDetecEt2)== HIGH || digitalRead(ledDetecEt3)== HIGH || digitalRead(ledDetecEt4)== HIGH){
    if(digitalRead(ledEt5D) == HIGH){
        digitalWrite(ledEt5D,HIGH);
        digitalWrite(ledMotM,HIGH); 
    }
  }
  if(digitalRead(ledDetecEt4) == HIGH){
        digitalWrite(ledMotD,LOW);
        digitalWrite(ledMotM,LOW);
  }
}

void monterDepuisEtage2(){
  if(digitalRead(ledDetecEt1)== HIGH){
    if (digitalRead(ledEt2M) == HIGH){
        digitalWrite(ledEt2M,HIGH);
        digitalWrite(ledMotM,HIGH); 
    }
  }else {
    if(digitalRead(ledEt2M) == HIGH){
        digitalWrite(ledEt2M,HIGH);
        digitalWrite(ledMotD,HIGH); 
    }
  }
  if(digitalRead(ledDetecEt2) == HIGH){
        digitalWrite(ledMotD,LOW);
        digitalWrite(ledMotM,LOW);
  }
}

void descendreDepuisEtage2() {
  if(digitalRead(ledDetecEt1)== HIGH){
    if(digitalRead(ledEt2D) == HIGH){
        digitalWrite(ledEt2D,HIGH);
        digitalWrite(ledMotM,HIGH); 
    }
  }else {
    if (digitalRead(ledEt2D) == HIGH){
        digitalWrite(ledEt2D,HIGH);
        digitalWrite(ledMotD,HIGH); 
    }
  }
  if(digitalRead(ledDetecEt2) == HIGH){
        digitalWrite(ledMotD,LOW);
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
 if(digitalRead(ledUrgence) == LOW){
    arret_urgence();
  }else{
    if(digitalRead(ledEt5) == HIGH){
      allerEtage5();
    }if(digitalRead(ledEt4) == HIGH){
      allerEtage4();
    } if(digitalRead(ledEt3) == HIGH){
      allerEtage3();
    } if(digitalRead(ledEt2) == HIGH){
      allerEtage2();
    } if(digitalRead(ledEt1) == HIGH){
      descendreEtage1();
    }

  }
   
}
