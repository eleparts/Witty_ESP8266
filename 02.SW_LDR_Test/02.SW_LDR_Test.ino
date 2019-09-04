// GPIO Pin  
const int B_LED       = LED_BUILTIN; // GPIO 2
const int RGB_RED     = 15;
const int RGB_GREEN   = 12;
const int RGB_BULE    = 13;

const int PUSH_BUTTON    = 4;
const int FLASH_BUTTON   = 0;       

const int LDR            = A0; // photoresistor (CDS)


void setup() {
  // put your setup code here, to run once:
  pinMode(B_LED       , OUTPUT);         // builtin
  pinMode(RGB_RED     , OUTPUT);         // red
  pinMode(RGB_GREEN   , OUTPUT);         // green
  pinMode(RGB_BULE    , OUTPUT);         // bule

  pinMode(PUSH_BUTTON , INPUT);
  pinMode(FLASH_BUTTON, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int sensorValue = analogRead(LDR);
  int pushButton = digitalRead(PUSH_BUTTON);
  int flashButton = digitalRead(FLASH_BUTTON);

  // LDR(CDS)- RGB LED control
  if(sensorValue > 900){          // CDS value 1024~901 : Red LED ON 
    RGB_LED(HIGH,LOW,LOW);    
    
  }else if(sensorValue > 300){    // CDS value 900~301  : Bule LED ON 
    RGB_LED(LOW,LOW,HIGH);  
    
  }else{ 
    RGB_LED(LOW,HIGH,LOW);        // CDS value 300~     : Green 0LED ON 
  }

  if(!pushButton)                 // Push button - BUILTIN LED ON
    digitalWrite(B_LED, LOW);

  if(!flashButton)                // Flash button - BUILTIN LED OFF
    digitalWrite(B_LED, HIGH);

    
  delay(200);
}


// RGB LED Control
void RGB_LED(bool red, bool green, bool bule){
  
  digitalWrite(RGB_RED, red);   
  digitalWrite(RGB_GREEN, green);   
  digitalWrite(RGB_BULE, bule); 

  return;
}
