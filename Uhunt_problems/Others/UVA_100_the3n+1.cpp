#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll longitud_ciclo(ll n)
{
    if(n==1) return 1;
    return 1+ longitud_ciclo(n%2==0 ? n/2 : 3*n+1);
}

ll Max_long_ciclo(ll start, ll end)
{
    ll left=min(start,end);
    ll right=max(start, end);
    ll maxima_longitud=0;
    for(ll i=left;i<=right;i++)
    {
        ll aux=longitud_ciclo(i);
        if(aux>maxima_longitud)
        {
            maxima_longitud=aux;
        }
    }
    return maxima_longitud;
}

int main()
{
    ll i,j;
    while(cin>>i>>j)
    {
        cout<<i<<" "<<j<<" "<<Max_long_ciclo(i,j)<<endl;
    }
    return 0;
}