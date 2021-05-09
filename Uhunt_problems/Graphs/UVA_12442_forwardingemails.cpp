#include <bits/stdc++.h>

using namespace std;

//Necesitamos hace una búsqueda en profundidad por lo que necesitamos implementar
// El algoritmo de la DFS
vector<int> longitud(50005);
bitset<50005> visited; //Nos dice si los nodos han sido visitados o no
vector<int> graph(50005);

int DFS(int n)
{
    visited[n]=true;
    longitud[n]=0; //Apenas comenzamos
    if(!visited[graph[n]])
    {
        longitud[n]+=(DFS(graph[n])+1);
    }
    visited[n]=false;
    return longitud[n];
}

int main()
{
    int cont=1;
    int testcases,n,u,v;
    cin>>testcases;
    while(testcases--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            visited[i]=false;
            longitud[i]=-1;
        }
        for (int i=0;i<n;i++)
        {
            cin>>u>>v;
            graph[u]=v;
        }
        int resultado,res,mx;
        mx=-1;
        for(int i=1;i<=n;i++)
        {
            resultado=(longitud[i]==-1) ? DFS(i) :longitud[i];
            if(resultado>mx)
            {
                mx=resultado;
                res=i;
            }
        }
        cout<<"Case "<<cont<<": "<<res<<"\n";
        cont++;
    }
    return 0;
}