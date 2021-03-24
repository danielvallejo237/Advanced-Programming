#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ll n, r; //numero de elementos y rotaciones
    list<ll> elementos;
    cin>>n>>r;
    for (ll i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        elementos.push_back(a);
    }
    for(ll j=0;j<r;j++)
    {
        elementos.push_back(elementos.front());
        elementos.pop_front();
    }
    for(list<ll>::iterator it=elementos.begin();it!=elementos.end();++it) cout<<*it<<" ";
    cout<<endl;
    return 0;
}