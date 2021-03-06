// Solución del problema blue marys company usando un 
//Li Chao Tree

#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define N 100006

namespace segtree{
struct Line
{
	ll b,a;
	ll operator ()(ll x){return b*x+(a-b);}
}

void insert(int l, int r, Line segment, int n=1)
{
	if(l+1 == r)
	{
		if(segment(l) >stree[n](l)) stree[n]=segment;
		/*Este arbol Li Chao está pensado
		 * para maximizar encontrar la función que 
		 * maximiza un determinado punto x*/
		 return;
	}
	int mid=(l+r)>>1;
	int lc=n*2; //Left child
	int rc=lc+1; //Right child
	if(stree[n].m>segment.m) swap(stree[n],segment);
	if(stree[n](mid)<segment(mid))
	{
		swap(stree[n],segment);
		insert(l,mid,segment,lc);
	}
	else
	{
		insert(mid,r,segment,rc);
	}
}

ll query(int l, int r, int x, int n)
{
	if(l+1==r) return stree[n](x);
	int mid=(r+l) >>1;
	int lc=n*2; //Left child
	int rc=lc+1; //Right child
	if(x<mid)
	{
		return max(stree[n](x),query(l,mid,x,lc));
	}
	else
	{
		return max(stree[n](x),query(mid,r,x,rc));
	}
}
}
