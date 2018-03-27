#ifndef GRAMATICA_H
#define GRAMATICA_H
#include <iostream>
#include <vector>
#include "NoTerminal.h"
using namespace std;
#include <cstddef>
#include <sstream>
#include <string>
class Gramatica
{
    public:
        Gramatica();
        void formar();
        void check(string cadena);
        int _check(NoTerminal *a, vector<string> vs, string cadena, int cont);

        vector<string> alfabeto;
        vector<NoTerminal*> produc;
        NoTerminal * obtener(string n);
        vector<string> split(string c,bool flag);
        NoTerminal * inicial;
        virtual ~Gramatica();

    protected:

    private:
};

#endif // GRAMATICA_H
