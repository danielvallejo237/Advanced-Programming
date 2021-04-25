#include <bits/stdc++.h>

using namespace std;

#define ll long long

//Para que agarre más enteros ya que no usamos enteros negativos

bool isKaprekar(ll n)
{
    if(n==1) return true;

    ll cuad=n*n;
    ll digitos=0;
    while(cuad)
    {
        digitos++;
        cuad/=10;
    }
    cuad=n*n; //Se perdió el cálculo del cuadrado del número
    for(ll i=1;i<digitos;i++)
    {
        ll parts=pow(10,i);
        if(parts==n) continue; 
        ll sum=cuad/parts + cuad % parts;
        if (sum==n) return true;
    }
    return false;
}

ll Lower_Kaprekar_Bound(ll n)
{
    for(int i=n;i>=0;i--) if(isKaprekar(i)) return i;
    return -1;
}
int main()
{
    ll numero;
    cin>>numero;
    cout<<"Cota inferior de numero de Kaprekar: "<<Lower_Kaprekar_Bound(numero)<<endl;
    return 0;
}