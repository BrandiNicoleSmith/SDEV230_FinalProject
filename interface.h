#ifndef INTERFACE_H
#define INTERFACE_H

#include "inventory.h"

using namespace std;

class interface{

private:
    user sessionUser;

public:
    interface();
    interface(user u);
    void setUser(user u);
    user getUser();
    void loginPrompt();
    bool Menu(inventory& inv);

};


#endif