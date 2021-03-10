/*Resolver el problema de dtpsum, hacemos un update del valor del nodo
y hacemos y calculamos la suma entre dos nodos a, b
*/

#include <bits/stdc++.h>
#define lli long long int

using namespace std;

#define N 100009
//Este es el tammaño máximo de nodos que vamos a tener

//Definimos el segment tree de los caminos
lli nodos;

vector<lli> st(4*N);
vector<lli> sma(4*N); //abreviación de suma

//Funciones necesarias para implementar el segment tree
lli left(lli pos)
{
  return pos<<1;
}
lli right(lli pos)
{
  return (pos<<1)+1;
}

void update(lli n, lli l, lli r, lli idx, lli new_val)
{
  if(l==r)
  {
    st[n]+=new_val;
    return;
  }
  lli mid=(l+r)/2;
  if(idx<=mid)
  {
    update(left(n),l,mid,idx,new_val);
  }
  else update(right(n),mid+1,r,idx,new_val);
  //Lo que queremos calcular es la suma del camino
  st[n]=st[left(n)]+ st[right(n)];
}

lli move(lli n, lli l, lli r, lli i, lli j)
{
  if(i>r || j<l ) return 0; //Ya nos pasamos en el st
  if(i<=l && j>=r) return st[n];
  lli mid=(l+r)/2;
  return move(left(n),l,mid,i,j)+move(right(n),mid+1,r,i,j);
}
vector<lli> par(N);
vector<lli> info[N]; //informacion de los padres e hijos de los nodos
vector<lli> size(N);
vector<lli> depth(N);
vector<lli> nxt(N,-1);

/*El vector info corresponde a una matri de información de conexión*/


//Vamos a necesitar todos estos vectores para la dfs

void DFS(lli n, lli pr=0)
{
  par[n]=pr;
  size[n]=1;
  for(int i=0;i<info[n].size();i++)
  {
    lli g=info[n][i];
    if(g==pr) continue; //De si mismo a si mismo
    depth[g]=depth[n]+1;
    DFS(g,n);
    size[n]+=size[g];
    if(nxt[n]==-1 || size[g] >size[nxt[n]]) nxt[n]=g;
  }
}

//Parte de la descomposición Heavy-light
vector<lli> chain(N); //Guardamos la longitud de la cadena
vector<lli> num(N);
vector<lli> top(N); //Los tops de la cadena
vector<lli> csz(N);

lli cnt=1;
lli all=0;

void HLD(lli n, lli pr=-1)
{
  chain[n]=cnt-1;
  num[n]=all++;
  if(!csz[cnt-1]) top[cnt-1]=n;
  ++csz[cnt-1];
  if(nxt[n]!=-1) HLD(nxt[n],n);
  for(int i=0;i<info[n].size();i++)
  {
    int g=info[n][i];
    if(g==pr || g==nxt[n]) continue;
    ++cnt;
    HLD(g,n);
  }
}

lli computeSum(int a, int b) //Calcular la suma de un nodo al otro
{
  lli resultado=0;
  while(chain[a]!=chain[b])
  {
    cout<<"chains differ"<<endl;
    if(depth[top[chain[a]]]<depth[top[chain[b]]]) swap(a,b);
    lli start= top[chain[a]];
    if(num[a]==num[start]+csz[chain[a]]-1) resultado+=sma[chain[a]];
    else resultado+=move(1,0,nodos-1,num[start],num[a]);
    a=par[start];
  }
  if(depth[a] > depth[b]) swap(a, b);
  resultado += move(1, 0, nodos - 1, num[a], num[b]);
  return resultado;
}

void Update(lli a, lli nval)
{
  update(1,0,nodos-1,num[a],nval);
  int start = num[top[chain[a]]];
  int end = start + csz[chain[a]] - 1;
  sma[chain[a]] = move(1, 0, nodos - 1, start, end);
}


int main()
{
  //Este algoritmo tiene un uso grande en memoria
  //Prueba de las funciones anteriormente diseñadas
  lli querys;
  cin>>nodos>>querys;
  vector<lli> tmp(N);
  for(int i=0;i<nodos;i++)
  {
    cin>>tmp[i];
  }
  info[0].push_back(0);
  for(lli i=1;i<nodos;i++)
  {
    lli parent;
    cin>>parent;
    info[parent].push_back(tmp[i]);
    info[i].push_back(tmp[parent]);
  }

  DFS(0);
  cout<<"Completed DFS"<<endl;
  HLD(0);
  cout<<"Completed Heavy light decomposition"<<endl;
  cout<<"Suma calculada "<<computeSum(2,3)<<endl;
  //Update(3,2);
  //cout<<"Updated completed"<<endl;

  return 0;
}
