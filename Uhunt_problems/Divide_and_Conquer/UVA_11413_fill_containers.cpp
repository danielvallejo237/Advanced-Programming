#include <bits/stdc++.h>

using namespace std;

#define ll long long 

/*Problema de Filling Containers, usando el problema de divide y vencerás*/

//barcos y se manda el tamaño de los contenedores
bool FillAllContainers(const vector<int>&barcos, int m, int C)
{
    int container=1;
    int capacity=C;
    for(int i=0;i<barcos.size();i++)
    {
        if (barcos[i]>C) return false;
        if(barcos[i]>capacity)
        {
            if(container==m) return false; //Ya todos los contenedores fueron llenados
            ++container;
            capacity=C;
        }
        capacity-=barcos[i];
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m)
    {
        vector<int> vessels(n);
        for(int i=0;i<n;i++)
        {
            cin>>vessels[i];
        }
        int L=1, U=1000000000, C = 0;
        //La forma de buscar la capacidad que correposnde a la que es maximal se hace mediante una búsqueda binaria
        //La condición de paro es hasta que nos quede que Left es igual a Right es decir estamos en un elemento
        while(L<=U)
        {
            int mid=(L+U)/2;
            if(FillAllContainers(vessels,m,mid))
            {
                C=mid;
                U=mid-1;
            }
            else L=mid+1;
        }
        cout<<C<<endl;
    }
    return 0;
}