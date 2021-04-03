#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back

ll getCloserGreat(vector<ll> personas, ll height)
{
    ll res=-1,left=0,right=(ll)personas.size()-1;
    //Aqui vamos a aplicar una búsqueda binaria 
    while(left<=right)
    {
        ll mid=left + ((right - left) >> 1);
        if(personas[mid]>height)
        {
            res=personas[mid];
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return res;
}

ll getCloserSmall(vector<ll> personas, ll height)
{
    ll res=-1,left=0,right=(ll)personas.size()-1;
    //Aqui vamos a aplicar una búsqueda binaria 
    while(left<=right)
    {
        ll mid=left + ((right - left) >> 1);
        if(personas[mid]<height)
        {
            res=personas[mid];
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //Desactivar la sincronización con el stdio
    ll ladys;
    scanf("%lld",&ladys);
    vector<ll> sujetos;
    for (ll i=0;i<ladys;i++)
    {
        ll subj;
        scanf("%lld",&subj);
        sujetos.pb(subj);
    }
    ll querys;
    scanf("%lld",&querys);
    vector<ll> alturas;
    for (ll i=0;i<querys;i++)
    {
        ll altura;
        scanf("%lld",&altura);
        alturas.pb(altura); 
    }
    for(ll i=0;i<querys;i++)
    {
        ll sm=getCloserSmall(sujetos,alturas[i]);
        ll bi=getCloserGreat(sujetos,alturas[i]);
        if(sm==-1) printf("X ");
        else printf("%lld ",sm);
        if(bi==-1) printf("X\n");
        else printf("%lld\n",bi);
    }
    return 0;
}

