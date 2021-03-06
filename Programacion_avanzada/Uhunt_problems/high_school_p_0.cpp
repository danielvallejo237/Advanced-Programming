#include <bits/stdc++.h>

using namespace std;
int main()
{
	int v1,t1;
	while (scanf("%d %d",&v1,&t1)!=EOF)
	{
		if (-100<=v1<=100 && 0<=t1<=200) printf("%d\n",2*v1*t1);
	}
	return 0;
}
