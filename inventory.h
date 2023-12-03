#ifndef INVENTORY_H
#define INVENTORY_H

using namespace std;


class inventory {


public:

int getInventoryCount();
int getUPC(int) const {return UPC;}
inventory() {UPC = 0;}
inventory(int);
void incrementInventory();
void decrementInventory();
void printInventory() const;




private:

int UPC;
int inventoryCount;




};

#endif

