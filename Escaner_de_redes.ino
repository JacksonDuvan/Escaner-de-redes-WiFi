#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(9600);//Velocidad de conexion serial
  pinMode(16,OUTPUT);//GPO16 como salida 
  pinMode(5,OUTPUT);//GPO5 como salida 
  WiFi.mode(WIFI_STA);//Modulo como estacion WiFi
  WiFi.disconnect();//Desconectamos el WiFi 
  delay(100);//Reatardo
  Serial.println("");
  Serial.println("Configuracion realizada");//Imprimimos mensaje Serial
  delay(1000);//Retardo 
}
void loop() {
  Serial.println("////////////////////////////////");//Imprimimos 
  Serial.println("           Iniciamos escaneo.");//Imprimios mensaje Serial
  Serial.println("////////////////////////////////");//Imprimimos 

  int R = WiFi.scanNetworks();//Activamos escaner y lo almacenamos en la variable R 

  if (R == 0){
    Serial.println("No hay redes disponibles...");//Imprimios mensaje Serial
    }
  else{ //Si se encuentran redes disponibles 
    Serial.print(R); //Imprimimos cantidad de redes disponibles 
    Serial.println(" Redes disponibles.");//Imprimios mensaje Serial
    if(R <= 5){
      digitalWrite(16,HIGH);//Enciende LED AMARILLO 
      digitalWrite(5,LOW);
      }
    if(R > 5){
      digitalWrite(5,HIGH);//Enciende LED AZUL
      digitalWrite(16,LOW);
      }
    }
  
  

}
