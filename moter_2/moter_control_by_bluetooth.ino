//#include<SoftwareSerial.h>//to include software serial class file
///void send_to_mobile();//prototype
//void send_from_mobile();//prototype
void motc();
void mota();
void motoff();
String t;
//char i;
int motcl=12;
int motacl=11;
//SoftwareSerial mySerial(9,10);//to make pin 9,10 as Rx,Tx respectively for serial communication between bluetooh module and arduino
void setup()
{
  motoff();
  Serial.begin(9600);//baud rate  between serial moniter and arduino serial ports 0,1
 
  delay(1000);
  pinMode(motcl,OUTPUT);
   pinMode(motacl,OUTPUT);
  }
  void loop()
  {
    
      if (Serial.available()>0)// check if serial data is available at pin 9 
      {
       
        t=Serial.readString();
        Serial.flush();//hold the program until we enter all input on pin 9,10
       Serial.println(t);
      
         Serial.println("trasfering data from bluetooth to arduino");
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
          analogWrite(motacl,0);
         
         
          }
          void motoff()
        {
          Serial.println("motoff block");
          analogWrite(motcl,0);
          analogWrite(motacl,0);
           Serial.println("enter valid command");
          
          }
