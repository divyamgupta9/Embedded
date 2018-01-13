int led=13;                                                  
int brightness;



// the setup routine runs once when you press reset:
void setup() {
  
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
   analogWrite(led,brightness);  
 
  for(brightness=HIGH;brightness<=0;brightness-10)
   
 

  
 
  
  
 delay(1000);
  
  
  
  
  
   
            
}
