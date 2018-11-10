#ifndef kru_utils_h
#define kru_utils_h
#include "Arduino.h"

String padRight(String s, unsigned int maxLen);

int getStartColForCenteredString(int screenWidth, int textWidth);

String getCenteredString(int screenWidth, String txt);
#endif