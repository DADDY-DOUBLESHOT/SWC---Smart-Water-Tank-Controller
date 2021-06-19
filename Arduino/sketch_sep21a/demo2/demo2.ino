#include<LiquidCrystal.h>
#include <Servo.h>


int pos = 0;   
int i;
LiquidCrystal lcd(12 , 11, 5, 4, 3, 2);
int trigPin1=10;
int echoPin1=9;

int trigPin2=A0;
int echoPin2=8;


int tank1 =6 ; 
int relay = 13; 
int distance1=0;
int distance2=0;
long duration1;
long duration2;

const int maxCap1=28;
const int maxCap2=28;



void setup() 
{
  
  lcd.begin(16, 2);
  
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  
  pinMode(6,OUTPUT);
  digitalWrite(6,HIGH);
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);


  
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
  int temp1=(maxCap1-distance1)*4.38;
  lcd.print("Tank 1 : ");
  lcd.print(temp1);
  lcd.print("%    ");

  lcd.setCursor(0,1);
  int temp2=(maxCap2-distance2)*4.38;
  lcd.print("Tank 2 : ");
  lcd.print(temp2);
  lcd.print("%    ");
  
  delay(7);



  if(temp1>=96&&temp2<96)
  {
    
    digitalWrite(6,LOW);
  }
  if(temp2>=96&&temp1<96)
  {
    digitalWrite(6,HIGH);
  }
  

  

  if(temp1>=96&&temp2>=96)
  {
    digitalWrite(13,HIGH);
    digitalWrite(6,HIGH);
     
  }
  else
  {
    digitalWrite(13,LOW); 
      
  }


}
