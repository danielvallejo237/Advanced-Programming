#include "BigInt.h"
#include <bits/stdc++.h>

using namespace std;

/*Problema de resolución de encontar el último dígito de elevar p a un numero q*/
/*
@Author Daniel Vallejo Aldana 
Licenciatura en Computación */

bool isIn(set<int> conj,int d)
{
    return (conj.find(d)!=conj.end());
}
int last_digit(BigInt p, BigInt q)
{
    set<int> digitos;
    vector<int> units;
    BigInt aux=p;
    int power=1,dig;
    int cont=1;
    while(1)
    {
        dig=aux.get_units();
        if(isIn(digitos,dig)) break;  
        power++;
        aux=p^power;
        digitos.insert(dig);
        units.push_back(dig);
        cont++;    
    }
    return units[(q-1)%(cont-1)];
}
int main()
{
    BigInt p,q;
    while(cin>>p>>q) cout<<"Ultimo digito de "<<p<<"^"<<q<<"= "<<last_digit(p,q)<<endl;
    return 0;
}