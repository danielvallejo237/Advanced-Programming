/*Idea principal del problema:

La idea del problema es guardar en cada una de las casillas del grid el numero de ratas que se matarían si
se pusiera la bomba en dicha posición. Para esto calculamos el área de devastancion de la bomba sin que se salga
de los límites establecidos por el problema [0,1024], al final solo agarramos la posición con el mayor valor de 
ratas muertas por la explosión de la bomba de veneno e imprimimos la información pedida*/

//Este algoritmo se resuelve en orden O(n^{3}), siendo la inicialización de las poblaciones la operación más costosa

/*
@Author Daniel Vallejo Aldana
Licenciatura en computación
*/

#include<bits/stdc++.h>

using namespace std;
#define ll long long 
#define pb push_back
#define GRID_SIZE 1025
#define INF 10000000
ll grid[GRID_SIZE][GRID_SIZE];

ll maxi(ll a, ll b)
{
    return (a>b) ? a:b;
}
ll mini(ll a, ll b)
{
    return (a<b) ? a:b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll scenarios;
    scanf("%lld",&scenarios);
    while(scenarios--)
    {
        fill(&grid[0][0],&grid[GRID_SIZE-1][GRID_SIZE],0);
        ll d; //d es la fuerza con la que 
        scanf("%lld",&d); //El radio de destrucción de las bombas
        ll populations;
        scanf("%lld",&populations);
        while(populations--)
        {
            ll x,y,ratas;
            scanf("%lld%lld%lld",&x,&y,&ratas);
            ll lx=maxi(0,x-d); 
            ll rx=mini(x+d,1024);  //Hay que guardar la suma de las ratas que matamos si nos situamos en dicha posición
            ll ly=maxi(0,y-d);
            ll ry=mini(y+d,1024);//Hacemos la matriz de las poblaciones de las ratas
            //Según el problema se asegura de que las posiciones que tomemos serán posiciones válidas
            for(ll i=lx;i<=rx;i++)
            {
                for(ll j=ly;j<=ry;j++) grid[i][j]+=ratas; 
            }
        }
        ll maximo=-INF;
        ll xcor,ycor;
        for(ll i=0;i<GRID_SIZE-1;i++)
        {
            for(ll j=0;j<GRID_SIZE-1;j++)
            {
                if(grid[i][j]>maximo)
                {
                    maximo=grid[i][j];
                    xcor=i;
                    ycor=j;
                }
            }
        }
        printf("%lld %lld %lld\n",xcor,ycor,maximo);

    }
    return 0;
}