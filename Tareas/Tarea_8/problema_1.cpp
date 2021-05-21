#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAXINT 100005
#define MAXL 20 //La longitud mayor del sufijo
//La complejidad de este algoritmo es de alrededor de O(n^2)
//Lo anterior porque hacemos iteración sobre cada caracter n veces así nos da la complejidad deseada

string A;

class ent 
{
    public:
    ll nr[2];
    ll p;
};
vector<ent> L(MAXINT);

ll cmp(ent a, ent b)
{
    return a.nr[0]==b.nr[0] ? (a.nr[1]<b.nr[1] ? 1:0) : (a.nr[0]<b.nr[0] ? 1: 0);
}
vector<vector<ll>> P(MAXL,vector<ll>(MAXINT));
ll N,i,stp,cnt;
//Calculemos el prefijo común más grande
ll LCP(ll x, ll y)
{
    ll k, ret=0;
    if(x==y) return N-x;
    for(k=stp-1;k>=0 && x<N && y<N;k--)
    {
        if(P[k][x]==P[k][y])
        {
            x+=1<<k;
            y+=1<<k;
            ret+=1<<k;
        }
    }
    return ret;
}

int main()
{
    cin>>A;
    for(N=A.size(),i=0;i<N;i++)
    {
        P[0][i]=A[i]-'a';
    }
    for(stp=1,cnt=1;cnt>>1<N;stp++,cnt<<=1)
    {
        for(i=0;i<N;i++)
        {
            L[i].nr[0]=P[stp-1][i];
            L[i].nr[1]=i+cnt<N ? P[stp-1][i+cnt] : -1;
            L[i].p=i;
        }
        sort(L.begin(),L.begin()+N,cmp);
        for(i=0;i<N;i++)
        {
            P[stp][L[i].p] = i>0&& L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
        }
    }
    vector<ll> Sa(N,0);
    for(i=0;i<N;i++) Sa[P[stp-1][i]]=i;
    vector<ll> lcp(N,0);
    for(i=0;i<N-1;i++)
    {
        lcp[i]=LCP(Sa[i],Sa[i+1]);
    }
    ll res=N-Sa[0];
    for(i=1;i<N;i++) res+=N-Sa[i]-lcp[i-1];
    cout<<"#Sub cadenas distintas: "<<res<<"\n";
    return 0;
}
