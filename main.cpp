/*
Solution Requirements
A working application using at least two classes (25 points). <- hopefully underway

Implementing a modular approach by using functions (10 points). <- underway

Use at least two files in your application. (10 points). <-done :)

Include the usage of at least two arrays (10 points). <- product/upc parallel arrays

Implement secure coding best practices (10 points). <- 

Validation testing (10 points). <- 

Develop an appropriate set of test data to fully validate the program against.
The data sets you tested against.
A brief written explanation of the results of your tests and what you had to fix.
Screen shots of your good test data working.

User manual (10 points).<- 
You will write and submit a User's manual for your final project and submit it according to the instructions in the attached file.

Documentation of source code (10 points). <-  
You will fully document (comment) the C++ source code with appropriate comments including:
A brief explanation of the purpose of each module (Sub) at the beginning of each Sub. (A header's comment)
Explanation of the purpose of each variable where it is declared. (An end line comment)
Line by line, or at least section by section comments within the code, explaining what the line/section does.

The link of the GitHub repository for your final project (5 points). <- done :)
total points tracker:
15/

*/


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include "inventoryImp.cpp" // Stores inventory item information as a class variable
#include "diagnosticsImp.cpp" // Feedback, Crash Report, Notifications
#include "userImp.cpp" // Class for handling and storing user information, Name, and Password
#include "interfaceImp.cpp" // Handles user interface functions
//Header files




using namespace std;

user creds[5];


//prints the menu for the program.
void printMenu(){
    cout << ""<< endl;
    cout << ""<< endl;
    cout << ""<< endl;
    cout << ""<< endl;
    cout << ""<< endl;
    cout << ""<< endl;
    cout << ""<< endl;
    cout << ""<< endl;
    cout << ""<< endl;

}


//return true if password/username is in file (hardmode: pattern match, nightmare mode: hash the passwords and usernames), else false
bool validateCreds(string username = "N/A", string password = "N/A"){
    if(true){
        
        return true;
    }
    else{
        return false;
    }
}

// Iterates through the file it was given (stock.txt), and writes its contents into arrays. (currently set to write to a "struct" that does not exist in this context)
/*void parseFile(string filename)
{
    ifstream file(filename);
        int lineCount = 0;
        string line;
        while (getline(file, line) && lineCount < 20) {
            stringstream ss(line);
            int upc, itemCount;
            string itemName;
            double itemPrice;

            if (ss >> upc >> itemName >> itemCount >> itemPrice) {
                studentType dataElement{upc, itemName, itemCount, itemPrice}; //needs altering at some point to write as class variable
                arr[lineCount++] = dataElement;
            } else {
                cerr << "Data format or read error on line " << line << endl;
            }
        }
        file.close();
}*/


void loadUsers(){
    employees = file.open("employees.txt");
    // parse file, \n\n is new user object|| username: --> user.username, password --> user.password
    employees.close();
}

/*
launch program
load users from file and store in userInfo array
login
output file
modify -> menu (add, delete, modify itemCount)
reprint after changes
*/
int main()
{
    template <typename T>;
    int size = 10; //size for arrays
    string filename = "stock.txt";
    T products<T>[size]; 
    T upcs<T>[size];

    loadUsers();
    //loop for login (possible feature: after 3 attempts, close program with sassy message)
    // Replace this with function call?
    p:
    string username;
    string password;
    cout << "Enter Username: ";
    cin >>username;
    cout << "Enter Password: ";
    cin >>password;
    if (validateCreds(username, password)){
        cout << "Login Success";
    }
    else{
        cout << "Username or Password incorrect.";
        goto p;
    }
    //end login loop





    //menu loop begin
    q:
    printMenu();
    cout<< "Enter choice: ";
    int choice;
    
    switch(choice){
        case 1: //menu modify inventory
            break;
        case 2: //menu delete inventory item
            break;
        case 3: //menu add inventory item
            break;
        case 4: //print current inventory
            break;
        case 5: //exit
            break;
        default:
            cout << "Please choose from the above options";
    }
    //parseFile(filename)
    //menu loop end
    return 0;
}