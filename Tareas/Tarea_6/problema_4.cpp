#include <bits/stdc++.h>
#include "BigInt.h"

using namespace std;

#define ll unsigned long long
#define N 11
vector<ll> DP(N,-1); //Usamos porgramación dinámica para calcular el factorial

/*Para determinar cuantos términos hay de la secuencia x^{i1},x2^{i2},x3^{i3}...,xk^{ik}
Tenemos que calcular el número n!/i1!....ik! como k y n son menores a 10 se puede meter lo anterior en un entero
del tipo long long
*/
ll factorial(ll num)
{
    if(DP[num]!=-1) return DP[num];
    else if (num==0) return DP[num]=1;
    else return DP[num]=num*factorial(num-1);
}

ll Coeficient(vector<ll> powers)
{
    ll n=accumulate(powers.begin(),powers.end(),0);
    ll prod=1;
    for(vector<ll>::iterator it=powers.begin();it!=powers.end();++it) prod*=factorial(*it);
    return factorial(n)/prod;
}
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> powers(k);
    for(int i=0;i<k;i++) cin>>powers[i];
    cout<<"Coeficiente del monomio correspondiente: "<<Coeficient(powers)<<endl;
    return 0;
}