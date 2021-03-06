//Implementación del Li Chao Tree y solución de algunos problemas

#include <bits/stdc++.h>


using namespace std;

#define ll long long int
#define MAX 500

struct Line
{
	ll m,b;
	ll operator()(ll x){return m*x+b;}
}stree[4*MAX]; //Construcción de un segment tree

void insert(int l, int r, Line segment, int n=0)
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
	int lc=n*2+1; //Left child
	int rc=n*2+2; //Right child
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
	int lc=n*2+1; //Left child
	int rc=n*2+2; //Right child
	if(x<mid)
	{
		return max(stree[n](x),query(l,mid,x,lc));
	}
	else
	{
		return max(stree[n](x),query(mid,r,x,rc));
	}
}

int main()
{
	
	Line l1,l2,l3;
	l1.m=10;
	l1.b=3;
	l2.m=1;
	l2.b=456;
	l3.m=15;
	l3.b=2;
	cout<<"Line created"<<endl;
	cout<<"Line "<<l1.m<<"x +"<<l1.b<<endl;
	insert(0,MAX-1,l1);
	insert(0,MAX-1,l2);
	insert(0,MAX-1,l3);
	cout<<"Lines inserted, insertion completed"<<endl;
	return 0;
}
