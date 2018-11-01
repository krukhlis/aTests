#ifndef kru_menu_h
#define kru_menu_h
#include "Arduino.h"
#include "LinkedList.h"

class KRuMenu
{
public:
  int currentItem = 0;
  int maxItem = -1;
  LinkedList<String> menuItems = LinkedList<String>();
  KRuMenu();
  KRuMenu(LinkedList<String> items);
  void update(int dir, int btn);
};
#endif