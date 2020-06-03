/*
 23CM TRX PTT interface program for ATTiny

 RX / TX sequencer voor relais and PA
  
 IC 5 = PB0 = PA_BIAS
 IC 6 = PB1 = RF_RELAIS
 IC 7 = PB2 = PTT_IN 
 IC 2 = PB3 = PTT_TRX

 Used with Programmer "Arduino as ISP" 
 
*/

// Define the ATTiny PIN x = PBx

  #define PA_BIAS 0    
  #define RF_RELAIS 1
  #define PTT_IN 2
  #define PTT_TRX 3  


// the setup function runs once when you press reset or power the board

void setup() {

  // initialize digital pins

  pinMode(PA_BIAS, OUTPUT);
  pinMode(RF_RELAIS, OUTPUT);
  pinMode(PTT_IN, INPUT_PULLUP);    
  pinMode(PTT_TRX, OUTPUT);


// Set Default for RX Final arrangement. 

  digitalWrite(PA_BIAS, LOW);    // Output Pin = HIGH, Aktive LOW  = Bias On       
  digitalWrite(RF_RELAIS, LOW);  // Output Pin = HIGH, Aktive LOW  = Relays On    
  digitalWrite(PTT_TRX, HIGH);   // Output Pin = HIGH, Aktive LOW  = TX On       
       
}

// Subroutines Called by PTT inout

void TX_START(){        
  digitalWrite(RF_RELAIS, HIGH);      
  digitalWrite(PA_BIAS, HIGH);
  delay(10);
  digitalWrite(PTT_TRX, LOW); 
}

void TX_END(){
    digitalWrite(PA_BIAS, LOW);
    digitalWrite(PTT_TRX, HIGH);
    delay(10);
    digitalWrite(RF_RELAIS, LOW);
    delay(10); 
}


// the Main loop function runs over and over again forever

void loop() {

  if (digitalRead(PTT_IN) == LOW)
    { TX_START();
  }
  else
    { TX_END();
  }
  delay(1);
}
