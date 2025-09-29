//Medii ambiente aeroespacial práctica#1

// Muestra las lecturas del sensor DHT11
#include <LiquidCrystal.h>
#include "DHT.h"
// terminal para conectar el sensor DHT11
#define DHTPIN 12     
// tipo de sensor DHT
#define DHTTYPE DHT11   // DHT 11 

// pines para conectar la pantalla LCD LiquidCrystal
LiquidCrystal lcd(8,9,4,5,6,7); 

DHT dht(DHTPIN, DHTTYPE);
 


void setup()
{
  // conexión del puerto serie (Arduino-Pc)
  Serial.begin(9600); 
  // panatlla de inicialización
  lcd.begin(16,2);
 
  lcd.clear();
  // inicia el sensor DHT11
  dht.begin();
}


void loop() {
  //para obtener datos de humedad
  float h = dht.readHumidity();
  //para obtener datos de temperatura
  float t = dht.readTemperature();
  // mostrar (visualización)
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("H= "); 
  lcd.print(h);lcd.print(" %");
  lcd.setCursor(0,1);
  lcd.print("T= "); 
  lcd.print(t);lcd.print(" *C");
  // salida al puerto serie
  Serial.print("Humidity= "); 
  Serial.print(h);Serial.print(" %");
  Serial.print("   Temperature= "); 
  Serial.print(t);Serial.println(" *C");

   //tiempo sólo para  2 segundos
  delay(2000);
}
