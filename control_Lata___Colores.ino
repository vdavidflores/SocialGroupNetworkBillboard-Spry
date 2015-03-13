//pins
int pinBotSpray = 4;
int pinLedInfra = 8;
int pinLedR =9;
int pinLedG = 10;
int pinLedB = 11;
int pinPot = 5;


//valores
int VAP; //valor actual de potenciomertro
int valR = 0;
int valG= 0;
int valB= 0;
int estadoBotSpray = 0;
int numeroColor;
int serialColor;
 // Colores en binario 0-30 y B, N.





void setup(){
  pinMode(pinBotSpray, INPUT);
  pinMode(pinLedInfra, OUTPUT);
  pinMode(pinLedR, OUTPUT);
  pinMode(pinLedG, OUTPUT);
  pinMode(pinLedB, OUTPUT);
  pinMode(pinPot, INPUT);
  Serial.begin(9600);
}

void loop(){
  
 
  
  //Checar el valor actual del potenciometro (VAP) y modular el rango corepondiente
  /*
  Doonde 0-990 es el rrango de colores RGB comenzando de el 12 al 1007
  Del 0-16 son blanco.
  Del 1007- 1023 es negro,
  */
  VAP = analogRead(pinPot);
if(VAP < 17){
     valR = 255;
     valG = 255;
     valB = 255;
     
}
else if(VAP < 347){
   //RANGO 1
     valR = map(VAP,17,347,255,0);
     valG = map(VAP,17,347,0,255);
     valB = 0;
} else if(VAP < 677){
    
    //RANGO 2
    valR = 0;
    valG = map(VAP,347,677,255,0);
    valB = map(VAP,347,677,0,255);
   
}else if(VAP <1007){
   
   //RANGO 3
   valR = map(VAP,677,1007,0,255);
   valG = 0;
   valB = map(VAP,677,1007,255,0);
   
} else if(VAP > 1007){
  valR = 0;
   valG = 0;
   valB = 0;

}
   /*
   Serial.println(VAP);
   Serial.println(valR);
  Serial.println(valG);
  Serial.println(valB);
  */
  
  //Pasar a los valores de  RGB a los leds correspondientes
   analogWrite(pinLedR, valR);
   analogWrite(pinLedG, valG);
   analogWrite(pinLedB, valB);
  
   
   

  //ensender el infrarojo cuando se presione el boton 
 estadoBotSpray = digitalRead(pinBotSpray);
 

  if(estadoBotSpray == HIGH){
    
    digitalWrite(pinLedInfra, HIGH);
    //enviar valores RGB a dispositivo externo
   // Serial.println("on");
    
 
  }else {
    digitalWrite(pinLedInfra, LOW);
    //Serial.println("off");
    
  }
    
  //......................................................Enviar a serial  
   
   
  
  if(VAP <= 17){
      numeroColor = 0;
      }else if(VAP >=1007){
      numeroColor = 32;
      }else if(VAP > 17 && VAP < 1007){
    
  numeroColor = map(VAP,17,1007,1,30);
   }
   
   
   
   
   if ((millis() % 1000) == 0){
     

      Serial.write(numeroColor);
      
      
   }
   
   
}

  
  
  
  


