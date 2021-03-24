#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main()
{
    map<ll,ll> calcetines;
    ll n;
    cin>>n;
    vector<ll> socks(n);
    for (ll i=0;i<n;i++)
    {
        cin>>socks[i];
        calcetines[socks[i]]+=1;
    }
    set<ll> uni(socks.begin(),socks.end());
    ll pares=0;
    for(auto const &s: uni)
    {
        pares+=(ll)calcetines[s]/(ll)2;
    }
    cout<<pares<<endl;
}