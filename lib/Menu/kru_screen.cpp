#include "kru_screen.h"
#include "Arduino.h"
#include "SSD1306AsciiAvrI2c.h"

KRuScreen::KRuScreen()
{
    width = 0;
    height = 0;
    colors = 1;
}

KRuScreen::KRuScreen(int sWidth, int sHeight, int sColors, uint32_t i2cClock)
{
    width = sWidth;
    height = sHeight;
    colors = sColors;
}

void KRuScreen::println(int col, int row, String s)
{
    //default implementation does nothing
}

void KRuScreen::clearRegion(int col, int startChar, int row, int length){
    //default implementation does nothing
}

KRuScreenSSD1306::KRuScreenSSD1306(int sWidth, int sHeight, int sColors, uint32_t i2cClock)
{
    width = sWidth;
    height = sHeight;
    colors = sColors;
    oled.begin(&Adafruit128x64, SSD1306_I2C_ADDRESS);
    oled.setI2cClock((0 >= i2cClock) ? 444000 : i2cClock);
    oled.setFont(System5x7);
    oled.clear();
}

KRuScreenSSD1306::KRuScreenSSD1306(SSD1306AsciiAvrI2c oledScreen)
{
    height = oledScreen.displayRows();
    width = oledScreen.displayWidth() / (oledScreen.fontWidth() + oledScreen.letterSpacing());
    colors = 1;
    oled = oledScreen;
}

void KRuScreenSSD1306::println(int col, int row, String s)
{
    int xRow = (row > height - 1) ? row % height : row;
    int xCol = (col > width - 1) ? col % width : col;
    //int xCol = col;int xRow = row;
    oled.setCursor(xCol, xRow);
    oled.println(s);
}

void KRuScreenSSD1306::clearRegion(int col, int startChar, int row, int length){
    oled.clearField(col + oled.fieldWidth(startChar), row, length);
}