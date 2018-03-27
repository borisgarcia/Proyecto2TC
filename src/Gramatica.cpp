#include "Gramatica.h"

Gramatica::Gramatica()
{
    //ctor
}

Gramatica::~Gramatica()
{
    //dtor
}

void Gramatica::formar()
{
    int cantNoTerminales;
    int cantProdu;
    string e;
    string e_2;

    cout<<"Ingrese la cantidad de no terminales: ";
    cin>>cantNoTerminales;

    NoTerminal * nt = new NoTerminal("S");
    this->inicial = nt;
    cout<<"Ingrese las Cantidad Producciones de S: ";
    cin>>cantProdu;

    for(int x = 0;x<cantProdu;x++)
    {
        cout<<"Ingrese la Produccion #"<<x<<": ";
        cin>>e_2;
        nt->producciones.push_back(e_2);
    }

    produc.push_back(nt);

    for(int x = 0;x<cantNoTerminales;x++)
    {
        cout<<"Ingrese el simbolo del No Terminal #"<<x<<": ";
        cin>>e;
        NoTerminal * n = new NoTerminal(e);
        cout<<"Ingrese las Cantidad Producciones de " <<e<<": ";
        cin>>cantProdu;
        for(int x = 0;x<cantProdu;x++)
        {
            cout<<"Ingrese la Produccion #"<<x<<": ";
            cin>>e_2;
            n->producciones.push_back(e_2);
        }
        produc.push_back(n);
    }
}

vector<string> Gramatica::split(string cadena, bool flag)
{
    string l="";
	vector<string> v;
	for(auto n:cadena)
	{
        if(isupper(n) && flag)
        {
            l = n;
            v.push_back(l);
        }
        else if(!isupper(n) && !flag)
        {
            l = n;
            v.push_back(l);
        }
	}
	return v;
}

void Gramatica::check(string cadena)
{
    NoTerminal * actual = inicial;
    if(_check(actual,actual->producciones,cadena,0)==1)
        cout<<"La Palabra "<<cadena<<" es aceptada!"<<endl;
    else
        cout<<"La Palabra "<<cadena<<" es no aceptada!"<<endl;

}

int Gramatica::_check(NoTerminal *noTerminal, vector<string> vs, string cadena, int cont)
{
    vector<string> casoBase;
    NoTerminal * _casoBase = new NoTerminal(" ");
    if(noTerminal->nombre == " " && cont==cadena.size())
    {
        cout<<"cont==cadena.size"<<endl;
        return 1;
    }
    else if(noTerminal->nombre !=" " && cont<cadena.size())
    {
        bool flag = false;
        cout<<"______________"<<endl;
        cout<<"ElsePrincipal"<<endl;
        for(int x = 0;x<vs.size();x++)
        {
            int b = -1;
            string temp = vs.at(x);
            for(int y = 0;y<temp.size();y++)
            {
                if(isupper(temp.at(y)))
                {
                    stringstream ss;
                    string s;
                    ss << temp.at(y);
                    ss >> s;
                    noTerminal = obtener(s);
                    cout<<"isUpper - "<<s<<endl;
                    b = _check(noTerminal,noTerminal->producciones,cadena,cont);
                    if(b == 3)
                        continue;
                    else if(b == 1)
                        return b;
                }
                else
                {
                    if(temp.at(y)==cadena.at(cont)){
                        cont++;
                        flag = true;
                        cout<<"isLower - "<<temp.at(y)<<endl;
                        b = _check(_casoBase,casoBase,cadena,cont);
                        if(b == 3)
                        continue;
                    else if(b == 1)
                        return b;
                    }
                    else
                        continue;
                }
            }

        }
    }
    return 3;

}

NoTerminal * Gramatica::obtener(string n)
{
    for(int x = 0;x<produc.size();x++)
    {
        if(produc.at(x)->nombre == n)
            return produc.at(x);
    }
    return NULL;
}
