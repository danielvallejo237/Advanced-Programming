#include"Treap_simple.h"
//Prueba de la estructura de treap
/* Daniel Vallejo Aldana Licenciatura en Computación*/
/* Problema de las pelotas robadas */
using namespace std;

int main()
{
  srand(time(0));
  int insertions;
  cin>>insertions;
  Treap treap;
  for (int i=0;i<insertions;i++) treap.InsertBV(rand()% 601);
  treap.printInorder(treap.root);
  int k=rand() % 11;
  //cout<<endl<<"Nodo en posicion "<<0<<" "<<treap.getValueInPos(0)<<endl;
  treap.InsertBP(10,8);
  //cout<<"[info] Inserting by position..."<<endl;
  treap.eraseByPos(10);
  return 0;
}
