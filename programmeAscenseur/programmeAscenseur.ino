int ledUrgence = 46;
int ledMotM = 14;
int ledMotD = 15;
int ledEt1 = 45;
int ledDetecEt1 =13;

void setup() {
  pinMode(ledUrgence, OUTPUT);
  pinMode(ledUrgence, INPUT);
  pinMode(ledMotM, OUTPUT);
  pinMode(ledMotD,OUTPUT);
  pinMode(ledEt1,OUTPUT);
  pinMode(ledEt1,INPUT);
  pinMode(ledDetecEt1,OUTPUT);
}

void arret_urgence() {
  // put your main code here, to run repeatedly:
    digitalWrite(ledMotM,LOW);
    digitalWrite(ledMotD,LOW);
}

void descendreEtage1() {
  if(digitalRead(ledEt1) == HIGH){
      digitalWrite(ledEt1,HIGH);
      digitalWrite(ledMotD,HIGH); 
  }
}
void loop(){
  if(digitalRead(ledUrgence) == LOW){
    descendreEtage1();
    if(digitalRead(ledDetecEt1) == HIGH){
      digitalWrite(ledMotD,LOW);
    }
  }else{
    arret_urgence();
  }
}
