#include <bits/stdc++.h>

using namespace std;

#define ll long long 

ll maxSum1D(vector<ll> arreglo)
{
    ll current_max=arreglo[0];
    ll max_so_far=arreglo[0];
    for (int i=1;i<(int)arreglo.size();i++)
    {
        current_max=max(arreglo[i],arreglo[i]+current_max);
        max_so_far=max(max_so_far,current_max);
    }
    return max_so_far;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    vector<ll> vec(n);
    for(ll i=0;i<n;i++) cin>>vec[i];
    cout<<"Maxima suma del arreglo: "<<maxSum1D(vec)<<endl;
    return 0;
}