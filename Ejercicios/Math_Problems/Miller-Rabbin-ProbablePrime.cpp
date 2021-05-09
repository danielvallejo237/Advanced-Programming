#include <bits/stdc++.h>

using namespace std;

#define lli unsigned long int

namespace prim{

bool isPrime(lli num)
{
    if(num==1 || num==2) return true;
    if(num==0) return false;
    for (lli i=2;i<=sqrt(num);++i)
    {
        if (num % i ==0)
        {
            return false;
        }
    }
    return true;
}

lli modPow(lli b,lli e, lli md)
{
    lli rm=1;
    lli bb= b%md;
    while(e)
    {
        if(e%2)
        {
            rm=(rm*bb)%md;
        }
        e>>=1;
        bb=(bb*bb)%md;
    }
    return rm;
}

bool MillerRabbin(lli n, int c)
{
    //c es el numero de ensayos que vamos a hacer
    //Entre más grande es el valor de c mayor es la probabilidad de que el resultado encontrado sea correcto
    if(n<2 || (n%2)==0) return false;
    if(n==2) return true;
    lli d=n-1;
    int s=0;
    while(d%2==0)
    {
        d>>=1;
        s++;
    }
    lli b;
    for(int k=0;k<c;k++)
    {
         lli x=2+rand()%(n-3);
         b=modPow(x,d,n);
         if((b==1)||(b==n-1)) continue; //Test inconcluso
         for (int i=1;i<s;i++)
         {
             b=(b*b)%n;
             if(b==n-1) break; //Otro test inconcluso
         }
         if(b!=n-1) return false;
    }
    return true; //Todos los tests inconclusos
}
};

int main()
{
    lli n;
    cin>>n;
    cout<<"Exact prime test: "<<prim::isPrime(n)<<endl;
    cout<<"Miller rabbin test: "<<prim::MillerRabbin(n,10)<<endl;
    return 0;
}