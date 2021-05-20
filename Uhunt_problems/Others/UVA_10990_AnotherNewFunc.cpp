#include <bits/stdc++.h>

using namespace std;

#define MAXINT 2000005

vector<int> DP(MAXINT); //Aquí usaremos una DP
vector<int> PROF(MAXINT);

int EulerPhi(int n)
{
    int result = n;
    for(int p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;      
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
         
    return result;
}
void precompute()
{
    for(int i=1;i<=MAXINT;i++) DP[i]=EulerPhi(i);
}

int DepthofPhi(int n)
{
    int aux=n;
    int depth=0;
    while(aux!=1)
    {
        aux=DP[aux];
        depth++;
    }
    return depth;
}

void precomputeDepth()
{
    for(int i=1;i<=MAXINT;i++)
    {
        PROF[i]=DepthofPhi(i);
    }
}

long int SODF(int m, int n)
{
    long int result=0;
    for(long int i=m;i<=n;i++) result+=PROF[i];
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int testcases;
    precompute();
    precomputeDepth();
    cin>>testcases;
    while(testcases--)
    {
        int m,n;
        cin>>m>>n;
        assert(m<=n && m>=2);
        cout<<SODF(m,n)<<endl;
    }
    return 0;
}