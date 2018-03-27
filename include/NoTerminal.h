#ifndef NOTERMINAL_H
#define NOTERMINAL_H
#include <iostream>
#include <vector>
#include "NoTerminal.h"
using namespace std;

class NoTerminal
{
    public:
        NoTerminal(string n);
        virtual ~NoTerminal();
        vector<string> producciones;
        string nombre;
        bool inicial;
    protected:

    private:
};

#endif // NOTERMINAL_H
