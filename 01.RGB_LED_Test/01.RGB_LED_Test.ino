/*
* eleparts - Witty ESP-12F 
* RGB LED & BUILTIN LED TEST
*/

// GPIO Pin  
const int B_LED       = LED_BUILTIN; // GPIO 2
const int RGB_RED     = 15;
const int RGB_GREEN   = 12;
const int RGB_BULE    = 13;


void setup() {
  // put your setup code here, to run once:
  
  pinMode(B_LED       , OUTPUT);         // builtin
  pinMode(RGB_RED     , OUTPUT);         // red
  pinMode(RGB_GREEN   , OUTPUT);         // green
  pinMode(RGB_BULE    , OUTPUT);         // bule
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(B_LED, HIGH);         // Builtin LED : GPIO voltage HIGH ==  LED off 
  
  RGB_LED(HIGH,LOW,LOW);             // RGB Red ON
  delay(300);                        // delay 300ms
  
  RGB_LED(LOW,HIGH,LOW);             // RGB Green ON    
  delay(300);                  
  
  RGB_LED(LOW,LOW,HIGH);             // RGB Bule ON
  delay(300);  

  RGB_LED(LOW,LOW,LOW);              // RGB off
  
  digitalWrite(B_LED, LOW);          // Builtin LED : GPIO voltage LOW ==  LED on 
  delay(500);
  
    
}

// RGB LED Control
void RGB_LED(bool red, bool green, bool bule){
  
  digitalWrite(RGB_RED, red);   
  digitalWrite(RGB_GREEN, green);   
  digitalWrite(RGB_BULE, bule); 

  return;
}
