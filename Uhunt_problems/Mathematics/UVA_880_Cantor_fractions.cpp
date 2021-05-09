#include <bits/stdc++.h>

using namespace std;

#define lli unsigned long long

/*Descripción:

Tenemos que encontrar el numerador y el denominador de la fracción 
para esto usamos fórmulas en el tour de fracciones de cantor para 
acceder de forma O(1), al valor de la n esima fracción de cantor*/

int main()
{
    ios_base::sync_with_stdio(false);
    lli n;
    while (cin>>n)
    {
        lli denominador;
        lli numerador;
        denominador=(-1+floor(sqrt(1+8*n)))/2;
        numerador=n-(denominador*(denominador+1)/2);
        if(numerador==0) cout<<"1/"<<denominador<<endl;
        else cout<<denominador+2-numerador<<"/"<<numerador<<endl;
    }
    return 0;
}