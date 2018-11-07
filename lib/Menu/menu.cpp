#include "menu.h"
#include "LinkedList.h"
#include "kru_utils.h"
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

KRuMenuItemClickResponse KRuMenuItem::handleClick()
{
    KRuMenuItemClickResponse res = KRuMenuItemClickResponse();
    if (subItems.size() > 0)
    {
        res.miCRType = HORIZONTAL_SUBITEMS;
        res.subItems = subItems;
    }
    return res;
}

KRuMenu::KRuMenu()
{
    maxItem = 0;
}

KRuMenu::KRuMenu(LinkedList<KRuMenuItem> items, KRuScreen *scr)
{
    menuItems = items;
    maxItem = items.size() - 1;
    screen = scr;
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
        topVisibleItem = 0;
    }

    if (currentItem - screen->height + firstRow + 1 >= 0)
    {
        topVisibleItem = currentItem - screen->height + firstRow + 1;
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

void KRuMenu::draw()
{
    for (int i = topVisibleItem; i < min(topVisibleItem + screen->height - firstRow, menuItems.size()); i++)
    {
        String mi = currentItem == i ? ">" + menuItems.get(i).menuItem : " " + menuItems.get(i).menuItem;
        
        screen->println(0, firstRow + i - topVisibleItem, padRight(mi,screen->width-1));
    }
}