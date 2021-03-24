
#include <bits/stdc++.h>

using namespace std;
#define ll long long 

ll sign(ll num)
{
    if (num==0) return 0;
    else return (num < 0) ? -1: 1; 
}

ll value(char ist)
{
    if (ist=='U') return 1;
    else return -1;
}


int main()
{
    ll steps;
    string path;
    cin>>steps;
    cin>>path;
    //cout<<steps<<endl<<path<<endl;
    ll valley_coun=0;
    ll recorrido=0;
    ll new_sign=sign(valley_coun);
    for (char const &c:path)
    {
        recorrido+=value(c);
        //cout<<recorrido<<endl;
        if(new_sign<0 && sign(recorrido)>=0) valley_coun++;
        new_sign=sign(recorrido);
    } 
    cout<<valley_coun<<endl;
    return 0;
}