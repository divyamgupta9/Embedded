int led =6;
int bright=0;
 int fade=5;
void setup() {
  // put your setup code here, to run once:

pinMode(6,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:


      // digitalWrite(13,HIGH);
    //digitalWrite(12,LOW);
 //   digitalWrite(11,LOW);
    analogWrite(6,bright);
     bright=bright+fade;
      if (bright<=0||bright>=255)
      {
     
      fade=-fade;
      }
      delay(30);
}
