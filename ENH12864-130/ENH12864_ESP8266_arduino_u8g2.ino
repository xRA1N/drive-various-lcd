//      ENH12864-130/ ESP8266 arduino 
//     /*sclk=*/ D5, /*data=*/ D7, /*cd=*/ D1, /*cs=*/ D2, /*reset=*/ D9);

#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include <Arduino.h>
U8G2_UC1604_JLX19264_1_4W_HW_SPI u8g2(U8G2_R2,/* cs=*/ D2, /* dc=*/ D1, /* reset=*/ D9); 
void setup(void) {
  u8g2.begin();
}

void loop(void) {
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0, 18, "Hello");    u8g2.drawStr(20, 48, "World!");
  } while ( u8g2.nextPage() );
}
