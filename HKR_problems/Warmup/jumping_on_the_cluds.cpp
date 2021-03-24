#include <bits/stdc++.h>

using namespace std;

#define ll long long 

ll jump(ll curr, vector<ll> clouds)
{
    ll s1=curr + 1;
    ll s2=curr + 2;
    //cout<<s1<<" "<<s2<<endl;
    if(clouds[s2]!=1) return s2;
    else return s1;
}

int main()
{
    ll number;
    cin>>number;
    vector<ll> clouds(number);
    for (ll i=0;i<number;i++) cin>>clouds[i];
    ll saltos=0;
    ll index=0;
    while(1)
    {
        ll tmp=index;
        index=jump(tmp,clouds);
        if(index>number) break;
        //cout<<index<<endl;
        saltos++;
    }
    cout<<saltos<<endl;
    return 0;
}