// Construcción de un arbol binario de búsqueda
//Falta la función delete node
#include<bits/stdc++.h>
using namespace std;
#define True 1
#define False 0

typedef struct Node
{
  int value;
  Node *lchild;
  Node *rchild;
  Node(int v)
  {
    value=v;
    lchild=NULL;
    rchild=NULL;
  }
  Node()
  {
    lchild=NULL;
    rchild=NULL;
  }
}Node;

struct BST
{
  Node *root; //La raiz del arbol
  BST()
  {
    root=NULL;
  }
  void insert(int valor)
  {
    Node *tmp=new Node(valor);
    Node *current;
    Node *parent;
    if(root==NULL)
    {
      root=tmp;
    }
    else
    {
      current=root;
      parent=NULL;
      while(1)
      {
        parent=current;
        if(current->value > valor)
        {
          current=current->lchild;
          if(current==NULL)
          {
            parent->lchild=tmp;
            return;
          }
        }
        else
        {
          current=current->rchild;
          if(current==NULL)
          {
            parent->rchild=tmp;
            return;
          }
        }
      }
    }
  }
  int getmax()
  {
    Node *current=root;
    while(current->rchild != NULL)
    {
      current=current->rchild;
    }
    return current->value;
  }
  int getmin()
  {
    Node *current=root;
    while(current->lchild != NULL)
    {
      current=current->lchild;
    }
    return current->value;
  }
  Node *search(int valor) //Regresamos el nodo donde está si no regresamos nulo
  {
    Node *current;
    current=root;
    while(current->value!=valor)
    {
      if(current!=NULL)
      {

          if(current->value > valor)
          {
            current=current->rchild;
          }
          else
          {
            current=current->lchild;
          }

        if(current==NULL) return NULL;
      }
    }
    return current;
  }
  bool isIn(int valor)
  {
    if(search(valor)) return True;
    else return False;
  }
};
int main()
{
  BST arbol;
  arbol.insert(10);
  arbol.insert(14);
  arbol.insert(8);
  cout<<arbol.getmax()<<endl;
  cout<<arbol.getmin()<<endl;
  cout<<arbol.isIn(10)<<endl;
  cout<<arbol.isIn(45)<<endl;
  return 0;
}
