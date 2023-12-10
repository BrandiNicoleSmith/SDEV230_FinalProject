#ifndef INVENTORY_H
#define INVENTORY_H

using namespace std;

class inventory {
    private:
        string itemUPC[20];
        string itemName[20];
        int itemQuantity[20];
        double itemPrice[20];
        string itemDescription[20];
        string saveFile;

    public:
        inventory();
        void loadInventory(string); // Loads current inventory records from declared file
        void printInventory() const; // Outputs the values currently loaded into the 5 parallel inventory data arrays
        void updateItemCount(string); // Changes the quantity of an inventory item by the specified amount (Searches by itemUPC)
        void updateItemPrice(string); // Changes the price of an inventory item to the specified price (Searches by itemUPC)
        void replaceItem(string); // Replaces and index position with a completely new item
        string getUPC(string); // Returns the itemUPC of an item when given the itemName
        void saveInventory(); // Saves the current inventory data to the specified file

    //comments
    // As is, any input that the functions can't find in the arrays will just be ignored rather than looping anything

    };

#endif

