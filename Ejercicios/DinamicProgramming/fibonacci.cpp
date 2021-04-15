#include <bits/stdc++.h>
using namespace std;
#define ll long long 

#define MAXN 1000
vector<ll> DP(MAXN,-1);
ll fibonacci_bottomup(ll n)
{
    //Técnica Bottom-Up con soluciones desde la más pequeña hasta la más grande
    DP[0]=0;
    DP[1]=1;
    ll i;
    for(i=2;i<=n;i++) DP[i]=DP[i-1]+DP[i-2];
    return DP[i-1];
}
ll fibonacci_topdown(ll n)
{
    if(n==0) DP[0]=0;
    if(n==1) DP[1]=1;
    if(DP[n]!=-1) return DP[n];
    return fibonacci_topdown(n-1)+fibonacci_topdown(n-2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll numero;
    cin>>numero;
    printf("Fibonacci BU %lld: %lld\n",numero,fibonacci_bottomup(numero));
    printf("Fibonacci TD %lld: %lld\n",numero,fibonacci_topdown(numero));
    return 0;
}