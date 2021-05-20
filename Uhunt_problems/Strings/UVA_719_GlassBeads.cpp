#include <bits/stdc++.h>

using namespace std;


int findDisjoint(string s)
{
    string aux_str=s+s+s; //Esto para los ciclos
    for(int i=0;i<s.size();i++)
    {
        bool flag=true;
        for(int j=i+1;j<s.size()+i;j++)
        {
            string s1=aux_str.substr(i,s.size());
            string s2=aux_str.substr(j,s.size());
            flag*=(s1<s2);
        }
        if(flag)
        {
            return i+1;
        }
    }
    return -1;

}

int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        cin>>str;
        cout<<findDisjoint(str)<<"\n";
    }
    return 0;
}