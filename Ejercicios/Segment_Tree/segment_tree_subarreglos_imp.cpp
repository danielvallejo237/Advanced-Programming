/*Problema, encontrar el numero más pequeño mayor o igual a
 un numero en específico, en este caso no hay modificación de
los numeros de entrada*/

#include <bits/stdc++.h>

using namespace std;

#define N 100005
#define INF 100008

int left(int p)
{
  return p<<1;
}
int rigth(int p)
{
  return (p<<1)+1;
}
vector<int> arr(N);
vector<int> st[4*N]; //Es un vector de vectores

void build(int p, int l, int r)
{
  if(l==r) st[p].push_back(arr[l]);
  else
  {
    int mid=(l+r)/2;
    build(left(p),l,mid);
    build(rigth(p),mid+1,r);
    //Como hacemos merge de los elementos hoja del segment tree
    merge(st[l].begin(),st[l].end(),st[r].begin(),st[r].end(),back_inserter(st[p]));
    /*Estamos uniendo dos vectores con la operación merge, al final tendremos solo
    un vector que es el completo*/
  }
}

int query(int p, int l, int r, int i, int j, int x)
{
  /*Donde x corresponde al numero que queremos encontrar*/
  if(l>j || i>r) return INF;
  if(l==r)
  {
    vector<int>::iterator pos=lower_bound(st[p].begin(),st[p].end(),x);
    if(pos!=st[p].end()) return *pos;
    else return INF;
  }
  int mid=(l+r)/2;
  return min(query(left(p),l,mid,i,min(j,mid),x),query(rigth(p),mid+1,r,max(mid+1,i),j,x));
}

//En este caso no existen los updates, solamente suponemos que el arreglo se queda así como está
//Para el caso de los updates debemos de hacer algún tipo de multiset
int main()
{
  int n; //Numero de elementos en el arreglo
  cin>>n;
  for(int i=1;i<=n;i++) cin>>arr[i];
  build(1,1,n);
  int numero;
  cin>>numero;
  cout<<"Segment tree built"<<endl;
  cout<<"Doing query for x= "<<numero<<" :"<<endl;
  cout<<query(1,1,n,1,5,numero)<<endl;
  //Vamos probando por partes el módulo anterior
  return 0;
}

/*Apéndice: Descripción de las funciones lower bound y upper bound
upper bound: iterator pointing to the first element that is greater than value,
or last if no such element is found.

lower_bound: Returns an iterator pointing to the first element in the range [first,last)
 which does not compare less than val.*/
//Bosquejo de la función update para el caso de los 
/*
void update(int v, int tl, int tr, int pos, int new_val) {
    t[v].erase(t[v].find(a[pos]));
    t[v].insert(new_val);
    if (tl != tr) {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
    } else {
        a[pos] = new_val;
    }
}
*/
