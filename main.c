#define vccSensor A0
#define pinoSensor A1


#define ledVermelho 12
#define ledLaranja 11
#define ledAmarelo 10
#define ledVerde 9
#define ledAzul 8


int umidade = 0;
void setup(){

  Serial.begin(9600);
  pinMode(vccSensor, OUTPUT);
  pinMode(pinoSensor, INPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledLaranja, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);



}


void loop(){
  digitalWrite(vccSensor, HIGH); // Liga
  delay(100);
  umidade = analogRead(pinoSensor);
  digitalWrite(vccSensor, LOW); // Desliga
  Serial.println(umidade);
  
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledLaranja, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAzul, LOW);

  if (umidade < 200  ){
    digitalWrite(ledVermelho, HIGH);
  }else if ( umidade < 400 && umidade > 200){
    digitalWrite(ledLaranja, HIGH); 
  }else if ( umidade < 600 && umidade > 400){
    digitalWrite(ledAmarelo, HIGH); 
  }else if (umidade < 800 && umidade > 600){
   digitalWrite(ledVerde, HIGH); 
  }else{
  	digitalWrite(ledAzul, HIGH);
  }
    
  
  delay(100);
}