int ledMotM = 14;
int ledMotD = 15;
int ledEt1 = 45;
int ledDetecEt1 = 13;
int ledEt2 = 44;
int ledEt3 = 43;
int ledEt4 = 42;
int ledDetecEt2 = 12;
int ledDetecEt3 = 11;
int ledDetecEt4 = 10;
int ledDetecEt5 = 9;
int ledUrgence = 46;

int ledBPEtage3M =  27;
int ledBPEtage3D = 23;
int BPEtage3M = 35;
int BPEtage3D = 32; 

void setup() {
  pinMode(ledUrgence, OUTPUT);
  pinMode(ledUrgence, INPUT);
  pinMode(ledMotM, OUTPUT);
  pinMode(ledMotD,OUTPUT);
  pinMode(ledEt1,OUTPUT);
  pinMode(ledEt1,INPUT);
  pinMode(ledEt2,INPUT);
  pinMode(ledEt3,INPUT);
  pinMode(ledEt4,INPUT);
  pinMode(ledDetecEt1,OUTPUT);
  pinMode(ledDetecEt2,OUTPUT);
  pinMode(ledDetecEt3,OUTPUT);
  pinMode(ledDetecEt4,OUTPUT);
  pinMode(ledDetecEt5,OUTPUT);

  pinMode(ledBPEtage3M,OUTPUT);
  pinMode(ledBPEtage3D,OUTPUT);
  pinMode(BPEtage3M,INPUT);
  pinMode(BPEtage3D,INPUT);
}

void arret_urgence() {
    digitalWrite(ledMotM,LOW);
    digitalWrite(ledMotD,LOW);
}

void monterDepuisEtage3(){
  if(digitalRead(ledDetecEt1)== HIGH || digitalRead(ledDetecEt2)== HIGH){
    if (digitalRead(ledEt3M) == HIGH){
        digitalWrite(ledEt3M,HIGH);
        digitalWrite(ledMotM,HIGH); 
    }
  }else {
    if(digitalRead(ledEt3M) == HIGH){
        digitalWrite(ledEt3M,HIGH);
        digitalWrite(ledMotD,HIGH); 
    }
  }
  
  if(digitalRead(ledDetecEt3) == HIGH){
        digitalWrite(ledMotD,LOW);
        digitalWrite(ledMotM,LOW);
  }
}

void descendreDepuisEtage3() {
  if(digitalRead(ledDetecEt1)== HIGH || digitalRead(ledDetecEt2)== HIGH){
    if(digitalRead(ledEt3D) == HIGH){
        digitalWrite(ledEt3D,HIGH);
        digitalWrite(ledMotM,HIGH); 
    }
  }else {
    if (digitalRead(ledEt3D) == HIGH){
        digitalWrite(ledEt3D,HIGH);
        digitalWrite(ledMotD,HIGH); 
    }
  }
  if(digitalRead(ledDetecEt3) == HIGH){
        digitalWrite(ledMotD,LOW);
        digitalWrite(ledMotM,LOW);
  }
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

void allerEtage5() {
    if(digitalRead(ledEt5) == HIGH){
        digitalWrite(ledEt5,HIGH);
        digitalWrite(ledMotM,HIGH);
    }
    if(digitalRead(ledDetecEt5) == HIGH){
        digitalWrite(ledMotM,LOW);
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
