#include<bits/stdc++.h>


using namespace std;
#define ll long long
#define MAXINT 1000

vector<ll> DP(MAXINT,-1);


ll factorial_bottomup(ll n)
{
    DP[0]=1;
    ll i;
    for(i=1;i<=n;i++) DP[i]=i*DP[i-1];
    return DP[i-1]; 
}
ll factorial_topdown(ll n)
{
    if(n==0) DP[0]=1;
    if(DP[n]!=-1) return DP[n];
    return n*factorial_topdown(n-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    cout<<"Factorial "<<n<<" using bottom up: "<<factorial_bottomup(n)<<"\n";
    cout<<"Factorial "<<n<<" using top down: "<<factorial_topdown(n)<<"\n";
    return 0;
}