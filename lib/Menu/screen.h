#ifndef kru_screen_h
#define kru_screen_h
#include "Arduino.h"
#include "SSD1306AsciiAvrI2c.h"
// 0X3C+SA0 - 0x3C or 0x3D
#define SSD1306_I2C_ADDRESS 0x3C
class KRuScreen
{
public:
  int width, height, colors = 0;
  KRuScreen();
  KRuScreen(int sWidth, int sHeight, int sColors, uint32_t i2cClock);
  virtual void println(int col, int row, String s);
};

class KRuScreenSSD1306 : public KRuScreen
{
public:
  SSD1306AsciiAvrI2c oled;
  KRuScreenSSD1306(int sWidth, int sHeight, int sColors, uint32_t i2cClock);
  KRuScreenSSD1306(SSD1306AsciiAvrI2c oledScreen);
  virtual void println(int col, int row, String s);
};

#endif