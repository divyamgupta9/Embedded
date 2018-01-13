#include<SoftwareSerial.h>//to include software serial class file
//void send_to_mobile();//prototype
//void send_from_mobile();//prototype
void motc();
void mota();
void motoff();
int t;
char i;
int motcl=3;
int motacl=5;
SoftwareSerial mySerial(9,10);//to make pin 9,10 as Rx,Tx respectively for serial communication between bluetooh module and arduino
void setup()
{
  motoff();
  Serial.begin(9600);//baud rate  between serial moniter and arduino serial ports 0,1
  mySerial.begin(9600);//baud rate  between bluetooh and arduino serial ports 9,10
  delay(1000);
  pinMode(motcl,OUTPUT);
   pinMode(motacl,OUTPUT);
  }
  void loop()
  {
    if(mySerial.available()>0)// check if serial data is available at pin 0 from serial moniter
    {
      t=mySerial.read();
      mySerial.flush();
      t=t-48;
      Serial.print("val of t=");
      Serial.println(t);
      switch(t)//reads the data 1 byte at a time and than use for switch case
    {
      case 1:
     motc();
     delay(5000);
     mySerial.println("moter is on as text message is recived on mobile");
     delay(5000);
     break;
     case 2:
     mota();
     delay(5000);
     mySerial.println("moter is off as text message is recived on mobile");
     delay(5000);
     break;
     default :
     motoff();
     delay(5000);
     mySerial.println("invalid input");
     delay(5000);
     break ;
    }}}
        void motc()
        {
          Serial.println("motc block");
          analogWrite(motcl,255);
          analogWrite(motacl,0);
          delay(5000);
          motoff();
          }
          void mota()
        {
          Serial.println("mota block");
          analogWrite(motcl,0);
          analogWrite(motacl,255);
          delay(5000);
          motoff();
          }
          void motoff()
        {
          Serial.println("motoff block");
          analogWrite(motcl,0);
          analogWrite(motacl,0);
          
          }
