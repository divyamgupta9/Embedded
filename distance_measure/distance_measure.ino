int trig=7;
int echo=8;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DISTANCE");
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  }
  void loop()
  {
int dist,time;

digitalWrite(7,HIGH);
delay(1000);
digitalWrite(7,LOW);
time=pulseIn(echo,HIGH);
dist = (time/2) * 0.034049 ;
if(dist>300||dist<0){
lcd.setCursor(0,1);
lcd.print("out of range");
}
else 
{
  
lcd.setCursor(0,1);
lcd.print(dist);
lcd.print("CM");
}
delay(1000);
    }
