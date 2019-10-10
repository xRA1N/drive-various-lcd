/*
 * YXD12864G04  
 * Controller "ks0108", Display "128x64"  Description
 *  1   2   3   4   5   6   7   8   9   10   11   12   13   14    15    16           
 *  GND VCC RS  RW  EN  DB7 DB6   ~               DB1  DB0  CS2   CS1   VCC            
 *  
 * U8G2_KS0108_128X64_1(rotation, d0, d1, d2, d3, d4, d5, d6, d7, enable, dc, cs0, cs1, cs2 [, reset])   page buffer, size = 128 bytes
 * U8G2_KS0108_128X64_2(rotation, d0, d1, d2, d3, d4, d5, d6, d7, enable, dc, cs0, cs1, cs2 [, reset])   page buffer, size = 256 bytes
 * U8G2_KS0108_128X64_F(rotation, d0, d1, d2, d3, d4, d5, d6, d7, enable, dc, cs0, cs1, cs2 [, reset])   full framebuffer, size = 1024 bytes
 */
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif


// Set R/W to low!
U8G2_KS0108_128X64_F u8g2(U8G2_R0, 4,5, 6, 7, 8, 9,10, 11, /*enable=*/12,/*dc=*/  13,   /*cs0=*/ 3, /*cs1=*/ 2, /*cs2=*/ U8X8_PIN_NONE, /* reset=*/  U8X8_PIN_NONE); 

void setup(void) {
  u8g2.begin();
}

void loop(void) {
  u8g2.clearBuffer();					// clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
  u8g2.drawStr(0,10,"Hello World!");	// write something to the internal memory
  u8g2.sendBuffer();					// transfer internal memory to the display
  delay(1000);  
}
