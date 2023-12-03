#ifndef USER_H
#define USER_H

#include <string>
using namespace std;




class user{

public:

void setUsername(string& user) const;
void setPassword(string& pass) const;
string getUserName() const {return userName;}
string getPassword() const {return password;}
user(){userName = " "; password = " ";}
user(string, string);









private:
    string userName;
    string password;
};


#endif