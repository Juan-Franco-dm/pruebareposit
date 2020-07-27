





#include <SoftwareSerial.h> //Incluir Libreria SoftwareSerial
SoftwareSerial MOD_SIM800L(10, 11);

void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  MOD_SIM800L.begin(9600);
  Serial.begin(9600);
  delay(5000); // Tiempo suficiente para ingresar a la red telefonica.
 MOD_SIM800L.print("AT+CREG\r\n");
    delay(200);
  
 MOD_SIM800L.print("AT+CMGF=1\r\n");
    delay(800);
  MOD_SIM800L.print("AT+CNMI=0,2\r\n"); /* El módulo enviará los mensaje 
                            directamente al puerto serial del dispositivo. */
  delay(800); 
 
 
}

void loop(){
  
  
    
   //-----------------------------------------------------------

    while(MOD_SIM800L.available()!=0)
  {
    char option=MOD_SIM800L.read();
    if(option == '#'  )// es muy probable 99% que este dentro de miprudp 
    {
      digitalWrite(LED_BUILTIN, HIGH);
       //Serial.print("hight");
      while(MOD_SIM800L.available()!=0)
      {
      char option=MOD_SIM800L.read();
      }
      delay(100);
      MOD_SIM800L.print("AT+CNMA\r\n");
      delay(500);
      
    }
   

    if(option == '*'  )// es muy probable 99% que este dentro de miprudp 
    {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.print("LOW");
      //Serial.print("hight");
      while(MOD_SIM800L.available()!=0)
      {
      char option=MOD_SIM800L.read();
      }
      delay(100);
      MOD_SIM800L.print("AT+CNMA\r\n");
      delay(500);
     
    }
  
  }
  }    
