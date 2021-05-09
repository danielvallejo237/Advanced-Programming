#include <bits/stdc++.h>

using namespace std;
// Fórmula para encontrar el índice de un numero fibonacci de forma rápida

int index(int fbnum)
{
    if (fbnum==0) return 1;
    float fibo=2.078087 *log(fbnum) + 1.672276;
    return round(fibo)-1;
}

void DaVinciCode(const vector<int>&numeros, string chain)
{
    int mel=*max_element(numeros.begin(),numeros.end());
    vector<char> cad(mel,' ');
    string aux;
    for (int i=0;i<chain.size();i++)
    {
        if((chain[i]>=65 && chain[i]<=90)) aux.push_back(chain[i]);
    }
    //cout<<aux;
    for(int j=0;j<numeros.size();j++)
    {
        cad[numeros[j]-1]=aux[j];
    }
    string s(cad.begin(),cad.end());
    cout<<s<<endl;
}

int main()
{
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int digits;
        int dig;
        vector<int> numeros;
        cin>>digits;
        while(digits--) cin>>dig, numeros.push_back(index(dig));
        string cadena;
        getline(std::cin >> std::ws, cadena);
        DaVinciCode(numeros,cadena);
    }
    return 0;
}