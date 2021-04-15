#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool binary_search(vector<ll> a, ll l, ll r,ll x)
{
    ll mid=(l+r)/2;
    if(a[mid]==x) return true;
    if(l==r && a[mid]!=x) return false; //El elemento no se enceuntra en el arreglo
    else
    {
        if(a[mid]>=x) return binary_search(a,l,mid,x);
        else return binary_search(a,mid+1,r,x);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll N;
    cin>>N;
    vector<ll> num(N);
    for(ll i=0;i<N;i++)
    {
        cin>>num[i];
    }
    sort(num.begin(),num.begin()+N);
    ll toSearch;
    map<int,string> opciones;
    opciones[0]="No";
    opciones[1]="Si";
    while(cin>>toSearch)
    {
        if(toSearch==-1) break;
        cout<<"Numero "<<toSearch<<" en el arreglo "<<opciones[binary_search(num,0,N-1,toSearch)]<<"\n";
    }
    return 0;
}