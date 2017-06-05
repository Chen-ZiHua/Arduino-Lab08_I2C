#include <Wire.h>
#include <LiquidCrystal.h> // include the library code
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int SLAVE_ADDRESS = 1;
char incomingByte;
void setup() {
  Serial.begin(9600);
  lcd.begin(20, 2);
  Wire.begin(); // join I2C bus as a Master
}
void loop() {
Wire.requestFrom(SLAVE_ADDRESS,5);
// request 1 bytes from slave
while (Wire.available()) {
incomingByte = Wire.read(); // receive a byte
//Serial.print(incomingByte);
lcd.print(incomingByte);// Display at LCD


}
-delay(1000);
// LCD 換行
}
