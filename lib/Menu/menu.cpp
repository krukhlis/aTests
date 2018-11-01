#include "menu.h"
#include "LinkedList.h"

KRuMenu::KRuMenu()
{
    //menuItems = items;
    //maxItem = items.size()-1;
    maxItem = 0;
}

KRuMenu::KRuMenu(LinkedList<String> items)
{
    menuItems = items;
    maxItem = items.size() - 1;
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