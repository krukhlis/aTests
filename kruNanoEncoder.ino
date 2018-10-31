#include <Arduino.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C


SSD1306AsciiAvrI2c oled;
int val;
int encoder0PinA = PD3;
int encoder0PinB = PD7;
int encoder0Button = PD5;

int encoder0Pos = 0;
int encoder0PinALast = LOW;
int encoder0BtnLast = LOW;
int n = LOW;
int btn = LOW;
char buf1[9];
char buf2[9];

void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode (encoder0PinA, INPUT);
  pinMode (encoder0PinB, INPUT);
  pinMode (encoder0Button, INPUT);
  Serial.begin (9600);
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.setI2cClock(444000);
  oled.setFont(System5x7);
  oled.clear();
  oled.print("-=Please chose menu=-");
  Serial.println("Oled rows:"+String(oled.displayRows()));
  Serial.println("Oled cols:"+String(oled.displayWidth()/(oled.fontWidth()+oled.letterSpacing())));
  
}

void draw(int encVal, int btnX){
  oled.setCursor(1,1);oled.println("Val:"+String(encVal)+"    ");
  oled.setCursor(1,2);oled.println("Btn:"+String(btnX)+"    ");
}

// the loop routine runs over and over again forever:
void loop() {
  
  n = digitalRead(encoder0PinA);
  if ((encoder0PinALast == LOW) && (n == HIGH)) {
    if (digitalRead(encoder0PinB) == LOW) {
      encoder0Pos--;
    } else {
      encoder0Pos++;
    }
    Serial.print (encoder0Pos);
    Serial.print ("/");
  }
  encoder0PinALast = n;
  //check button
  btn = digitalRead(encoder0Button);
  if ((encoder0BtnLast == LOW) && (btn == HIGH)) {
    Serial.println("\nButton released");
  } else if ((encoder0BtnLast == HIGH) && (btn == LOW)) {
    Serial.println("\nButton pressed");
  }
  encoder0BtnLast = btn;
  draw(encoder0Pos, encoder0BtnLast);
}
