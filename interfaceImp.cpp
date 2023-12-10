#include "interface.h"
#include "user.h"
#include "inventory.h"
#include <iostream>

using namespace std;
//constructor
interface::interface (){
    
}
//constructor 2: providing the user object
interface::interface (user u){
    sessionUser = u;
}
//setter for interface's sessionUser field
void interface::setUser(user u){
    sessionUser = u;
    return;
}
//getter for interface's sessionUser field
user interface::getUser(){
    return sessionUser;
}

//method to call the Login subroutine
void interface::loginPrompt()
{
    //loop for login 
    p:
    string username;
    string password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    user login = user(username, password);
    if (login.isValid()){
        cout << "Login Success";
        setUser(login);
        cin.clear();
    }
    else{
        goto p;
        cin.clear();
    }
    //end login loop
}


//function operate the menu, uses a int to enter the choice
bool interface::Menu(inventory& inv)
{
    int choice;
    string input;
    bool loggedOut = false;
    
    q:
    cout << "\n\t\tPlease select an operation" <<endl;
    //prints the menu for the program.

    cout << "1: View Inventory" << endl;
    cout << "2: Update item quantity" << endl;
    cout << "3: Update item price" << endl;
    cout << "4: Replace Item" << endl;
    cout << "5: Save Data" << endl;
    cout << "6: Sign out" << endl;
    cout << "7: Exit" << endl;

    cin >> choice;

    switch (choice) {
        case 1: // Prints the current inventory information
            inv.printInventory();
            break;

        case 2: // Searches by either item name or UPC and alters that items quantity
            cout << "Search by item Name, UPC, or Cancel?" << endl;
            cin >> input;

            if (input == "UPC" || input == "upc") {
                cout << "Enter item UPC: ";
                cin >> input;
                inv.updateItemCount(input);

            } else if (input == "cancel" || input == "Cancel") {
                goto q;

            } else {
                inv.updateItemCount(inv.getUPC(input));
            }
            break;

        case 3: // Searches by either item name or UPC and alters that items price
            inv.updateItemPrice(input);
            cout << "Search by item Name, UPC, or Cancel?" << endl;
            cin >> input;

            if (input == "upc" || input == "UPC") {
                cout << "Enter item UPC: ";
                cin >> input;
                inv.updateItemPrice(input);

            } else if (input == "cancel" || input == "Cancel") {
                goto q;

            } else {
                inv.updateItemPrice(inv.getUPC(input));
            }
            break;

        case 4: // Overwrites all the data points for a specified UPC
            cout << "Notice, this will overwrite the specified UPC.\nPlease enter the UPC of the item you would like to replace. Type 'Cancel' to select a different option." << endl;
            cin >> input;

            if (input == "Cancel" || input == "cancel") {
                goto q;

            } else {
                inv.replaceItem(input);
            }
            break;

        case 5: // Saves the current inventory data to a file of choice
            inv.saveInventory();
            break;

        case 6:
            loggedOut = true;
            return loggedOut;

        case 7:
            exit(0);

        default:
            goto q;
            break;
    }
    if(!loggedOut){
        goto q;
    }
    goto q;
    return false; // End of Switch
}