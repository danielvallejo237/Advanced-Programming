#include <bits/stdc++.h>

using namespace std;

const int N=100005;
int n,k, arr[N];

int main()
{
    while(cin>>n>>k)
    {
        for(int i=0;i<n;i++) cin>>arr[i];
    int ans=n+1;
    int sum=0;
    int l=0,r=0;
    while(r<n)
    {
        sum+=arr[r++];
        while(sum>=k)
        {
            ans=min(ans,r-l);
            sum-=arr[l++];
        }
    }
    ans =(ans==n+1 ? 0: ans);
    cout<<ans<<endl;
    }
}