#include <bits/stdc++.h>

using namespace std;

#define MAXINT 1000
//Como lo sugieren en la solución del problema es necesario calcular la primalidad
// de los p y q independientemente de n

vector<vector<bool>> RP(MAXINT,vector<bool> (MAXINT));
pair<float,pair<int,int>> v[500000]; //Un arreglo de parejas de parejas

void precompute()
{
	//Usar la función por defecto gcd de GNU
	for (int i=0;i<MAXINT;i++)
	{
		for(int j=0;j<MAXINT;j++) {
		if(__gcd(i,j)==1)
			{
				RP[i][j]=true;
			}
		else RP[i][j]=false;
		}
	}
	
}


int main()
{

	precompute();
	int n,k;
	while(cin>>n>>k)
	{
		
	int l=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(RP[i][j])
			{
				v[l++]=make_pair((float)j/(float)i,make_pair(j,i));
			}
		}
	}
	std::nth_element(v,v+k-1,v+l);
	cout << v[k-1].second.first << "/" << v[k-1].second.second << endl;
	}
	return 0;
}
