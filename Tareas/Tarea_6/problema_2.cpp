#include <bits/stdc++.h>
#include "BigInt.h"

// https://stackoverflow.com/questions/41611489/find-out-the-number-of-ways-in-which-two-queens-intersects-wont-be-stable-on

using namespace std;

/*Dado un tablero de ajedréz de pxp con (1<=p<=10^6) ¿De cuantas maneras se pueden colocar dos reinas 
antagonistas para que esten en situación de amenazarse mutuamente? */

// En un tablero se amenazan n * (5 * n - 1) * (n - 1) / 3

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
    cin>>N;
    cout<<"Numero de posiciones en que se amenazan las reinas en tablero de "<<N<<" x "<<N<<" :"<<getUnstable(N)<<endl;
    return 0;
}