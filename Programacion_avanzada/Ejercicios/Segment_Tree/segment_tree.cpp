/*Creación de un segment tree para responder preguntas
 de un determinado arreglo de forma eficiente*/

 #include<bits/stdc++.h>

 using namespace std;

 class SegmentTree
 {
 private:
   vector<int> st, A; //Segment tree y el vector de datos
   int n; //Posicion en la que haremos el build o las consultas
   int left(int pos)
   {
     return pos<<1;
   }
   int right(int pos)
   {
     return (pos<<1) +1 ; //Equivale a las fórmulas 0.5*(L+R)
   }
   void build(int p, int L, int R)
   {
     if(L==R) st[p]=L;
     else
     {
       build(left(p),L,(L+R)/2);
       build(right(p),(L+R)/2+1,R);
       int p1=st[left(p)];
       int p2=st[right(p)];
       st[p] = (A[p1] <= A[p2]) ? p1 : p2;
       //En ese segmento guardamos el mínimo de esos números
     }
   }
   int rmq(int p, int L, int R, int i, int j)
   {
     //cout<<"Entering rmq"<<endl;
     if(j<L || i>R) return -1;
     /*Checamos que no nos estemos saliendo de los rangos de
     de los segmentos */
     if(L==R) return st[p];
     /*Que esté acotado en el rango de Left y Right */
     //Calcular el rmq dado ese segmento
     int p1=rmq(left(p),L,(L+R)/2,i,j);
     int p2=rmq(right(p),(L+R)/2+1,R,i,j);
     if(p2==-1) return p1;
     if(p1==-1) return p2;
     return (A[p1]< A[p2]) ? p1: p2;
   }
 public:
   SegmentTree(const vector<int> &_A)
   {
     A=_A;
     n=(int)A.size();
     st.assign(4*n,0);
     /*Esto es una cota superior del numero de nodos a usar */
     build(1,0,n-1);
     cout<<"Clase Segment Tree inicializada"<<endl;
   }
   int rmq(int i, int j) //sobrecargando la función rmq
   {
     return A[rmq(1,0,n-1,i,j)];
   }
 };
 int main()
 {
   int arr[] = { 18, 17, 13, 19, 15, 11, 20 }; // the original array
   vector<int> A(arr, arr + 7);
   SegmentTree stree(A);
   cout<<"RMQ: "<<stree.rmq(1,3)<<endl;
   cout<<"RMQ: "<<stree.rmq(1,6)<<endl;
   return 0;
 }
