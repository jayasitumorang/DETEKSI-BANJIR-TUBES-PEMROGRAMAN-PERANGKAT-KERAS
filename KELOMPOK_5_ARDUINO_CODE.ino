#include <Servo.h>  
#include <LiquidCrystal.h>  
const int trig = 2, echo = 3; 
int z; 
int merah=A0,orange=A1,kuning=A2,hijau=A3;  
int buzzer=7; 
int durasi, Distanceincm; 
Servo myservo;  
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);  

void setup() {
  lcd.begin(16, 2); 
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT); 
  pinMode(merah, OUTPUT); 
  pinMode(kuning, OUTPUT);  
  pinMode(hijau, OUTPUT); 
  pinMode(orange, OUTPUT);  
  digitalWrite(hijau, HIGH);  
  myservo.attach(4);  
  
}

void loop() {
  
  digitalWrite(trig, HIGH); 
  delay(15);  
  digitalWrite(trig, LOW);  
  durasi = pulseIn(echo, HIGH); 
  Distanceincm = (durasi / 58.2); 
  z=335-Distanceincm; 
  lcd.setCursor(0, 0);  
  lcd.print("Ketinggian : "); 
  lcd.print(z); 
  delay(1000); 
  
  if (Distanceincm > 240) {
    lcd.clear(); 
    lcd.setCursor(0, 1);  
    lcd.print("Kondisi: Aman  "); 
    digitalWrite(merah, LOW);
    digitalWrite(orange, LOW);
    digitalWrite(kuning, LOW);
    digitalWrite(hijau, HIGH);
    noTone(buzzer); 
    myservo.write(0); 
    delay(20);  
    
  }
  if (Distanceincm > 160 && Distanceincm <= 240 ) {
    lcd.setCursor(0, 1);  
    lcd.print("Kondisi: Siaga 1");   
    digitalWrite(merah, LOW);
    digitalWrite(orange, LOW);
    digitalWrite(kuning, HIGH);
    digitalWrite(hijau, LOW);
    noTone(buzzer); 
    myservo.write(30);  
    delay(20);  
  }
  if (Distanceincm > 80 && Distanceincm <= 160) { 
    lcd.setCursor(0, 1);
    lcd.print("Kondisi: Siaga 2");    
    digitalWrite(merah, LOW);
    digitalWrite(orange,HIGH);
    digitalWrite(kuning, LOW);
    digitalWrite(hijau, LOW);
    noTone(buzzer);
    myservo.write(60);  
    delay(20);  
  }
  if (Distanceincm > 0 && Distanceincm <= 80) {
    lcd.setCursor(0, 1);  
    lcd.print("Kondisi: BAHAYA!");   
    digitalWrite(merah, HIGH);
    digitalWrite(orange,LOW);
    digitalWrite(kuning, LOW);
    digitalWrite(hijau, LOW);
    buzz(); 
    myservo.write(90);  
    delay(20);  
  }
 
}

void buzz(){
  tone(buzzer,2000,250); 
    delay(300); 
}
