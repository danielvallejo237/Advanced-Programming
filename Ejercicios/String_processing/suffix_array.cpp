#include <bits/stdc++.h>

using namespace std;
#define MAXN 1000

//Creación de un arreglo de sufijos en c++ 

/* 
Definición de arreglo de sufijos:

Es un arreglo de enteros donde cada sufijo es representado con un índice y luego se ordenan los sufijos en 
orden lexicográfico. La forma naive se construye de la siguiente forma 
*/
string s;
vector<int> suffix(MAXN,0);

inline bool suffixcomp(int i, int j)
{
	return (s.substr(i)<s.substr(j)); 
}
//Lo anterior nos sirve para dar el orden lexicográfico a las cosas

int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		suffix[i]=i;
	}
	sort(suffix.begin(),suffix.begin()+s.size(),suffixcomp);
	
	for(int j=0;j<s.size();j++)
	{
		cout<<s.substr(suffix[j])<<endl;
	}
	
	//Vemos que si está ordenado en orden lexicográfico
	
}