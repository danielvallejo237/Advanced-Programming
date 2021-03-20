#include<bits/stdc++.h>
#include <cmath>
using namespace std;

long long int compute_rows(long long int warriors)
{
	long long int rows;
	double delta,y;
	delta=1+8*warriors;
	y=(-1+sqrt(delta))/2;
	return (long long int)y;
}

int main()
{
	int cases;
	cin>>cases;
	for (int i=0;i<cases;i++)
	{
		long long int w;
		cin>>w;
		cout<<compute_rows(w)<<endl;
	}
	return 0;
}
