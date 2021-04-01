/*Solución de problemas de contar triangulos */

#include<bits/stdc++.h>

using namespace std;
#define ll long long 
#define pb push_back
#define MAX_NODE 3001

ll adj[MAX_NODE][MAX_NODE];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    scanf("%lld",&t);
    assert(t<=250);
    while(t--) //Para todos los casos de prueba
    {
        ll n,m;
        scanf("%lld%lld",&n,&m);
        assert(n>=1 && n<=3000);
        fill(&adj[0][0], &adj[n-1][n], false);
        //Hacemos una matriz con puros 0's 
        while(m--)
        {
            ll source, destination;
            scanf("%lld%lld",&source,&destination);
            source--;
            destination--;
            adj[source][destination]=true;
            adj[destination][source]=true;
        }
        ll count=0; //Numero de truangulos que tenemos por test case
        for (ll i=0;i<n;i++)
        {
            for (ll j=i+1;j<n;j++)
            {
                if(!adj[i][j]) continue;
                for(ll k=j+1;k<n;k++)
                {
                    if(adj[j][k] && adj[i][k]) count++;
                }
            }
        }
        printf("%lld\n",count);

        /*Aquí es donde comienza la parte del escaneo de las aristas*/
    }
    return 0;
}
