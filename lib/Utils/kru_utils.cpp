#include "kru_utils.h"

String padRight(String s, unsigned int maxLen)
{
    for (unsigned int i = s.length(); i <= maxLen; i++)
    {
        s.concat(" ");
    }
    return s;
}

int getStartColForCenteredString(int screenWidth, int textWidth)
{
    return (screenWidth - textWidth) / 2;
}

String getCenteredString(int screenWidth, String txt)
{
    int leftPad = (screenWidth - txt.length()) / 2;
    String res;
    for (unsigned int i = 1; i <= leftPad; i++)
    {
        res.concat(" ");
    };
    res.concat(txt);
    unsigned int curSize = res.length();
    for (unsigned int i = curSize; i < screenWidth; i++)
    {
        res.concat(" ");
    };
    return res;
}
