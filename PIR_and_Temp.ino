const int buzzer = 8;

int reg = A1;
int temp;

int PIR = 5;
const int led_red = 3;
const int led_green = 4;

void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(PIR, INPUT);
  pinMode(reg, INPUT);
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  Serial.begin(9600);
  //dht.begin();
}

void loop()
{
  
  int reading = digitalRead(PIR);
  temp = analogRead(reg)/20;
  //temp = dht.readTemperature();
  Serial.print('\n');
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");

  digitalWrite(led_red, LOW);
  delay(10);
  digitalWrite(led_green, LOW);
  delay(10);
  
  Serial.println(reading);
  
  if (temp >= 20 && reading == 1) {
    Serial.print("Motion detected");
    tone(buzzer, 6553); 
    
    Serial.print('\n');
    digitalWrite(led_red, LOW);
    delay(10);
    digitalWrite(led_green, HIGH);
    //delay(1000);
    delay(1000);        
    noTone(buzzer);   
    delay(10);
  }
  else if (temp <= 10 && reading == 1){
    Serial.print("Motion detected");
    tone(buzzer, 6553); 
    
    Serial.print('\n');
    digitalWrite(led_green, LOW);
    delay(10);
    digitalWrite(led_red, HIGH);
    //delay(1000);
    delay(1000);        
    noTone(buzzer);   
    delay(10);
  }


  delay(3000);
}
