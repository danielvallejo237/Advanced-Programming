/*Implementación para el cálculo de la suma de
un rango i j para la implementación del segment tree*/
#include<bits/stdc++.h>
#include<algorithm>
#define N 10005
using namespace std;
/*Modificando un poco el código podemos calcular la suma, el mínimo,
En este caso calculamos el máximo común divisor de los números del arreglo*/

vector<int> arr(N); // El arreglo puede tener a lo más N elementos
vector<int> st(4*N);

int left(int p)
{
  return p << 1;
}
int right(int p)
{
  return (p<<1) +1;
}

void build(int p, int l, int r)
{
  if(l==r) st[p]=arr[l]; //Condición de paro del algoritmo build
  else
  {
    build(left(p),l,(l+r)/2);
    build(right(p),(l+r)/2+1,r);
    st[p]=__gcd(arr[l],arr[r]); //merge operation para la suma de los elementos
    //st[p]=arr[l]+arr[r];
  }
}

int query(int p, int l, int r, int i, int j) //La parte de la consulta
{
  if(r<i || j<l) return 0; //esta condicion es muy importante, equivale a if(l>r)
  if(l==r) return st[p];
  //cout<<"Sum query"<<endl;
  int p1=query(left(p),l,(l+r)/2,i,j); //Esta es la consulta de la suma de los dos lados del vector
  int p2=query(right(p),(l+r)/2+1,r,i,j); //Si uno no es posible se regresa -1
  return __gcd(p1,p2);
  //return p1+p2;
}

void update(int p, int l, int r, int index, int nv)
{
  if(l==r) st[p]=nv;
  else
  {
    int mid=(l+r)/2;
    if(index>mid)
    {
      update(right(p),mid+1,r,index,nv);
    }
    else
    {
      update(left(p),l,mid,index,nv);
    }
    st[p]=__gcd(st[left(p)],st[right(p)]); //Esto es importante porque estamos cambiando cosas
    //hay que asegurarse de que todos los nodos afectados se cambien
    //st[p]=st[left(p)]+st[right(p)];
  }
}

int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++) cin>>arr[i]; //Aqui depende de donde inicie el asunto
  cout<<"Calling the build function"<<endl;
  build(1,1,n);
  cout<<"Realizando consulta"<<endl;
  cout<<query(1,1,n,2,4)<<endl;
  cout<<"Realizando actualización"<<endl;
  update(1,1,n,2,9);
  arr[2]=10;
  cout<<"Realizando consulta"<<endl;
  cout<<query(1,1,n,2,4)<<endl;
  cout<<"Segment tree construido"<<endl;
  return 0;
}
