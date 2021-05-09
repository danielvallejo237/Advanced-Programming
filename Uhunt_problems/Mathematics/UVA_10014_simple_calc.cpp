#include <bits/stdc++.h>

using namespace std;

float computeProduct(vector<float> c, int n)
{
    float suma=0.0;
    for(int i=1;i<=n;i++)
    {
        suma+=2.0*(float)i*c[n-i];
    }
    return -suma;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout<<fixed;
    cout<<setprecision(2);
    int testcases;
    cin>>testcases;
    while (testcases--)
    {
        int n;
        cin>>n;
        float first,last;
        cin>>first;
        cin>>last;
        vector<float> ci(n);    
        for(int j=0;j<(int)ci.size();j++) cin>>ci[j];
        float num=last+(float)n*first+computeProduct(ci,n);
        printf("%.2lf\n", num/(float)(n+1));
        if(testcases) puts("");
    }
    return 0;
}