int Afrente = 13;
int Atras = 12;
int Bfrente = 11;
int Btras = 10;
int trig = 19;
int echo = 20;
int duracao;
int distanciavar;


void setup()
{
  pinMode(Atras, OUTPUT);
  pinMode(Afrente, OUTPUT);
  pinMode(Btras, OUTPUT);
  pinMode(Bfrente, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

float distancia(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  duracao = pulseIn(echo, HIGH);
  distanciavar = (duracao * 0.034)/2;
}

void frente() 
{
 digitalWrite(Afrente,HIGH);
 digitalWrite(Atras,LOW);
 digitalWrite(Bfrente,HIGH);
 digitalWrite(Btras,LOW);
}
void parar()
{
 digitalWrite(Afrente,LOW);
 digitalWrite(Atras,LOW);
 digitalWrite(Bfrente,LOW);
 digitalWrite(Btras,LOW);
}
void loop ()
{
  frente();
  distancia();

  if (distanciavar < 60)
  {
    parar();
  }
Serial.print("distancia: ");
Serial.print(distanciavar);
Serial.println(" cm");
delay(500);

}
