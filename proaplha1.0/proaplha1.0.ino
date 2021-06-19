#include <GSM.h>
#include<LiquidCrystal.h>
#include<Servo.h>

int trigPin=2;
int echoPin=3;
int relay = 8;                                //relay control pin
int trigPin1=2;                               //trig pin ultrasonic sensor 2
int echoPin1=3;                               //echo pin ultrasonic sensor2
int distance,distance2;
GSM gsmAccess; 
GSM_SMS sms;
boolean notConnected = true;

 const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

long duration,duration1;
Servo servo;
Servo servo1;                                 //servo2

void setup()
{
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  Serial.begin(9600);
  servo.attach(9);
  servo1.attach(9);                           //signal pin of servo motor2 
  lcd.begin(16, 2);
  while(notConnected)
  {
    if(gsmAccess.begin(/*PINNUMBER*/)==GSM_READY)
      notConnected = false;
    else
    {
      Serial.println("Not connected");
      delay(1000);
    }
 
}
}
void loop()
{

 //   if(/*pin of dry run sensor input is low*/)
//  {
//  digitalWrite(relay, LOW);
 // }
//  if(/*pin of dry run sensor input is HIGH*/)
//  {
 //   digitalWrite(relay, HIGH);
 // }
  printOut();
    if(distance=10)
     {
      servo.write(180);
     
    delay(200);
    printOut();
//    sms.beginSMS(/*remoteNumber*/);
  //sms.print("Motor one has been turned off");
  //sms.endSMS(); 
     }
  if(distance2=10)
  {
    servo1.write(180);
    delay(200);  
   printOut(); 
//   sms.beginSMS(/*remoteNumber*/);
  //sms.print("Motor two has been turned off");
  //sms.endSMS(); 
  }
}

int calculateDistance()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  return distance;
}  
int calculateDistance2()
{
  digitalWrite(trigPin1,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1,LOW);
  
  duration1=pulseIn(echoPin1,HIGH);
  distance2=duration1*0.034/2;
  return distance2;
}  

void printOut()
{
  lcd.clear();
    lcd.setCursor(0, 0); 
    lcd.print("%of tank1: ");
    lcd.print(calculateDistance());
    lcd.setCursor(0, 1); 
    lcd.print("%of tank2: ");
    lcd.print(calculateDistance2());
 }
