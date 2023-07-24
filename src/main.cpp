/*******************************************************************************
 * Start of Arduino_GFX setting
 *
 * Arduino_GFX try to find the settings depends on selected board in Arduino IDE
 * Or you can define the display dev kit not in the board list
 * Defalult pin list for non display dev kit:
 * Arduino Nano, Micro and more: CS:  9, DC:  8, RST:  7, BL:  6, SCK: 13, MOSI: 11, MISO: 12
 * ESP32 various dev board     : CS:  5, DC: 27, RST: 33, BL: 22, SCK: 18, MOSI: 23, MISO: nil
 * ESP32-C3 various dev board  : CS:  7, DC:  2, RST:  1, BL:  3, SCK:  4, MOSI:  6, MISO: nil
 * ESP32-S2 various dev board  : CS: 34, DC: 38, RST: 33, BL: 21, SCK: 36, MOSI: 35, MISO: nil
 * ESP32-S3 various dev board  : CS: 40, DC: 41, RST: 42, BL: 48, SCK: 36, MOSI: 35, MISO: nil
 * ESP8266 various dev board   : CS: 15, DC:  4, RST:  2, BL:  5, SCK: 14, MOSI: 13, MISO: 12
 * Raspberry Pi Pico dev board : CS: 17, DC: 27, RST: 26, BL: 28, SCK: 18, MOSI: 19, MISO: 16
 * RTL8720 BW16 old patch core : CS: 18, DC: 17, RST:  2, BL: 23, SCK: 19, MOSI: 21, MISO: 20
 * RTL8720_BW16 Official core  : CS:  9, DC:  8, RST:  6, BL:  3, SCK: 10, MOSI: 12, MISO: 11
 * RTL8722 dev board           : CS: 18, DC: 17, RST: 22, BL: 23, SCK: 13, MOSI: 11, MISO: 12
 * RTL8722_mini dev board      : CS: 12, DC: 14, RST: 15, BL: 13, SCK: 11, MOSI:  9, MISO: 10
 * Seeeduino XIAO dev board    : CS:  3, DC:  2, RST:  1, BL:  0, SCK:  8, MOSI: 10, MISO:  9
 * Teensy 4.1 dev board        : CS: 39, DC: 41, RST: 40, BL: 22, SCK: 13, MOSI: 11, MISO: 12
 ******************************************************************************/
#include <Arduino_GFX_Library.h>

#define GFX_BL PA15 // default backlight pin, you may replace DF_GFX_BL to actual backlight pin

/* More data bus class: https://github.com/moononournation/Arduino_GFX/wiki/Data-Bus-Class */
Arduino_DataBus *bus;

/* More display class: https://github.com/moononournation/Arduino_GFX/wiki/Display-Class */

Arduino_GFX *gfx;

void setup(void)
{

  // bus = new Arduino_SWSPI(PB5 /* DC */, PB7 /* CS */,PB3,PB4,-1);
  bus = new Arduino_HWSPI(PB5 /* DC */, PB7 /* CS */);
  gfx = new Arduino_ST7735(
      bus, PB6 /* RST */, 1 /* rotation */, false /* IPS */,
      128 /* width */, 160 /* height */,
      0 /* col offset 1 */, 0 /* row offset 1 */,
      0 /* col offset 2 */, 0 /* row offset 2 */,
      false /* BGR */);
  if (!gfx->begin(40000000))
  {
    Serial.println("gfx->begin() failed!");
  }
  gfx->fillScreen(BLACK);

  pinMode(GFX_BL, OUTPUT);
  digitalWrite(GFX_BL, HIGH);
  gfx->fillScreen(BLACK);
  gfx->setCursor(1, 1);
  gfx->setTextColor(RED);
  gfx->setTextSize(0);
  gfx->println("Hello World!");
  gfx->println("configurando equipo");

  delay(500);
  gfx->fillScreen(BLACK);

  gfx->setFont(u8g2_font_fur11_tf);
  gfx->setCursor(10, 40);
  gfx->printf("rescribiendo");
  pinMode(PC13,OUTPUT);
  


}


void loop()
{
  
 digitalWrite(PC13,0);
 delayMicroseconds(1);
 digitalWrite(PC13,1);
 delayMicroseconds(1);
  
}
