#ifndef DIAGNOSTICS_H
#define DIAGNOSTICS_H

#include "inventory.h" // Include the inventory header file

class inventory; // Forward declaration of the inventory class

class diagnostics
{
public:
    void masterTest(inventory& inv);
};

#endif