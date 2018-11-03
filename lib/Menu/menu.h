#ifndef kru_menu_h
#define kru_menu_h
#include "Arduino.h"
#include "LinkedList.h"

class KRuMenuItem
{
public:
  String menuItem;
  LinkedList<KRuMenuItem> subItems;
  KRuMenuItem();
  KRuMenuItem(String item, LinkedList<KRuMenuItem> sItems);
  KRuMenuItem(String item);
  ~KRuMenuItem();
  bool hasSubItems();
  int subItemsCnt();
  virtual void handleClick();
};

class KRuMenu
{
public:
  int currentItem = 0;
  int maxItem = -1;
  LinkedList<KRuMenuItem> menuItems = LinkedList<KRuMenuItem>();
  KRuMenu();
  KRuMenu(LinkedList<KRuMenuItem> items);
  ~KRuMenu();
  void update(int dir, int btn);
  void addMenuItem(String item, LinkedList<KRuMenuItem> subItems);
  void addMenuItem(KRuMenuItem item);
};
#endif