#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testcases=0;
    string containers;
    while(1)
    {
        testcases++;
        cin>>containers;
        if (containers=="end") break;
        vector<char> ships(26,'{'); 
        for(int i=0;i<containers.size();i++)
        {
            for (int j=0;j<26;j++)
            {
                if(ships[j]>=containers[i])
                {
                    ships[j]=containers[i];
                    break;
                }
            }
        }
        int pilas=0;
        for(auto a:ships)
        {
            if(a!='{') pilas++;
        }
        cout<<"Case "<<testcases<<": "<<pilas<<endl;
    }
    return 0;
}