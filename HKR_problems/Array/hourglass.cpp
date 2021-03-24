#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll getHourglasssum(ll x, ll y ,vector<vector<ll> > matrix)
{
    
    return matrix[x][y]+matrix[x-1][y]+matrix[x-1][y-1]+matrix[x-1][y+1]+ matrix[x+1][y]+matrix[x+1][y-1]+matrix[x+1][y+1];
    
}

int main()
{
    vector<vector<ll> > mat(6);
    for(ll i=0;i<mat.size();i++)
    {
        vector<ll> vec(6);
        for(ll j=0;j<vec.size();j++) 
        {
            cin>>vec[j];
            assert(vec[j]>=-9 && vec[j]<=9);
        }
        mat[i]=vec;
    }
    vector<ll> sumas;
    //cout<<getHourglasssum(1,1,mat)<<endl;
    for(ll i=1;i<=4;i++)
    {
        for(ll j=1;j<=4;j++) sumas.push_back(getHourglasssum(i,j,mat));
    }
    //for(vector<ll>::iterator it=sumas.begin();it!=sumas.end();++it) cout<<*it<<endl;
    cout<<*max_element(sumas.begin(),sumas.end())<<endl;
    return 0;
}