#include<SoftwareSerial.h>//to include software serial class file
void send_to_mobile();//prototype
void send_from_mobile();//prototype
void motc();
void mota();
void motoff();
String t;
char i;
int motcl=11;
int motacl=10;
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
    if (mySerial.available()>0)// check if serial data is available at pin 0 from serial moniter
    {
      i=mySerial.read();
      Serial.flush();
      mySerial.println(i);
      switch(i)//reads the data 1 byte at a time and than use for switch case
      {
        case 's'://s-->to invoke send_to_mobile
        Serial.println("case s");
        send_to_mobile();
        Serial.println("now we break case s");
        break;
        case 'r'://r-->to invoke send_from_mobile
        Serial.println("case r");
        send_from_mobile();
        Serial.println("now we break case r");
        break;
        }
      }
      if (Serial.available()>0)// check if serial data is available at pin 9 
      {
        Serial.println("trasfeer data from GSM to arduino");
        t=Serial.readString();
        Serial.flush();//hold the program until we enter all input on pin 9,10
        Serial.print("entered string is=");
        Serial.println(t);//print the value of t
        if(t=="on")// if sms from mobile is on then this bloch execute and call motc()
        {
          Serial.println("if condition block");
          motc();
         
          }
          else if(t=="off")// if sms from mobile is off then this bloch execute and call mota()
          {
            Serial.println("else if condition block");
            mota();
            
            }
            else// if sms from mobile is anything other than off then this block will execute
            {
              Serial.println("else condition block");
              motoff();
              
              }
        }
    }
    void send_to_mobile()
    {
Serial.println("send to mobile start");
mySerial.println("AT+CMGF=1");//first command line on gsm to creat text mode
delay(1000);
mySerial.println("AT+CMGF=\"-7014533381\"");//second command line on gsm to send sms
delay(1000);
mySerial.println("sending to mobile from arduino through GSM module");//sms which send to mobile
delay(1000);
mySerial.println("(cha)26");//to send the above written (char)26-->
delay(1000);
Serial.println("send to mobile end");
      }
      void send_from_mobile()
      {
        Serial.println("send from mobile starts");
        mySerial.println("AT+CNMT=2,2,0,0,0");
delay(1000);
Serial.println("send from mobile ends");
        }
        void motc()
        {
          Serial.println("motc block");
          analogWrite(motcl,255);
          analogWrite(motacl,0);
        
         
          }
          void mota()
        {
          Serial.println("mota block");
          analogWrite(motcl,0);
          analogWrite(motacl,255);
          
         
          }
          void motoff()
        {
          Serial.println("motoff block");
          analogWrite(motcl,0);
          analogWrite(motacl,0);
          
          }
