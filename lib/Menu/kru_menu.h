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
class KRuMenuItem;

typedef KRuMenuItemClickResponse (*menuItemCallBack)(String);

class KRuMenuItem
{
public:
  String menuItem;
  menuItemCallBack clickCallBack = NULL;
  LinkedList<KRuMenuItem> subItems;
  KRuMenuItem();
  KRuMenuItem(String item, LinkedList<KRuMenuItem> sItems, menuItemCallBack cb);
  KRuMenuItem(String item, menuItemCallBack cb);
  ~KRuMenuItem();
  bool hasSubItems();
  int subItemsCnt();
  virtual KRuMenuItemClickResponse handleClick();
  KRuMenuItemClickResponse defaultClickHandler();
  void func(KRuMenuItemClickResponse (*f)(String));
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
  virtual void update(int dir, int btn);
  void addMenuItem(String item, LinkedList<KRuMenuItem> subItems, menuItemCallBack cb);
  void addMenuItem(KRuMenuItem item);
  virtual void draw();
};
#endif