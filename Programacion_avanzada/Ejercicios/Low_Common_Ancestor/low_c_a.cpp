#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define level 18

vector <int> tree[MAXN];
int depth[MAXN];
int parent[MAXN][level];

/*Pre calcular la profundidad para cada uno de los nodos
Esta operación se realiza en orden O(N)*/
void dfs(int cur, int prev)
{
    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;
    for (int i=0; i<tree[cur].size(); i++)
    {
        if (tree[cur][i] != prev)
            dfs(tree[cur][i], cur);
    }
}

/*El cálculo de la matriz dispersa se hace en tiempo O(N log(N))*/
void precomputeSparseMatrix(int n)
{
    for (int i=1; i<level; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            if (parent[node][i-1] != -1)
                parent[node][i] =
                    parent[parent[node][i-1]][i-1];
        }
    }
}

/*Calcular el LCA en un tiempo O(log(N)) */
int lca(int u, int v)
{
    if (depth[v] < depth[u])
        swap(u, v);

    int diff = depth[v] - depth[u];

    for (int i=0; i<level; i++)
        if ((diff>>i)&1)
            v = parent[v][i];
    if (u == v)
        return u;
    for (int i=level-1; i>=0; i--)
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    return parent[u][0];
}

void addEdge(int u,int v)
{
    tree[u].push_back(v);
    tree[v].push_back(u);
}

// Función principal
int main()
{
    memset(parent,-1,sizeof(parent));
    int n = 8;
    addEdge(1,2);
    addEdge(1,3);
    addEdge(2,4);
    addEdge(2,5);
    addEdge(2,6);
    addEdge(3,7);
    addEdge(3,8);
    depth[0] = 0;

    // pre calculando la profundidad de cada uno de los nodos
    dfs(1,0);

    // Calculando la tabla de ancestros a cada uno de los nodos del árbol
    precomputeSparseMatrix(n);

    // Llamando a la función LCA
    cout << "LCA(4, 7) = " << lca(4,7) << endl;
    cout << "LCA(4, 6) = " << lca(4,6) << endl;
    return 0;
}
