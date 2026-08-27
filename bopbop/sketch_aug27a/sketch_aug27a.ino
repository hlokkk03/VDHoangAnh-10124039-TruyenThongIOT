#define LED1 11
#define LED2 12
#define LED3 13
#define LED4 10

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {

  digitalWrite(LED1, LOW); 
  digitalWrite(LED2, HIGH); 
  digitalWrite(LED3, LOW);  
  digitalWrite(LED4, HIGH); 
  delay(1000);            


  digitalWrite(LED1, HIGH); 
  digitalWrite(LED2, LOW);  
  digitalWrite(LED3, HIGH); 
  digitalWrite(LED4, LOW); 
  delay(1000);              
}