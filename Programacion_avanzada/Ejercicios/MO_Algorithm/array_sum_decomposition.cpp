/* Implementamos el algoritmo de MO, para calcular la
suma en rangos [L,R], dadas previamente las consultas y ordenarlas*/
#include <bits/stdc++.h>

using namespace std;

int N=10; // Tamaño del arreglo
int batch_size=sqrt(N);

vector<int> arreglo(N); //El arreglo es de tamaño N
vector<int> suma(batch_size + (int)((N % batch_size)>0)); //Aquí vamos a guardar el valor de la suma de los rangos
vector<int> solutions;

struct query
{
  int l, r, i; //i es el indice de la consulta, left y right son los rangos l y r de la consulta
  bool operator < (query b) const
  {
    if(l/batch_size==b.l/batch_size) return r/batch_size < b.r/batch_size; //Si caen en el mismo bloque
    //Entonces revisamos cual de las dos consultas queda primero
    //Lo anterior nos sirve para el algoritmo de ordenamiento
    return l/batch_size< b.l/batch_size; // Caen en bloques diferentes
  }
  void pout()
  {
    cout<<l<<" "<<r<<endl;
  }
};
vector<query> querys;

void process_querys(vector<query> consultas)
{
  int level=consultas[0].l/batch_size; // Es el nivel en el que estamos
  int lright=consultas[0].r/batch_size;
  vector<int>::iterator it=arreglo.begin()+batch_size-1; //El muro
  int solution;
  cout<<level<<" "<<lright<<" "<<*it<<endl;
  int Jump=0;
  for(int i=0;i<consultas.size();i++)
  {
    if(consultas[i].l/batch_size>level)
    {
      level=consultas[i].l/batch_size;
      lright=consultas[i].r/batch_size;
      Jump=0;
      it=arreglo.begin()+(consultas[i].l/batch_size+1)*(consultas[i].l/batch_size); //Movernos a un muro
    }
    //Calculemos ahora Jump
    if(consultas[i].r/batch_size > lright)
    {
      Jump+=suma[lright+1];
    }
    int suma_left=accumulate(arreglo.begin()+consultas[i].l,it+1,0);
    cout<<"Jump: "<<Jump<<endl;
    solution=Jump+suma_left;
    cout<<"Solucion: "<<solution<<endl;
  }
}



int M;

int main()
{
  srand(time(NULL));
  cin>>M;

  for(int j=0;j<N;j++)
  {
    arreglo[j]=rand()%10;
    cout<<arreglo[j]<<" ";
  }
  cout<<endl;
  querys.resize(M);
  for(int i=0;i<M;i++)
  {
    cin>>querys[i].l>>querys[i].r;
    querys[i].i=i;
  }
  sort(querys.begin(),querys.end());
  cout<<suma.size()<<endl;
  for(int i=0;i<suma.size();i++) //Así calculamos las sumas acumuladas
  {
    if(i==suma.size()-1)
    {
      suma[i]=accumulate(arreglo.end()-(N % batch_size),arreglo.end(),0);
    }
    else
    {
        suma[i]=accumulate(arreglo.begin()+i*batch_size,arreglo.begin()+(i+1)*batch_size,0);
    }
  }
  solutions.resize(M);
  process_querys(querys);
  cout<<solutions.front()<<endl;
  return 0;
}
