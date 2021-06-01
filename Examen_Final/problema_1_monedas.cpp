#include <bits/stdc++.h>

//Daniel Vallejo Aldana Licenciatuira en Computación

using namespace std;

/*Calcular el numero munimo que puede ser formado con dos monedas*/



int main()
{
    unsigned int v1,v2;
    cin>>v1>>v2;
    //v1 y v2 deben de ser primos relativos de tal forma que todos los demás enteros se puedan formar
    //Si no tendríamos problemas por ejemplo en formar impares sumando puros pares
    if(__gcd(v1,v2)!=1) cout<<-1<<endl;
    else
    {
        cout<<v1*v2-(v1+v2)+1<<endl;
    }
    return 0;
}