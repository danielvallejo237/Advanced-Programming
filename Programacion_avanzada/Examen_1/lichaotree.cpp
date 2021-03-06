
//Implementación de un LiChao tree
/* Examen parcial 1, Daniel Vallejo Aldana */
//Programación Avanzada
/*Algoritmo usando las ideas de las notas de la clase
Algoritmos 2 de Miguel Angel Ruiz*/

#include<bits/stdc++.h>
#define N 10000000
//10^5 funciones

using namespace std;
/*Solución de las notas: Consideremos un arbol en el
que cada nodo tendrá almacenada una función fk y cada nodo
representa un subintervalo del [L,R] al igual que en
la construcción del segment tree *


/*Esta es la función que será insertada en cada uno de los
nodos del segment tree*/

long long int left(long long int pos)
{
  return pos<<1; //Funciones auxiliares para movernos en el ST
}
long long int right(long long int pos)
{
  return (pos<<1) +1;
}

class linea
{
public:
  float m,b; //La pendiente de la Línea y el término independiente
  linea(float m, float b)
  {
    //Constructor de la clase linea para,
    //inicializar la pendiente y el término
    //independiente
    this->m=m;
    this->b=b;
  }
  linea(){}
  void print_line()
  {
    cout<<m<<"x + "<<b<<endl;
  }
  float build_line(float x)
  {
    //Regresamos la línea
    return m*x+b;
  }
};
//Creación del LiChao Tree un ST de funciones
vector<linea> segment_tree(4*N);
//El tamaño de la memoria a usar es 4*N

/*Parte de agregar funciones
->El camino desde la raiz hasta el nodo hoja representa a cierto {x},
se encuentra la función fk tal que fk es máximo.
La idea es ir insertando una función una por una de tal forma que se
mantenga la propiedad del LiChao Tree
*/

void add_function(int l, int r, linea line,int n=1)
{
  //n representa la posición en la que nos encontramos
  //Como siempre empezamos desde la raiz pues la n inicial es 1
  /*Inicialmente todos los nodos del arbol contendran a la misma funcion
  Supongamos que estamos ahora en un nodo que contiene a la función g y ahora queremos añadir
  a la función f, considermos mid=0.5(l+r),  en el nodo actual guardaremos la funcion
  que está por arriba del segmento en el que no se cortan y la función que está por debajo la
  insertamos en el nodo que corresponde al otro segmento */
  if(l+1==r)
  {
    if(line.build_line(l)>segment_tree[n].build_line(l))
    {
      /*Si la linea nueva maximiza hay que hacer un cambio de funciones*/
      segment_tree[n]=line;
    }
  return;
  }
  int mid=(l+r)/2;
  if(segment_tree[n].build_line(mid)<line.build_line(mid))
  {
    segment_tree[n]=line;
    add_function(l,mid,line,left(n));
  }
  else add_function(mid,r,line,right(n));
  /* Al guardar la función que es mayor en el segmento en el que no hay intersección mantenemos
la propiedad del Li Chao Tree en ese segmento, y mantendremos la propiedad en el otro segmento al insertar
la otra funci´on recursivamente*/
}


float query(int l, int r, float x, int n)
{
  /*Por la propiedad del arbol Li Chao Tree sacar el máximo es más sencillo
  ya que solo debemos de comparar los valores de fk(x) y proceder de forma recursiva*/
  if(l+1 == r) return segment_tree[n].build_line(x);
  int mid=(l+r)/2;
  if(x<mid)
  {
    return max(segment_tree[n].build_line(x),query(l,mid,x,left(n)));
  }
  else return max(segment_tree[n].build_line(x),query(mid,r,x,right(n)));
}

float simple_query(float x)
{
  return query(1,N,x,1);
}

void add_function_simple(linea l)
{
  add_function(1,N,l);
}

int main()
{
  /*No lo probé para el caso de 10^{5} debido al timepo y a la falta de un caso
 de prueba asá de grande pero debería de funcionar correctamente esta implementación
  */
  linea l1(10.0,12.4);
  linea l2(12.3,42.21);
  linea l3(14.36,2.45);
  linea l4(1.0,1.0);
  add_function_simple(l1);
  add_function_simple(l2);
  add_function_simple(l3);
  add_function_simple(l4);
  cout<<"Lineas Añadidas finalizado"<<endl;
  cout<<simple_query(2.4)<<endl;
  cout<<simple_query(3.6)<<endl;
  cout<<simple_query(12.36)<<endl;
  cout<<simple_query(10.3)<<endl;
  return 0;
}
