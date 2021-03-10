#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define N 100005

vector<ll> madj[N];

ll numnodos, querys;

//Funcion auxiliar para imprimir vectores
void printvec(vector<ll> v)
{
  vector<ll>::iterator it;
  for(it=v.begin();it!=v.begin()+numnodos;++it) cout<<*it<<" ";
  cout<<endl;
}

//Vector de padres de los nodos, una cadena que es vector de vectores
vector<ll> parent(N);
vector<ll> chain[N];
vector<ll> depth(N);
vector<ll> csz(N);
vector<ll> in(N);
vector<ll> rin(N);
vector<ll> nxt(N);
vector<ll> sma(N);
/*Usamos el vector de profundidad de cada uno de los nodos, el vector
nxt para los nodos siguientes, el vectpr sma para la suma */

ll t=0;

ll left(int pos)
{
  return pos<<1;
}
ll right(int pos)
{
  return (pos<<1)+1;
}
//Funciones auxiliares

void DFSCSZ(ll n=0, ll p=-1, ll d=0)
{
  parent[n]=p; //El padre del nodo 0 es el mismo por eso es -1 en vector de parent
  csz[n]=1;
  depth[n]=d;
  for(auto v: madj[n])
  {
    if(v!=p)
    {
      DFSCSZ(v,n,d+1);
      csz[n]+=csz[v];
      chain[n].push_back(v);
      if(csz[v]>csz[chain[n][0]]) swap(chain[n][0],chain[n].back());
    }
  }
}

void DFSHLD(ll n=0)
{
    in[n]=t++;
    rin[in[n]]=n;
    for(auto v: chain[n])
    {
      nxt[v]=(v==chain[n][0] ? nxt[n]: v);
      DFSHLD(v);
    }
    sma[n]=t;
}

//Calculamos el ancestro más pequeño para dos nodos
ll LCA(int u, int v)
{
  while(nxt[u] != nxt[v])
  {
    if(depth[nxt[u]]<depth[nxt[v]]) swap(u,v);
    u=parent[nxt[u]];
  }
  return depth[u]<depth[v] ? u : v;
}

vector<ll> segment_tree(4*N);
//El segment tree por cada uno de los caminos de las aristas pesadas
vector<ll> lazy(4*N);
//En este caso el st y el lazy solo son vectores
//grandes ya que estamos guardando un valor que
//es la suma
/* Hacemos un segment tree lazy de actualizaciones ya que va a ser más facil
actualizar el valor de un nodo en un rango*/

void add_node(int node, int low, int high)
{
  if (lazy[node]==0) return; //No hay nada que actualizar
  segment_tree[node]+=(high-low+1)*lazy[node];
  if(low!=high)
  {
    lazy[left(node)]+=lazy[node];
    lazy[right(node)]+=lazy[node];
  }
  lazy[node]=0;
}

void update_value(ll begin, ll end,ll x, ll low=0, ll high=-1, ll node=0)
{
  if(high==-1) high=numnodos-1;
  add_node(node,low, high);
  if(high < begin || low> end) return;
  if (low >= begin && high <= end) {
    lazy[node] = x;
    add_node(node, low, high);
    return;
  }
  ll mid = (low + high) / 2;
  update_value(begin, end, x, low, mid, left(node));
  update_value(begin, end, x, mid + 1, high, right(node));
  segment_tree[node] = segment_tree[left(node)] + segment_tree[right(node)];
}

void update_single_value(ll pos,ll x)
{
  update_value(pos,pos,x);
}

ll query(int begin, int end, int low=0, int high=-1, int node=0) {
  if (high == -1) high = numnodos - 1;
  add_node(node, low, high);
  if (high < begin || low > end) return 0;
  if (low >= begin && high <= end) return segment_tree[node];
  ll mid = (low + high) / 2;
  return query(begin, end, low, mid, left(node)) +
      query(begin, end, mid + 1, high, right(node));
}

//El ignore lca es para tomar o no en cuenta el minimo comun
//ancestro minimo comun de dos nodos
ll query_path(int u, int v, bool ignore_lca=false) {
  ll res = 0;
  while (nxt[u] != nxt[v]) {
    if (depth[nxt[u]] < depth[nxt[v]]) swap(u, v);
    res += query(in[nxt[u]], in[u]);
    u = parent[nxt[u]];
  }
  if (depth[u] < depth[v]) swap(u, v);
  res += query(in[v] + ignore_lca, in[u]);
  return res;
}

ll make_query(int u, int v)
{
  ll lca=LCA(u,v);
  bool ignore_lca=true;
  return query_path(u,lca)+query_path(lca,v,ignore_lca,m);
}

void init(vector<ll> vec)
{
  for(int i=0;i<numnodos;i++)
  {
    update_single_value(i,vec[i]);
  }
  cout<<"Valores asignados"<<endl;
}
int main()
{
  cin>>numnodos>>querys;
  vector<ll> tmp(numnodos);
  for(ll i=0;i<numnodos;i++)
  {
    cin>>tmp[i];
  }
  //for(vector<ll>::iterator it=tmp.begin();it!=tmp.end();++it) cout<<*it<<" ";
  //cout<<endl;
  for(ll i=1;i<numnodos;i++)
  {
    ll padre;
    cin>>padre;
    madj[padre].push_back(i);
    madj[i].push_back(padre);
  }
  //Metemos los nodos en la matriz de adyacencia que tiene la siguiente forma
  /*
   0 x,y,t
   1 k x t
  */
  cout<<"Haciendo Descomposición"<<endl;
  DFSCSZ();
  DFSHLD();
  cout<<"Descomposición completa"<<endl;
  init(tmp); //Las actualizaciones con base en el vector
  for(ll j=0;j<querys;j++)
  {
    char op;
    cin>>op;
    if(op=='P')
    {
      ll r1,r2;
      cin>>r1>>r2;
      cout<<make_query(r1,r2);
      cout<<endl;
    }
    if (op=='U')
    {
      ll pos, nval;
      cin>>pos>>nval;
      update_single_value(pos,nval);
      cout<<"Value updated"<<endl;
    }
  }
  cout<<"Querys done"<<endl;
  return 0;
}
