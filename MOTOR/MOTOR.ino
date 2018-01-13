
void moton();
void motoff();
String t={};
int mot1=12;
int mot2=11;
void setup()
{
Serial.begin(9600);
pinMode(mot1,OUTPUT);
pinMode(mot2,OUTPUT);
}
void loop()
{
  if(Serial.available()>0)
  {
   
    t= Serial.read();
    Serial.println(t);
     Serial.end();
  }
    
    if(t=="65")
    {
 moton();
 delay(1000);
 }
      
       else if(t=="66")
       {
       motoff();
        delay(1000);
       }
       Serial.begin(9600);
  }
  void moton()
   {
    analogWrite(mot1,255);
    analogWrite(mot2,0);
    }
    void motoff()
   {
    analogWrite(mot1,0);
    analogWrite(mot2,0);
    }

