#include <bits/stdc++.h>
#include<cstdio>

using namespace std;

int convert(vector<char>);

bool isRight(string cad)
{
    //De acuerdo al formato siempre hay números al inicio y no existen numeros
    //de la forma 0k
    int n1,n2,res;
    vector<char> aux;
    char op;
    bool notsign=true;
    for(auto c : cad)
    {
        if(c>=48 && c<=57 || (!notsign && c!=61)) aux.push_back(c);
        if((c==43 || c==45) && notsign)
        {
            op=c;
            n1=convert(aux);
            aux.clear();
            notsign=false;
        }
        if(c==61)
        {
            n2=convert(aux);
            aux.clear();
        }
    }
    if(aux.front()=='?') return false;
    res=convert(aux);
    //cout<<n1<<" "<<n2<<" "<<res<<endl;
    bool operacion=(op==43) ? 1 :0;
    if(operacion) return((n1+n2)==res);
    else return ((n1-n2)==res);
}

int convert(vector<char> vc)
{
    int num=0;
    if(vc[0]=='-')
    {
        for(int i=1;i<vc.size();i++)
        {
            num+=(vc[i]-48)*pow(10,vc.size()-i-1);
        }
        num=-num;
    }
    else
    {
        for(int i=0;i<vc.size();i++)
        {
            num+=(vc[i]-48)*pow(10,vc.size()-i-1);
        }
    }
    return num;
}

int main()
{
    string cad;
    int fine=0;
    while(getline(cin,cad))
    {
        if(cad.size()==0) break;
        fine+=isRight(cad);
    }
    cout<<fine<<endl;
    return 0;
}