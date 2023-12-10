#include "diagnostics.h"
#include "inventory.h"
#include <iostream>
#include <string>

using namespace std;

void diagnostics::masterTest(inventory& inv) {
    //inv.loadInventory("stock.txt");
    inv.printInventory();

    inv.updateItemCount("0005");
    inv.updateItemPrice("0006");
    inv.replaceItem("0007");
    inv.printInventory();

    inv.updateItemCount(inv.getUPC("fishing_poles")); //gotta test them poles for quality
    inv.updateItemPrice(inv.getUPC("fishing_poles"));
    inv.replaceItem(inv.getUPC("ham"));
}