#ifndef kru_menu_sets_h
#define kru_menu_sets_h
#include "Arduino.h"
#include "LinkedList.h"
#include "kru_screen.h"
#include "kru_menu.h"
class KRuMenuPlusMinus : public KRuMenu
{
  public:
    float val = 0.0f;
    float valStep = 1.0f;
    float maxVal = 1.0f;
    float minVal = 0.0f;
    String valName;
    KRuMenuPlusMinus(String valName, float step, float maxValue, float minValue, KRuScreen *scr);
    void add();
    void minus();
    virtual void draw();
    virtual void update(int dir, int btn);
};

#endif