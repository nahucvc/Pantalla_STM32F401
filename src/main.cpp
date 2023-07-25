

/* Configuracion de la pantalla */
#include <Arduino_GFX_Library.h>
#define GFX_BL PA15 // pin del led de retroiluminacion
Arduino_DataBus *bus = new Arduino_HWSPI(PB5 /* DC */, PB7 /* CS */);
Arduino_GFX *gfx = gfx = new Arduino_ST7735(bus, PB6 /* RST */, 1 /* rotation */, false /* IPS */,
                                            128 /* width */, 160 /* height */, 0 /* col offset 1 */, 0 /* row offset 1 */,
                                            0 /* col offset 2 */, 0 /* row offset 2 */, false /* BGR */);

void setup(void)
{

  if (!gfx->begin())
  {
    Serial.println("gfx->begin() failed!");
  }
  gfx->fillScreen(BLACK);
  /* Encendido de la retroiluminación */
  /**/  pinMode(GFX_BL, OUTPUT);
  /**/ digitalWrite(GFX_BL, HIGH);

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
  pinMode(PC13, OUTPUT);
}

void loop()
{

  digitalWrite(PC13, 0);
  delayMicroseconds(1);
  digitalWrite(PC13, 1);
  delayMicroseconds(1);
}
