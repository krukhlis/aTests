#include <Arduino.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"

#include "kru_encoder.h"
#include "LinkedList.h"
#include "kru_menu.h"
#include "kru_screen.h"
// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

SSD1306AsciiAvrI2c oled;

int encoder0PinA = PD3;
int encoder0PinB = PD7;
int encoder0Button = PD5;

KRuEncoder encoder(true);
KRuMenu menu = KRuMenu();

/*
void typeof(String a){ Serial.println("it a String a");
}
void typeof(int a)   { Serial.println("it a int a");}
void typeof(char* a) { Serial.println("it a char* a");}
*/
String getType(String a){return "String";};
String getType(KRuScreenSSD1306 a){return "KRuScreenSSD1306";};
String getType(KRuScreen a){return "KRuScreen";};

void setup()
{
  // initialize serial communication at 9600 bits per second:
  pinMode(encoder0PinA, INPUT);
  pinMode(encoder0PinB, INPUT);
  pinMode(encoder0Button, INPUT);
  Serial.begin(9600);
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.setI2cClock(444000);
  oled.setFont(System5x7);
  oled.clear();
  oled.print("-=Please chose menu=-");
  menu.screen= new KRuScreenSSD1306(oled);
  Serial.println("Type:"+getType(*menu.screen));
  Serial.println("KRU:witch classed Encoder v2.0");
  Serial.println("Oled rows:" + String(oled.displayRows()));
  Serial.println("Oled cols:" + String(oled.displayWidth() / (oled.fontWidth() + oled.letterSpacing())));
  // attachInterrupt (digitalPinToInterrupt (encoder0PinA),encIsrPinA,CHANGE);
  // attachInterrupt (digitalPinToInterrupt (encoder0Button),encIsrPinBtn,CHANGE);

  String menuItems[] = {
      "Set Timer 1",
      "Set Timer 2",
      "Set Probe 1 Temp",
      "Set Probe 2 Temp",
      "Probe 1 Controller",
      "Probe 2 Controller",
      "Advanced Settings",
      ""};
  for (int i = 0; i < 7; i++)
  {
    //menu.menuItems.add(menuItems[i]);
    menu.addMenuItem(menuItems[i], LinkedList<KRuMenuItem>());
  }
  Serial.println("Menu itinitialized...");
  menu.currentItem = 0;
  menu.maxItem = menu.menuItems.size() - 1;
  menu.firstCol=1;
  menu.firstRow=3;
  Serial.println("Before first draw...");
  draw(encoder.encoder0Pos, encoder.encoder0BtnLast);
  Serial.println("After first draw...");
}

void encIsrPinA()
{
  encoder.update(digitalRead(encoder0PinA), digitalRead(encoder0PinB), digitalRead(encoder0Button));
}

void encIsrPinBtn()
{
  encoder.update(digitalRead(encoder0PinA), digitalRead(encoder0PinB), digitalRead(encoder0Button));
}

void draw2(int encVal, int btnX)
{
  oled.setCursor(1, 1);
  oled.println("Val:" + String(encVal) + "    ");
  oled.setCursor(1, 2);
  oled.println("Btn:" + String(btnX) + "    ");
  Serial.print(encVal);
  Serial.print("/");
  Serial.print("\nButton:");
  Serial.println(btnX);
  for (int i = 0; i < menu.menuItems.size(); i++)
  {
    oled.setCursor(1, 3 + i);
    oled.println(menu.currentItem == i ? ">" + menu.menuItems.get(i).menuItem : " " + menu.menuItems.get(i).menuItem);
  }
  Serial.println(menu.menuItems.get(menu.currentItem).menuItem);
}

void draw(int encVal, int btnX)
{
  oled.setCursor(1, 1);
  oled.println("Val:" + String(encVal) + "    ");
  oled.setCursor(1, 2);
  oled.println("Btn:" + String(btnX) + "    ");
  Serial.print(encVal);
  Serial.print("/");
  Serial.print("\nButton:");
  Serial.println(btnX);
  menu.draw();
  
  Serial.println(menu.menuItems.get(menu.currentItem).menuItem);
}

// the loop routine runs over and over again forever:
void loop()
{
  encoder.update(digitalRead(encoder0PinA), digitalRead(encoder0PinB), digitalRead(encoder0Button));

  if (encoder.hasChanged)
  {
    menu.update((BOTH == encoder.lastChange || ROTATOR == encoder.lastChange) ? encoder.encoder0Dir : 0, encoder.encoder0BtnLast);
    Serial.println("Last Change:" + String(encoder.lastChange));
    draw(encoder.encoder0Pos, encoder.encoder0BtnLast);
  }
}
