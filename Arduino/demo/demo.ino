#include<LiquidCrystal.h>
#include <Servo.h>

Servo servo1,servo2;
int pos = 0;   
int i;
LiquidCrystal lcd(12 , 11, 5, 4, 3, 2);
int trigPin1=10;
int echoPin1=9;

int trigPin2=A0;
int echoPin2=8;

//int relay = 13; 
int distance1=0;
int distance2=0;
long duration1;
long duration2;

const int maxCap1=28;
const int maxCap2=28;
int temp1=0;
int temp2=0;



void setup() 
{
  
  servo1.attach(7);
  servo2.attach(6);
  lcd.begin(16, 2);
  
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);

  servo1.write(0);
  servo2.write(0);
  
}

void loop() 
{

  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1= duration1*0.034/2;

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2= duration2*0.034/2;

  
  
  
  lcd.setCursor(0,0);
  temp1=(maxCap1-distance1)*4.38;
  lcd.print("Tank 1 : ");
  lcd.print(temp1);
  lcd.print("%    ");
  

  lcd.setCursor(0,1);
  temp2=(maxCap2-distance2)*4.38;
  lcd.print("Tank 2 : ");
  lcd.print(temp2);
  lcd.print("%    ");
  
  delay(7);



  if(temp1>=96&&temp2<96)
  {
    servo1.write(180);
    servo2.write(0);
    
  }
  if(temp2>=96)
  {

   servo2.write(180);
   servo1.write(0);
   
    
  }
  

  

  if(temp1>=96&&temp2>=96)
  {
    digitalWrite(13,HIGH);
     servo1.write(180);
     servo2.write(180);
     
  }
  else
  {
    digitalWrite(13,LOW);   
  }
}
