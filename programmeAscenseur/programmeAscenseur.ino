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

void allerEtage5() {
    if(digitalRead(ledEt5) == HIGH){
        digitalWrite(ledEt5,HIGH);
        digitalWrite(ledMotM,HIGH);
    }
    if(digitalRead(ledDetecEt5) == HIGH){
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

void loop(){
 if(digitalRead(ledUrgence) == LOW){
    arret_urgence();
  }else{
    descendreEtage1();
    allerEtage2();
    allerEtage3();
    allerEtage4();
  }
}
