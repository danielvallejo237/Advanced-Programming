//Solucion del problema mkthnum usando estructuras persistentes
/*En el caso de las estructuras persistentes si consideramos
al segment tree como un árbol entonces cambia un poco la función */
#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define N 50005
#define M 50010
#define pb(a) push_back(a)

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

vector<Vertex*> roots;

Vertex *build(ll l, ll r)
{
  if(l==r) return new Vertex(arr[l]); //construcción de los nodos hoja
  ll mid=(l+r)/2;
  return new Vertex(build(l,mid),build(mid+1,r));
}

ll getSum(Vertex *v, ll l, ll r,ll i, ll j)
{
  if(i>j) return 0;
  if(i==l && j==r) return v->sum; /*No interesa llegar hasta los nodos
  hoja sino hasta el segmento que cumpla el rango que estamos buscando*/
  ll mid=(l+r)/2;
  ll s1=getSum(v->l,l,mid,i,min(mid,j));
  /* Generalmente en las consultas hay que considerar lo siguiente
  ->Calcular la suma de: l hasta min(medio,r); Puede que r esté antes que el medio
  ->Calcular la suma de: max(medio+1,l), puede que el promedio sea menor que la l
  */
  ll s2=getSum(v->r,mid+1,r,max(mid+1,i),j);
  return s1+s2;
}


Vertex *update(Vertex *v, ll l, ll r, ll pos, ll new_val)
{
  if(l==r) return new Vertex(new_val);
  ll mid=(l+r)/2;
  /*Si la posicion es mas pequeña que el medio entonces hay que actualizar
  el hijo izquierdo, si no al derecho*/
  if(pos<=mid)
  {
    return new Vertex(update(v->l,l,mid,pos,new_val),v->r);
  }
  else
  {
    return new Vertex(v->l,update(v->r,mid+1,r,pos,new_val));
  }
}
int main()
{
  //fill(arr.begin(),arr.end());
  ll n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
  }
  roots.pb(build(1,n));
  cout<<"Segment tree built "<<endl;
  cout<<"Calculando suma: "<<getSum(roots.back(),1,n,1,4)<<endl;
  cout<<"Realizando update"<<endl;
  roots.pb(update(roots.back(),1,n,4,100));
  cout<<"Calculando suma actualizada: "<<getSum(roots.back(),1,n,1,4)<<endl;
  cout<<"[info] Conclusion exitosa del algoritmo "<<endl;
  return 0;
}
