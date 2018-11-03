#include "menu.h"
#include "LinkedList.h"

KRuMenuItem::KRuMenuItem()
{
    ; //this constructor should neve be used!
}
KRuMenuItem::KRuMenuItem(String item, LinkedList<KRuMenuItem> sItems)
{
    menuItem = item;
    subItems = sItems;
}

KRuMenuItem::KRuMenuItem(String item)
{
    menuItem = item;
    subItems = LinkedList<KRuMenuItem>();
}

KRuMenuItem::~KRuMenuItem()
{
    subItems.clear();
}

bool KRuMenuItem::hasSubItems()
{
    return subItems.size() > 0;
}

int KRuMenuItem::subItemsCnt()
{
    return subItems.size();
}

void KRuMenuItem::handleClick()
{
    //default implementation is blank
}

KRuMenu::KRuMenu()
{
    maxItem = 0;
}

KRuMenu::KRuMenu(LinkedList<KRuMenuItem> items)
{
    menuItems = items;
    maxItem = items.size() - 1;
}

KRuMenu::~KRuMenu()
{
    menuItems.clear();
}

void KRuMenu::update(int dir, int btn)
{
    currentItem += dir;
    if (currentItem < 0)
    {
        currentItem = maxItem;
    }
    if (currentItem > maxItem)
    {
        currentItem = 0;
    }
}

void KRuMenu::addMenuItem(String item, LinkedList<KRuMenuItem> subItems)
{
    KRuMenuItem menuItem = KRuMenuItem(item, subItems);
    menuItems.add(menuItem);
}

void KRuMenu::addMenuItem(KRuMenuItem item)
{
    menuItems.add(item);
}