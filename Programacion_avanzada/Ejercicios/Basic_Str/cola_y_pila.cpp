#include"common.h"
#include<vector>
using namespace std;

#define N 20
//Dado un arreglo de tamaño N y un M<=N calcular la suma de los 
//mínimos de todos los subarreglos de tamaño M en tiempo O(N)
int main()
{
int M;
cin>>M;
if(M>N) exit(1);
QueueMin cola;
vector<int> vec;
vector<int>::iterator it;
srand(time(0));
for (int i=0;i<N;i++) vec.push_back(rand()%115);
int suma=0;
cout<<"[info] Parte de la suma de minimos..."<<endl;
for(it = vec.begin();it !=vec.end();++it)
{
	/*Esto solo se hace N veces dependiendo del tamaño 
	 del arreglo por lo que si cumple que sea O(N) */
	cout<<*it<<" ";
	cola.push(*it);
	if(cola.size()==M)
	{
		suma+=cola.MinElement();
		cola.pop();
	}
}
cout<<endl<<"Suma de minimos: "<<suma<<endl;
return 0;
}
