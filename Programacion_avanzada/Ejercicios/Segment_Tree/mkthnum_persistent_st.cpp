/*Programación del algoritmo mkthnum usnado
segment tree persistentes*/

#include<bits/stdc++.h>
using namespace std;

#define pb(a) push_back(a)
#define N 50005
#define ll long long int
vector<ll> arr(N);

struct Vertex
{
    Vertex *l, *r;
    ll sum;
    Vertex(ll val)
    {
      this->l=NULL;
      this->r=NULL;
      this->sum=val;
    }
    Vertex(Vertex *l, Vertex *r) //Esto es un poco más entendible usando el apuntador this en lugar de las definiciones implícitas
    {
      this->l=l;
      this->r=r;
      this->sum=0;
      if(this->l) sum+=this->l->sum;
      if(this->r) sum+=this->r->sum;
    }
    /*Recordemos que en cada nodo guardamos la suma de los dos nodos hijos
     por tal razón hacemos un constructor que a la vez funcione como
     la función merge de los segment tree*/
    //Constructores del segment tree persistente
};

Vertex *build(ll l, ll r)
{
	/*Al igual que en el caso anterior aquí debemos de construir el árbol
	de segmentos persistente para esa información */
  /*De acuerdo a la idea de la solución del ejercicio se nos pide inicializar un st vacío */
  if(l==r) return new Vertex(0); //La cuenta se incia en 0
  ll mid=(l+r)/2;
  return new Vertex(build(l,mid),build(mid+1,r)); //Hacemos las construcciones pertinentes del st
}

Vertex *update(Vertex *v,ll l, ll r, ll pos)
{
  if(l==r) return new Vertex(v->sum+1);
  ll mid=(l+r)/2;
  if(pos<=mid)
  {
    return new Vertex(update(v->l,l,mid,pos),v->r); //Aqui estamos juntando los nodos de la estrucutra persistente
  }
  else return new Vertex(v->l,update(v->r,mid+1,r,pos));
}

/*ll find_kth(Vertex *vl, Vertex *vr,ll l, ll r, ll k)
{
  /*Idea de lo anterior: Calculamos un histograma parcial sobre el segmento
  que se quiere [l,r] haceiendo la resta de las dos raices r_{r}-r_{l-1} para poder caclular
  dicho histograma, luego encontramos el k ésimo sobre ese intervalo
  Lo que se busca regresar es una posición*//*
  if(l==r) return l;
  ll mid=(l+r)/2;
  ll leftcount= vr->l->sum - vl->l->sum;
  if(leftcount>=k)
  {
    return find_kth(vl->l,vr->l,l,mid,k);
  }
  return find_kth(vl->r,vr->r,mid+1,r,k-leftcount);
}*/

ll find_kth(Vertex* vl, Vertex *vr, ll tl, ll tr, ll k) {
    if (tl == tr)
        return tl;
    ll tm = (tl + tr) / 2, left_count = vr->l->sum - vl->l->sum;
    if (left_count >= k)
        return find_kth(vl->l, vr->l, tl, tm, k);
    return find_kth(vl->r, vr->r, tm+1, tr, k-left_count);
}

vector<Vertex*> roots(N); //Esto se debe de modificar por problema

int main() {
  //Función Main o función principal del código
  ll n;
  cin>>n;
  roots.pb(build(0,N+1));
  cout<<"Persistant tree built"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
    roots.pb(update(roots.back(),0,N+1,arr[i]));
  }
  cout<<"Constructed segment tree"<<endl;
  cout<<"Doing querys"<<endl;
  cout<<find_kth(roots[1],roots[4],0,N+1,2)<<endl;;
  return 0;
}
