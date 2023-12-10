#include "user.h"
#include "interface.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;

//setter for username's field
void user::setUsername(string name)
{
    userName = name;
}

//setter for user's password field
void user::setPassword(string pass)
{
    password = pass;
}

//Constructor 1: username and password provided
user::user(string name, string pass)
{

    setUsername(name);
    setPassword(pass);

}
//Constructor 2: no args provided
user::user()
{
    userName = "N/A";
    password = "N/A";
}


//validates the user's username and password against the usernames and passwords stored in the employees.txt file
bool user::isValid() 
{
    ifstream infile;
    infile.open("employees.txt");

    //parallel arrays for usernames and passwords from file
    //size = num of employees in the employees files marked as a number on the first line
    string usernames[5];
    string passwords[5];
    //extract usernames and passwords
    string line;
    string contents;
    int lineCount = 0;
    while (getline(infile, line)) {
        stringstream ss(line);

        string a,b,c,d;

        //parse data and pass into vars
        if (ss >> a >> b >> c >> d) {
            usernames[lineCount] = b;
            passwords[lineCount] = d;
        }
        lineCount++;
    }
    bool flagName = false;
    bool flagPass = false;
    
    infile.close();

    //iterate through extracted usernames
    for (string i : usernames){
        if (i == userName){
            flagName = true;
        }
    }
    //iterate through extracted passwords
    for (string i : passwords){
        if (i == password){
            flagPass = true;
        }
    }

    if(!flagName)
    {
        cout << "ERROR: username is invalid." << endl;
    }

    if(!flagPass)
    {
        cout << "ERROR: password is invalid." << endl;
    }

    //flag comparison for final return evaluation:
    if (flagName && flagPass){
        return true;
    }
    else{
        return false;
    } 
    
}