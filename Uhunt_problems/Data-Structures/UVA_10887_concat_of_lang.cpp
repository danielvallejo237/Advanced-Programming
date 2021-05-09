#include <bits/stdc++.h>

using namespace std;

vector<string> A,B,C;
int main()
{
    ios_base::sync_with_stdio(false);
    int testcases;
    cin>>testcases;
    int counter=1;
    while(testcases--)
    {
        int m, n;
        A.clear();
        C.clear();
        B.clear();
        cin>>m>>n;
        cin.ignore();
        for(int i=0;i<m;i++)
        {
            string s;
            getline(cin,s);
            A.push_back(s);
        }
        for (int i=0;i<n;i++)
        {
            string s;
            getline(cin,s);
            B.push_back(s);
        }
        for (int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++) C.push_back(A[i]+B[j]);
            //Concatenamos las cadenas de las cosas 
        }
        sort(C.begin(),C.end());
        int ans=unique(C.begin(),C.end())-C.begin();
        cout<<"Case "<<counter<<": "<<ans<<endl;
        counter++;
    }
    return 0;

}