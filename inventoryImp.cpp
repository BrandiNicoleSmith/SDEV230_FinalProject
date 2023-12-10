#include "inventory.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

// Constructor
inventory::inventory() {

}

// Gets current inventory count from declared file
void inventory::loadInventory(string filename) {
    saveFile = filename;
    ifstream file(filename);
    int lineCount = 0;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);

        string upc, name, description;
        int quantity;
        double price;

    // Extract data and perform checks
        if (ss >> upc >> name >> quantity >> price >> description) {
            itemUPC[lineCount] = upc;
            itemName[lineCount] = name;
            itemQuantity[lineCount] = quantity;
            itemPrice[lineCount] = price;
            itemDescription[lineCount] = description;
        } else {
            cerr << "Error reading line: " << line << endl;
        }
        lineCount++;
    }
    cout << "loadInventory() has finished..." << endl;
}


// Outputs the values currently loaded into the 5 parallel inventory data arrays
void inventory::printInventory() const{
    cout << "\t\t\tCurrent Inventory Records" << endl;
    for (int i = 0; i < 20; i++) {
        cout << itemUPC[i] << " " << itemName[i] << " " << itemQuantity[i] << " $" << itemPrice[i] << " " << itemDescription[i] << endl;
    }
    cout << "\n";
}


// Finds the item specified by UPC and allows the updating of it's associated "itemQuantity"
void inventory::updateItemCount(string upc){
    int input = 0;
    int index = -1;

    for (int i = 0; i < 20; i++) {
        if (itemUPC[i] == upc) {
            index = i;
        }
    }

    if (index == -1) {
        cout << "Unable to find " << upc << " in inventory list." << endl;
    } else {
        cout << "What is the updated inventory count for " << itemName[index] << "?" << endl;
        cin >> input;

        itemQuantity[index] = input;

        cout << "Here is the updated inventory listing:\n";
        cout << itemUPC[index] << " " << itemName[index] << " " << itemQuantity[index] << " $" << itemPrice[index] << " " << itemDescription[index] << endl;
    }
}


// Finds the item specified by UPC and allows the updating of it's associated "itemPrice"
void inventory::updateItemPrice(string upc) {
    double input = 0.0;
    int index = -1;

    for (int i = 0; i < 20; i++) {
        if (itemUPC[i] == upc) {
            index = i;
        }
    }

    if (index == -1) {
        cout << "Unable to find " << upc << " in inventory list." << endl;
    } else {
        cout << "What is the updated price for " << itemName[index] << "?" << endl;
        cin >> input;

        itemPrice[index] = input;

        cout << "Here is the updated inventory listing:\n";
        cout << itemUPC[index] << " " << itemName[index] << " " << itemQuantity[index] << " $" << itemPrice[index] << " " << itemDescription[index] << endl;
    }
}


// Overwrites all information associated with the specified index
void inventory::replaceItem(string upc) {
    string iName = "";
    int iCount = 0;
    double iPrice = 0.0;
    string iDesc = "";

    int index = -1;

    for (int i = 0; i < 20; i++) {
        if (itemUPC[i] == upc) {
            index = i;
        }
    }

    if (index == -1) {
        cout << "Unable to find " << upc << " in inventory list." << endl;
    } else {
        cout << "Enter the name for the new item." << endl;
        cin >> iName;
        itemName[index] = iName;
        cout << "Enter the description for the new item." << endl;
        cin >> iDesc;
        itemDescription[index] = iDesc;
        cout << "Enter the price." << endl;
        cin >> iPrice;
        itemPrice[index] = iPrice;
        cout << "How many of this item are in stock." << endl;
        cin >> iCount;
        itemQuantity[index] = iCount;

        cout << "The new listing for index " << index << " is:" << endl;
        cout << itemUPC[index] << " " << itemName[index] << " " << itemQuantity[index] << " $" << itemPrice[index] << " " << itemDescription[index] << endl;
    }
}


// Finds the UPC associated with the provided item name
string inventory::getUPC(string name) {
    string iUPC = "";
    string convName = "";
    int index = -1;

    for (auto& x : name) {
        x = tolower(x);
    }

    for (int i = 0; i < 20; i++) {
        convName = itemName[i];

        for (auto& x : convName) {
            x = tolower(x);
        }

        if (convName == name) {
            index = i;
        }
    }

    if (index == -1) {
        cout << "Unable to find " << name << " in inventory list." << endl;
    }

    return itemUPC[index];
}


// Saves the current dataset to the specified file
void inventory::saveInventory() {
    ofstream outFile(saveFile);

    for (int i = 0; i < 20; i++) {
        outFile << itemUPC[i] << " " << itemName[i] << " " << itemQuantity[i] << " " << itemPrice[i] << " " << itemDescription[i] << endl;
    }

    outFile.close();
    cout << "File has saved" << endl;
}