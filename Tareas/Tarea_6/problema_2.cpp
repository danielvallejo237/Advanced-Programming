#include <bits/stdc++.h>
#include "BigInt.h"

using namespace std;

/*Dado un tablero de ajedréz de pxp con (1<=p<=10^6) ¿De cuantas maneras se pueden colocar dos reinas 
antagonistas para que esten en situación de amenazarse mutuamente? 

Explicación del problema:

Notemos que dos reinas se amenazan mutuamente si se encuentran en la misma vertical, horizontal
o en la diagonal. Además vemos que las reinas tienen libertad de movimiento en cuanto a número de casillas

Notemos primero que el número de posiciones en las cuales podemos poner a las dos reinas en 
un tablero de N x N está dado por

P(n)=n*n*(n*n-1)/2

Ahora, calculemos el número de posiciones en las cuales las reinas se pueden colocar en el
tablero de nxn sin que se amenacen, para esto recordando lo anterior notemos que 
para que dos reinas no se ataquen no deben de quedar en el mismo renglón, columna o diagonales 
por lo tanto el número de posiciones en las cuales las reinas no se atacan es 

NA(n)=n(n-1)(n-2)(3n-1)/6

Por lo tanto el número de posiciones en las cuales las reinas se amenazan es

A(n)=P(n)-NA(n) y en consecuencia A(n)=n*(5*n-1)*(n-1)/3

*/


BigInt getUnstable(BigInt n)
{
    return n*(n*5-1)*(n-1)/3;
}
BigInt getStable(BigInt n)
{
    return n*(n-1)*(n-2)*(n*3-1)/6;
}

int main()
{
    BigInt N;
    while(cin>>N)
    {
        cout<<"Numero de posiciones en que se amenazan las reinas en tablero de "<<N<<" x "<<N<<" :"<<getUnstable(N)<<endl;
    }
    return 0;
}