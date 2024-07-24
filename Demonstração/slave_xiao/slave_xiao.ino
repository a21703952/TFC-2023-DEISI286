#include <WiFi.h>
#include <U8g2lib.h>
#include <Arduino.h>
#include <SPI.h>
#include <stdio.h>

HardwareSerial mySerial(0);

U8G2_SSD1327_WS_128X128_F_4W_HW_SPI u8g2(U8G2_R0, D1, D2, D3);
void setup() {     
  Serial.begin(9600); 
  mySerial.begin(9600, SERIAL_8N1, 1, 0);
  u8g2.begin();
  //oled.setFont(u8g2_font_uMINI_6x8); // Select a font
}
float temperatura = 10.0;
void loop() {
  temperatura = temperatura + 1.0;
  if (mySerial.available()) {
    String tempString = mySerial.readStringUntil('\n'); // Read the incoming data as a string
    temperatura = tempString.toFloat(); // Convert the string to a float
    Serial.print("Received Temperature: ");
    Serial.print(temperatura);
    Serial.println(" °C");
  }
  char tempRead[5];
  sprintf(tempRead, "%.1f°C", temperatura);
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    /*u8g2.drawStr(20,40,"Temperatura:");
    u8g2.drawStr(20,50, tempRead);
    u8g2.drawStr(40,50,"ºC");
    u8g2.setCursor(5,40);
    u8g2.print("Temperatura:");*/
    u8g2.setCursor(30,70);
    u8g2.print(tempRead);
  } while ( u8g2.nextPage() );   // Update the display
  delay(1000);
}
