/*
Solution Requirements

A working application using at least two classes (25 points). <- hopefully underway

Implementing a modular approach by using functions (10 points). <- done :)

Use at least two files in your application. (10 points). <-done :)

Include the usage of at least two arrays (10 points). <- done :)

Implement secure coding best practices (10 points). <- done :)

Validation testing (10 points). <- done :)

Develop an appropriate set of test data to fully validate the program against.
The data sets you tested against.
A brief written explanation of the results of your tests and what you had to fix.
Screen shots of your good test data working. (INCLUDE in user manuel: Written explaination of tests)

Do below in final post-coding phase:
User manual (10 points).<- done :)
You will write and submit a User's manual for your final project and submit it according to the instructions in the attached file.

Documentation of source code (10 points). <-  done :)
You will fully document (comment) the C++ source code with appropriate comments including:
A brief explanation of the purpose of each module (Sub) at the beginning of each Sub. (A header's comment)
Explanation of the purpose of each variable where it is declared. (An end line comment)
Line by line, or at least section by section comments within the code, explaining what the line/section does.

The link of the GitHub repository for your final project (5 points). <- done :)
total points tracker:
80/100
Current Phase: Bugfixing
*/

//necessary includes:
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
#include "interface.h"



using namespace std;


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

    string filename = "stock.txt";
    


    inventory invent = inventory();
    invent.loadInventory(filename);
    interface i = interface();
    l:
    i.loginPrompt();
    if (i.Menu(invent)){
        goto l;
    }
    

    return 0;
}