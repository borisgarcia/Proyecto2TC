#include <iostream>
#include "Gramatica.h"
using namespace std;

int main()
{
    Gramatica * g = new Gramatica();
    //g->formar();
    //g->split("HoLA",false);

    NoTerminal *nt1 = new NoTerminal("S");
    nt1->inicial = true;
    g->inicial = nt1;
    NoTerminal *nt2 = new NoTerminal("A");
    NoTerminal *nt3 = new NoTerminal("B");

    nt1->producciones.push_back("bA");
    nt1->producciones.push_back("aB");

    nt2->producciones.push_back("a");
    nt2->producciones.push_back("aS");
    nt2->producciones.push_back("bAA");

    nt3->producciones.push_back("b");
    nt3->producciones.push_back("bS");
    nt3->producciones.push_back("aBB");
    g->produc.push_back(nt1);
    g->produc.push_back(nt2);
    g->produc.push_back(nt3);

    g->check("babaab");


    return 0;
}
