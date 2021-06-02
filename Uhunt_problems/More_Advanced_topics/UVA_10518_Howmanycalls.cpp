#include <bits/stdc++.h>

/*En este problemas contamos cuantas llamadas recursivas hacemos para llegar a 
un número n de fibonacci*/
using namespace std;

struct node
{
    int s[2][2];
}a,p,res;

int m;

void init()
{
    a.s[0][0]=1,res.s[0][0]=1;
    a.s[0][1]=1,res.s[0][1]=0;
    a.s[1][0]=1,res.s[1][0]=0;
    a.s[1][1]=0,res.s[1][1]=1;
}

node compute(node a,node b)
{
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            p.s[i][j]=(a.s[i][0]*b.s[0][j]+a.s[i][1]*b.s[1][j])%m;
        }
    }
     return p; //p corresponde a la potencia modular 
}

int solve(long long s){
    init();
    while (s){
        if (s & 1)
            res = compute(res,a);
        a = compute(a,a);
        s >>= 1;
    }
    return (res.s[0][0]*2-1+m)%m;
}

int main(){
    long long n;
    int cas = 1;
    while (scanf("%lld%d",&n,&m) != EOF && n+m){
        printf("Case %d: %lld %d ",cas++,n,m);
        printf("%d\n",solve(n));
    }
}