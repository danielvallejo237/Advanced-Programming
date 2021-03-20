/* Implementación de la estructura de treap con las funciones split,merge, insert y delete
por las llaves*/
#include <bits/stdc++.h>
#include <ctime>

using namespace std;

//La semilla se incializa con el clocking de la computadora

/* README
De las lineas 16-43 es la estructura de nodo del treap,
De las líneas 122 a 205 son las funciones de Split, Merge, Insert y Erase por posición es ahí donde se encuentran los problemas
*/

typedef struct _Node
{
	long long int x,p,cnt;
	long long int Max; // Se refiere al elemento máximo del subarbol
	_Node *l, *r;
	_Node(long long int _x)
	{
		x=_x;
		p=(rand() << 15 )^rand();
		cnt=1;
		l=NULL;
		r=NULL;
		Max=_x;
	}
	~_Node()
	{
		delete l;
		delete r;
	}
	void recalc()
	{
		cnt=1;
		cnt+=((l)?(l->cnt):0);
		cnt+=((r)?(r->cnt):0);
	}
	void subtreeMax()
	{
		Max=x;
		long long int ml=((l)?(l->Max):x);
		long long int mr=((r)?(r->Max):x);
		Max=max(x,max(ml,mr));
	}
	void print()
	{
		cout<<"( "<<p<<" "<<x<<" "<<cnt<<" )";
	}
} * Node;

struct Treap
{
	Node root=NULL;
	Treap(){}
	Node merge(Node l, Node r)
	{
		if(!l || ! r) return l ? l: r;
		if(l->p >r->p)
		{
			l->r=merge(l->r,r);
			l->recalc();
			l->subtreeMax();
			return l;
		}
		else
		{
			r->l=merge(l,r->l);
			r->recalc();
			r->subtreeMax();
			return r;
		}
	}
	void SplitByValue(Node n, long long int d, Node &l,Node &r)
	{
		l=r=NULL;
		if(!n)
		{
			return;
		}
		if(n->x <d)
		{
			SplitByValue(n->r,d,n->r,r);
			l=n;
		}
		else
		{
			SplitByValue(n->l,d,l,n->l);
			r=n;
		}
		n->recalc();
		n->subtreeMax();
	}
	void printInorder(Node raiz)
	{
		if(raiz)
		{
			printInorder(raiz->l);
			raiz->print();
			printInorder(raiz->r);
		}

	}
	void print()
	{
		printInorder(root);
		cout<<endl;
	}
	void eraseByValue(long long int x)
	{
		Node l,m,r;
		SplitByValue(root,x,l,m);
		SplitByValue(m,x+1,m,r);
		delete m;
		root=merge(l,r);
	}
	void InsertBV(long long int x)
	{
		Node l,r;
		SplitByValue(root,x,l,r);
		root=merge(merge(l, new _Node(x)),r);
	}
	void SplitFirstNodes(Node n, long long int c, Node &l)
	{
		l=NULL;
		if(!n->l || n-> cnt <= c)
		{
			return;
		}
		if(n->l->cnt > c)
		{
			SplitFirstNodes(n->l,c,n->l);
			l=n;
		}
		n->recalc();
		n->subtreeMax();
	}
	/* Funcion size: Sirve para ver si un nodo es nulo o no con base en el tamaño de los
	nodos que tiene debajp */
	long long int size(Node n)
	{
		if(n) return n->cnt;
		else return 0;
	}
	/*Regresa el nodo que se encuentra en una determinada posición */
 	Node getNodeInPos(Node n,long long int p)
	{
		if(size(n)==0) return n;
		/*Si el nodo es nulo regresamos el nodo */
		if(size(n->l) == p) return n;
		else if(size(n->l) > p)
		{
			return getNodeInPos(n->l,p);
		}
		else if (size(n->l) < p)
		{
			return getNodeInPos(n->r,p-size(n->l)-1);
		}
	}
	/*Regresa el valor que corresponde al nodo que se encuentra en una determinada posición */
	long long int getValueInPos(Node n,long long int p)
	{
		Node raiz;
		raiz=getNodeInPos(n,p);
		if(!raiz) return -1;
		else return raiz->x;
	}
	/* Función que hace el Split de un Treap con base en una posicion
	es una función similar a la función split por valor solo checamos que el nodo no sea nulo
	en este caso si el nodo es nulo entonces su tamaño es 0 y se puede seguir la recursión*/
	void SplitByPos(Node n, long long int p, Node &l,Node &r)
	{
		l=r=NULL;
		if(size(n)==0) return;
		if(size(n->l) <p)
		{
			SplitByPos(n->r,p-size(n->l)-1,n->r,r);
			l=n;
		}
		else
		{
			SplitByPos(n->l,p,l,n->l);
			r=n;
		}
		n->recalc();
		n->subtreeMax();
	}

	/*Similar a la función insert por valor hacemos un split en la posición que queremos insertar el nuevo nodo
	después hacemos el merge del arbol que hicimos split con el nuevo nodo que creamos*/
	void InsertBP(long long int p, long long int x)
	{
		Node l,r;
		SplitByPos(root,p,l,r);
		root=merge(merge(l, new _Node(x)),r);
	}
	/*############## FUNCION PROBLEMA ##############################
 Esta función hace un borrado de un nodo por posición, para esto dejamos el nodo solo
 para poder hacer el delete de dicho nodo, separamos el arbol desde la raíz hasta el nodo p, luego separamos el
 subarbol m en la posición p+1, hacemos delete del nodo m y finalmente hacemos un merge de los nodos
 left y right y lo igualamos a la raíz para tener de nuevo el árbol que queríamos*/
	void eraseByPos(long long int p)
	{
		Node l,m,r,aux;
		SplitByPos(root,p,l,m);
		SplitByPos(m,1,m,r);
		//aux=getNodeInPos(root,p);
		//SplitByValue(root,aux->x,l,m);
		//SplitByValue(m,aux->x+1,m,r);
		//SplitByPos(m,p+1,m,r);
	 // Revisemos si el nodo está realmente solo o no está pasando nada
		delete m;
		root=merge(l,r);
	}
	//void rotateLeft(Node n)
	void moveItems(long long int p1, long long int p2)
	{
		if (p1==p2) return;
		else
		{
			long long int aux=getValueInPos(root,p1);
			eraseByPos(p1);
			InsertBP(p2,aux);
		}
	/*	if (p1<p2)
		{
			long long int aux=getValueInPos(root,p1);
			eraseByPos(p1);
			InsertBP(p2,aux); //Caso en que la posicion 1 es menor que la posición 2

		}
		else if(p2<p1)
		{
			long long int aux=getValueInPos(root,p1);
			eraseByPos(p1);
			InsertBP(p2,aux);
		}
		else return; */
	}
	/* Esta función si corre bien pero según yo debería de tener fallas
	ya que no necesariamente se cumple*/
	long long int getMaxbyPos(long long int p1, long long int p2)
	{
		//Funciona pero no es para nada eficiente, se ocupa tiempo lineal
		/*if (!(p1<p2)) swap(p1,p2);
		//cout<<p2-p1;
		long long int max=getValueInPos(root,p1);
		for (long long int i=0;i<(p2-p1);i++)
		{
			if(getValueInPos(root,p1+i)>max) max=getValueInPos(root,p1+i);
		}
		return max;*/
		//Esta solución es mas costosa en memoria pero se hace en O(log(N))
		Node sp1=getNodeInPos(root,p1);
		//Node sp2=getNodeInPos(root,p2);
		if(sp1)
		{
			Node l,m,r;
			if (!(p1<p2)) swap(p1,p2);
			SplitByPos(root,p1,l,m);
			SplitByPos(m,(p2-p1)+1,m,r);
			long long int maximo=m->Max;
			root=merge(l,merge(m,r));
			return maximo;
		}
		else return -1;
	}
};
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
  //treap.print();
  //cout<<endl;
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
      //treap.print();
    }
    else if (peticion==1)
    {
      long long int p;
      cin>>p;
      treap.eraseByPos(p);
      //treap.print();

    }
    else if (peticion==2)
    {
      long long int p1,p2;
      cin>>p1>>p2;
      treap.moveItems(p1,p2);
      //treap.print();
    }
    else
    {
      continue;
    }
  }
  //cout<<"Maximo del arbol "<<treap.root->Max<<endl;
}
