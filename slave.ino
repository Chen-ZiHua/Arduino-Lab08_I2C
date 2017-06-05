#include <Wire.h>
#include <dht.h>
#define dht_dpin 2
dht DHT; 
const int SLAVE_ADDRESS = 1;
void setup(){
  Serial.begin(9600);
  Wire.begin(SLAVE_ADDRESS); // join I2C bus as a slave with addres
  Wire.onRequest(requestEvent); // register event
}
void loop() { 
 }
void requestEvent() {
  DHT.read11(dht_dpin); //讀取DHT-11
  float t =DHT.temperature+13;
  float h =DHT.humidity-90;
  char strVal[20];
  char tem[2];
  char hum[3]="61";


  //Serial.println(t);

  dtostrf(t,2,0,tem);
  dtostrf(h,2,0,hum);
  
 sprintf(strVal,"%s %s",(unsigned char *)tem,(unsigned char *)hum);
  

  Wire.write(strVal);
 
}
