#include <SoftwareSerial.h> //Incluir Libreria SoftwareSerial
SoftwareSerial MOD_SIM800L(10, 11); // pines del arduino uno D8 y D9
 //(RX, TX Del Módulo SIM800l)
int timesTosend=1;
int count=0;
char phone_no[]="1153070817";
void setup(){
Serial.begin(9600);
MOD_SIM800L.begin(9600);
delay(2000);
MOD_SIM800L.println("AT+CMGF=1");
delay(200);




}
void loop(){
while(count<timesTosend)
{
  delay(1500);




  // ENVIAR EL COMANDO DE ENVIO DE SMS INCLUYENDO EL DESTINATARIO DEL MENSAJE
MOD_SIM800L.print("AT+CMGS=\"1153070817\"\r");
  delay(100);

  // ENVIAR EL CUERPO DEL MENSAJE
  MOD_SIM800L.print("HOLA MUN!");
  delay(500);

  // ENVIAR EL CARACTER DE CONTROL ASCII 26 (SUB) 0X1A INDICANDO EL FINAL DEL CUERPO DEL MENSAJE
  MOD_SIM800L.print(char(0x1A));
  delay(2000);
}
}



