#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define INF 999999

int main()
{
    while(1)
    {
        int n;
        vector<int> arr;
        while(cin>>n && n!=-999999)
        {
            arr.push_back(n); //Insertamos el arreglo
        }
        int max_s=-INF;
        for(int j=0;j<arr.size();j++)
        {
            int max_current=arr[j];
            int max_so_far=arr[j];
            for(int i=j+1;i<arr.size()-1;i++)
            {
                max_current=max(arr[i+1]*max_current*arr[i],arr[i]);
                max_so_far=max(max_current,max_so_far);
            }
            if(max_so_far>max_s) max_s=max_so_far;
        }
        cout<<max_s<<"\n";
    }
    return 0;
}