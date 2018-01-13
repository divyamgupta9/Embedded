int LANE1[]={2,3,4};//red yellow green//
int LANE2[]={5,6,7};
int LANE3[]={8,9,10};
int LANE4[]={11,12,13};
void setup()
{
for(int i=0;i<3;i++)
{

pinMode(LANE1[i],OUTPUT);
pinMode(LANE2[i],OUTPUT);
pinMode(LANE3[i],OUTPUT);
pinMode(LANE4[i],OUTPUT);

  }
  for(int i=0;i<3;i++)
  {

digitalWrite(LANE1[i],LOW);
digitalWrite(LANE2[i],LOW);
digitalWrite(LANE3[i],LOW);
digitalWrite(LANE4[i],LOW);

  }
  }
  void loop()
  {
digitalWrite(LANE1[2],HIGH);
digitalWrite(LANE2[0],HIGH);
digitalWrite(LANE3[0],HIGH);
digitalWrite(LANE4[0],HIGH);
delay(8000);
digitalWrite(LANE1[2],LOW);
digitalWrite(LANE3[0],LOW);
digitalWrite(LANE1[1],HIGH);
digitalWrite(LANE3[1],HIGH);
delay(3000);
digitalWrite(LANE1[1],LOW);
digitalWrite(LANE3[1],LOW);
digitalWrite(LANE1[0],HIGH);
digitalWrite(LANE3[2],HIGH);
delay(8000);
digitalWrite(LANE3[2],LOW);
digitalWrite(LANE2[0],LOW);
digitalWrite(LANE3[1],HIGH);
digitalWrite(LANE2[1],HIGH);
delay(3000);
digitalWrite(LANE3[1],LOW);
digitalWrite(LANE2[1],LOW);
digitalWrite(LANE3[0],HIGH);
digitalWrite(LANE2[2],HIGH);
delay(8000);
digitalWrite(LANE2[2],LOW);
digitalWrite(LANE4[0],LOW);
digitalWrite(LANE2[1],HIGH);
digitalWrite(LANE4[1],HIGH);
delay(3000);
digitalWrite(LANE2[1],LOW);
digitalWrite(LANE4[1],LOW);
digitalWrite(LANE2[0],HIGH);
digitalWrite(LANE4[2],HIGH);
delay(8000);
digitalWrite(LANE4[2],LOW);
digitalWrite(LANE1[0],LOW);
digitalWrite(LANE4[1],HIGH);
digitalWrite(LANE1[1],HIGH);
delay(3000);
digitalWrite(LANE4[1],LOW);
digitalWrite(LANE1[1],LOW);
digitalWrite(LANE4[0],HIGH);
digitalWrite(LANE1[2],HIGH);
delay(8000);

    }


