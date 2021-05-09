#include <bits/stdc++.h>

using namespace std;

#define MAXINT 400000 //Tamaño máximo del problema
#define li64 long long
/*Resolveremos este problema con precálculo de la suma de los gcd */

vector<li64> aux(MAXINT+10);
vector<li64> suma(MAXINT+10,0);

void precalcular()
{
    aux[1]=1;
    for(int i=2;i<=MAXINT;i++)
    {
        if(aux[i]==0)
        {
            aux[i]=i-1;
            for(int j=i+i;j<=MAXINT;j+=i)
            {
                if(aux[j]==0) aux[j]=j;
                aux[j]=aux[j]-aux[j]/i;
            }
        }
    }
    for (int i=1;i<=MAXINT;i++)
    {
        for(int j=i+i;j<=MAXINT;j+=i)
        {
            suma[j]=suma[j]+(li64)(i*aux[j/i]);
        }
    }
    for (li64 i=1;i<=MAXINT;i++)
    {
        suma[i]+=suma[i-1];
    }
}

int main()
{
    li64 n;
    precalcular();
    while(cin>>n && n!=0)
    {
        cout<<suma[n]<<endl;
    }
    return 0;
}