//#include <GSM.h>
#include<LiquidCrystal.h>
#include<Servo.h>

int trigPin=10;
int echoPin=9;
int relay = 13;                                //relay control pin
int trigPin1=8;                               //trig pin ultrasonic sensor 2
int echoPin1=A0;                               //echo pin ultrasonic sensor2
int distance,distance2;
//GSM gsmAccess; 
//GSM_SMS sms;
boolean notConnected = true;

 const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(12 , 11, 5, 4, 3, 2);

long duration,duration1;
Servo servo;
Servo servo1;                                 //servo2

void setup()
{
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  //servo.attach(9);
  //servo1.attach(A0);                           //signal pin of servo motor2 
  lcd.begin(16, 2);
//  while(notConnected)
  //{
   // if(gsmAccess.begin(/*PINNUMBER*/)==GSM_READY)
    //  notConnected = false;
   // else
    //{
    //  Serial.println("Not connected");
    //  delay(1000);
    //}
 
//}
}
void loop()
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;


lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("Distance: "); // Prints string "Distance" on the LCD
lcd.print(distance); // Prints the distance value from the sensor
lcd.print("  cm");
delay(10);

 //   if(/*pin of dry run sensor input is low*/)
//  {
//  digitalWrite(relay, LOW);
 // }
//  if(/*pin of dry run sensor input is HIGH*/)
//  {
 //   digitalWrite(relay, HIGH);
 // }
 
  digitalWrite(13,LOW);
    if(distance=10)
     {
      servo.write(180);
     
    delay(200);
    
//    sms.beginSMS(/*remoteNumber*/);
  //sms.print("Motor one has been turned off");
  //sms.endSMS(); 
     }
  if(distance2=10)
  {
    servo1.write(180);
    delay(200);  
 
//   sms.beginSMS(/*remoteNumber*/);
  //sms.print("Motor two has been turned off");
  //sms.endSMS(); 
  }
  

 



    lcd.clear();
    lcd.setCursor(0, 0); 
    lcd.print("%of tank1: ");
    
    
  /*digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  lcd.print(distance);
delay(10);
  
    lcd.setCursor(0, 1); 
    lcd.print("%of tank2: ");
    digitalWrite(trigPin1,LOW);
  delayMicroseconds(0);
  digitalWrite(trigPin1,HIGH);
  delayMicroseconds(0);
  digitalWrite(trigPin1,LOW);
  
  duration1=pulseIn(echoPin1,HIGH);
  distance2=duration1*0.034/2;
    lcd.print(distance2);
   delay(10);

   */
 

}
