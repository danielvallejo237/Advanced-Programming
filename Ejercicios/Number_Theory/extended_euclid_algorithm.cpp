
#include <bits/stdc++.h>

using namespace std;

//Creación del algoritmo extendido de euclides para la solución de
// ecuaciones diofanitnas de la forma ax+by=gcd(a,b)

void extendedEuclid(int a, int b, int &gcd, int &x, int &y)
{
	//Condición de paro
	if(b==0) {x=1;y=0;gcd=a; return;}
	int xnew, ynew;
	extendedEuclid(b,a%b,gcd,xnew,ynew);
	x=ynew;
	y=xnew-(a/b)*ynew;
}


int main()
{
	int g,x,y;
	extendedEuclid(15,14,g,x,y);
	cout<<x<<" "<<y<<" "<<endl;
	return 0;
}

