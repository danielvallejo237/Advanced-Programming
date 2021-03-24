#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long 
#define MAXQ 50005


struct state
{
    int oldindex, oldval, oldcnt, time_periord;
};

int c[MAXQ], cntc;

state st[MAXQ*20];
int szt, current_time;

int seed=123;
const int step=10009,mask=(1<<3)-1;

inline int mrnd()
{
    seed=(seed*step) &mask;
    return seed & 1;
}

void init (int n)
{
    cntc=n;
    for(int i=0;i<n;i++) c[i]=i;
    szst=0,current_time=0;
}

int root(int a)
{
    
}