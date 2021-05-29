#include <bits/stdc++.h> 
using namespace std;
int dp[101][101],sum[101],f[101][101],g[101][101],n;
int main () {
    int i,j,l;
        while (cin>>n,n) {
        memset (dp,0,sizeof (dp));
        sum[0]=0;
            for (i=1;i<=n;i++) {int t;
            cin>>t;
            sum[i]=sum[i-1]+t;
        f[i][i]=g[i][i]=dp[i][i]=t;
                } for (l=1;l<n;l++) {for (i=1;i+l<=n;i++) {j=i+l;
                int tmp=0;
                tmp=min (tmp,f[i+1][j]);
                tmp=min (tmp,g[i][j-1]);
                dp[i][j]=sum[j]-sum[i-1]-tmp;
                f[i][j]=min (dp[i][j],f[i+1][j]);
            g[i][j]=min (dp[i][j],g[i][j-1]);
    }} cout<<dp[1][n]*2-sum[n]<<endl;
} return 0; }