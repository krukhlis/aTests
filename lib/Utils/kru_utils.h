#ifndef kru_utils_h
#define kru_utils_h
#include "Arduino.h"

String padRight(String s, unsigned int maxLen)
{
    for (unsigned int i = s.length(); i <= maxLen; i++)
    {
        s.concat(" ");
    }
    return s;
}
#endif