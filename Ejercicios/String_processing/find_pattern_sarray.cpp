#include <bits/stdc++.h>

using namespace std;
#define MAXN 1000

/*
Problema de encontrar la subcadena patrón dentro de la cadena original

*/

string s;
int suffix[MAXN];

//Construcción del arreglo de sufijos de la forma tradicional sin necesidad de usar radix sort
//Costo de esa operación O(n^{2}log(n))

inline bool suffixComp(int i, int j)
{
	return (s.substr(i)<s.substr(j));
}


inline bool suffcompare1(int ind, const string &pattern)
{
	return (s.substr(ind).compare(0,pattern.size(),pattern)<0);
}


inline bool suffcompare2(int ind, const string &pattern)
{
	return (s.substr(ind).compare(0,pattern.size(),pattern)>0);
}

pair<int,int> match(const string &pattern)
{
	int *low=lower_bound(suffix,suffix+s.size(),pattern,suffcompare1);
	int *up=upper_bound(suffix,suffix+s.size(),pattern,suffcompare2);
	return make_pair((int)(low-suffix),(int)(up-suffix));
}

int main()
{
	cin>>s;
	int adv=s.size();
	for(int i=0;i<adv;i++)
	{
		suffix[i]=i;
	}
	sort(suffix,suffix+adv,suffixComp);
	for(int i=0;i<adv;i++)
	{
		cout<<s.substr(suffix[i]);
	}
	//De esta forma ya tenemos el arreglo ordenado de los suffijos en orden lexicográfico
	string pattern;
	cin>>pattern;
	cout<<endl;
	pair<int,int> p=match(pattern);
	cout<<p.first<<" "<<p.second<<endl;
	for(int i=p.first;i<p.second;i++) cout<<s.substr(suffix[i])<<endl;
	return 0;
}
