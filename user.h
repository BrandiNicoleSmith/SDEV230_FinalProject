#ifndef USER_H
#define USER_H

#include <string>
using namespace std;




class user{

public:

void setUsername(string name);
void setPassword(string pass);
string getUserName() const {return userName;}
string getPassword() const {return password;}
user();
user(string name, string pass);
bool isValid();



private:
    string userName;
    string password;
};


#endif