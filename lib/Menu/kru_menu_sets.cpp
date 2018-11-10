#include "Arduino.h"
#include "LinkedList.h"
#include "kru_screen.h"
#include "kru_menu_sets.h"
#include "kru_utils.h"

KRuMenuPlusMinus::KRuMenuPlusMinus(String vName, float step, float maxValue, float minValue, KRuScreen *scr)
{
    maxItem = 0;
    screen = scr;
    maxVal = maxValue;
    minVal = minValue;
    valStep = step;
    valName = vName;
}
void KRuMenuPlusMinus::add()
{
    val += valStep;
    if (val > maxVal)
    {
        val = maxVal;
    }
}
void KRuMenuPlusMinus::minus()
{
    val -= valStep;
    if (val < minVal)
    {
        val = minVal;
    }
}

void KRuMenuPlusMinus::draw()
{
    String txt = "[-] " + valName + ":" + String(val) + " [+]";
    //int sC = getStartColForCenteredString(screen->width-firstCol, txt.length());
    Serial.println("Sw:" + String(screen->width));
    //Serial.println("Sc:"+String(sC));
    //screen->clearRegion(firstCol,1,firstRow,screen->width);
    screen->println(0, firstRow, getCenteredString(screen->width, txt));
}

void KRuMenuPlusMinus::update(int dir, int btn)
{
    val += (float)dir;
    if (val > maxVal)
    {
        val = maxVal;
    }
    if (val < minVal)
    {
        val = minVal;
    }
}