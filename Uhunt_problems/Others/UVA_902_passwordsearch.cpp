#include <bits/stdc++.h>

using namespace std;

string find_password(int size, string encoded)
{
    map<string,int> freqs;
    int max=0;
    string argmax;
    for(int i=0;i<encoded.size()-size;i++)
    {
        string aux=encoded.substr(i,size);
        if(freqs.find(aux)==freqs.end())
        {
            freqs[aux]=1;
        }
        else
        {
            freqs[aux]+=1;
        }
        if(freqs[aux]>max)
        {
            max=freqs[aux];
            argmax=aux;
        }
    }
    return argmax;
}


int main()
{
    string codigo;
    int tamano;
    while(cin>>tamano>>codigo && tamano)
    {
        cout<<find_password(tamano,codigo)<<endl;
    }
    return 0;
}