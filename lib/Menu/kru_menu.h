#ifndef kru_menu_h
#define kru_menu_h
#include "Arduino.h"
#include "LinkedList.h"
#include "kru_screen.h"

enum KRuMenuItemClickResponseType
{
  EMPTY,
  HORIZONTAL_SUBITEMS,
  VERTICAL_SUBITEMS,
  CLOSE_SUBMENU
};
struct KRuMenuItemClickResponse;
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
  virtual KRuMenuItemClickResponse handleClick();
};

struct KRuMenuItemClickResponse
{
  KRuMenuItemClickResponseType miCRType = EMPTY;
  LinkedList<KRuMenuItem> subItems;
};

class KRuMenu
{
public:
  int topVisibleItem = 0;
  int currentItem = 0;
  int maxItem = -1;
  int firstCol, firstRow = 0;
  KRuScreen *screen;
  KRuMenuItemClickResponse lastResponse;
  LinkedList<KRuMenuItem> menuItems = LinkedList<KRuMenuItem>();
  KRuMenu();
  KRuMenu(LinkedList<KRuMenuItem> items, KRuScreen *scr);
  ~KRuMenu();
  void update(int dir, int btn);
  void addMenuItem(String item, LinkedList<KRuMenuItem> subItems);
  void addMenuItem(KRuMenuItem item);
  void draw();
};
#endif