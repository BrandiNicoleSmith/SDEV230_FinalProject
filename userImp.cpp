#include "user.h"
//#include "interface.h"
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
    ifstream infile; // file object init
    infile.open("employees.txt"); //opens file ref (* variablize to create custom password file)

    //parallel arrays for usernames and passwords from file
    //size = num of employees in the employees files marked as a number on the first line
    string usernames[5];
    string passwords[5];
    //extract usernames and passwords
    string line;//string container for line
    int lineCount = 0;//line count int var for 
    while (getline(infile, line)) {
        stringstream ss(line); // creating stringstream object for each line as it iterates

        string usernameFieldMarker, savedUsername, passwordFieldMarker, savedPassword; //instantiating string container variables

        //parse data and pass into vars
        if (ss >> usernameFieldMarker >> savedUsername >> passwordFieldMarker >> savedPassword) {
            usernames[lineCount] = savedUsername;
            passwords[lineCount] = savedPassword;
        }
        lineCount++;
    }
    bool flagName = false; //comparison flag for username 
    bool flagPass = false; //comparison flag for password
    
    infile.close();//closes file
	
	
	int userIndex = 0; //username index variable for comparison
    //iterate through extracted usernames and increment userIndex
    for (string i : usernames){
		userIndex++;
        if (i == userName){
            flagName = true;
            break;
        }
    }

    /*iterate through extracted passwords
	if the index of the password matches the username's index, login success (solves password mismatch issue)*/
	int passIndex = 0; //password index variable for comparison
    for (string i : passwords){
		passIndex++;
        if (i == password && (userIndex == passIndex)){
            flagPass = true;
            break;
        }
    }

    if(!flagName){ //if useerrname is incorect, return fail
        cout << "ERROR: username is invalid." << endl;
    }

    if(!flagPass){ //if password is incorrect for that user, return fail
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