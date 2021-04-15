#include <bits/stdc++.h>

using namespace std;
#define ll long long
/*Algoritmo para resolver el problema de la devolución del cambio, dado un numero N
y un conjunto de monedas S={S1,S2,..,Sm} de cuántas formas es posible devolver N en cambio usando
esas monedas*/

/*
Paso 1: Identificar la tabla DP:
    La tabla DP consta de N+1 renglones y M columnas donde los renglones van desde 0 a N y es la cantidad de 
    dinero que se quiere cambiar, M es el id de las monedas disponibles para cambiar

Paso 2: Identificar la recurrencia: 
    La recurrencia es considerar las soluciones que incluyen a la moneda Sm y las que la excluyen
    luego juntarlas sumándolas
*/

ll CoinChange(vector<ll> Monedas, ll N, ll M)
{
    //Creación de la tabla DP, en este caso es un arreglo de dos dimesniones
    vector<vector<ll>> DP(N+1,vector<ll>(M));
    for(ll j=0;j<M;j++)
    {
        DP[0][j]=1; //Solo hay una solución
    }
    for(ll i=1;i<=N;i++)
    {
        for(ll j=0;j<M;j++)
        {
            //Aquí considerar los dos casos, las soluciones que contienen a Sm y las que no
            ll cont,notcont;
            cont=(i-Monedas[j]>=0) ? DP[i-Monedas[j]][j]:0;
            notcont=(j>=1) ? DP[i][j-1] : 0;
            DP[i][j]=cont+notcont;
        }
    }
    return DP[N][M-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll M,N;
    cin>>N>>M;
    vector<ll> Coins(M);
    for(int i=0;i<M;i++)
    {
        cin>>Coins[i];
    }
    sort(Coins.begin(),Coins.begin()+M);
    cout<<"Formas de dar cambio: "<<CoinChange(Coins,N,M)<<"\n\n";
    return 0;
}