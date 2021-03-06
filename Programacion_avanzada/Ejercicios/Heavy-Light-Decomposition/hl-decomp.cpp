#include<bits/stdc++.h>

using namespace std;

/*Los vectores que vamos a usar para la descomposición heavy light son los
siguientes */

vector<int> parent, head, pos, heavy,depth;

//parent y depth guardan el padre y la profundidad de cada nodo
//heavy the child at the other end of the heavy edge from v ?

int cur_pos; //La posición actual en la que estamos


int dfs (int v, vector<vector<int>> const &adj)
{
  /*Esta función recibe como entrada un vértice y la matriz de adyacencia
  de las aristas */
  int size=1;
  int max_child_size=0;
  for(int c:adj[v])
  {
    if(c!=parent[v])
    {
      parent[c]=v;
      depth[c]=depth[v]+1;
      int children_size=dfs(c,adj);
      size+=children_size;
      if(children_size>max_child_size)
      {
        max_child_size=children_size;
        heavy[v]=c;
      }
    }
  }
  return size;
}

void decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

void init(vector<vector<int>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;

    dfs(0, adj);
    decompose(0, 0, adj);
}
int query(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = segment_tree_query(pos[head[b]], pos[b]);
        res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = segment_tree_query(pos[a], pos[b]);
    res = max(res, last_heavy_path_max);
    return res;
}
