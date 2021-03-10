#include "Treap_simple.h"
#include <cmath>
using namespace std;

int main()
{
  long long int pelotas;
  Treap treap;
  cin>>pelotas;
  for (long long int i=0;i<pelotas;i++)
  {
    long long int value;
    cin>> value;
    treap.InsertBP(i,value);
  }
  treap.print();
  cout<<endl;
  long long int instrucciones;
  cin>>instrucciones;
  int peticion;
  // Por el momento solo se considerarán peticiones de la 0 a la 2
  for (long long int j=0;j<instrucciones;j++)
  {
    cin>>peticion;
    if (peticion==0)
    {
      long long int p1,p2;
      cin>>p1>>p2;
      cout<<treap.getMaxbyPos(p1,p2)<<endl;
      treap.print();
    }
    else if (peticion==1)
    {
      long long int p;
      cin>>p;
      treap.eraseByPos(p);
      treap.print();

    }
    else if (peticion==2)
    {
      long long int p1,p2;
      cin>>p1>>p2;
      treap.moveItems(p1,p2);
      treap.print();
    }
    else
    {
      cout<<"Peticion no valida"<<endl;
      exit(1);
    }
  }
  //cout<<"Maximo del arbol "<<treap.root->Max<<endl;
}
