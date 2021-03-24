#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll countAstring(string s)
{
    ll cuenta=0;
    for(char const &c:s) if (c=='a') cuenta++;
    return cuenta;
}

ll countA(string s, ll n) //La cuenta de la cadena infinita
{
    ll complete=(ll)n/(ll)s.size()*countAstring(s);
    ll index=(ll)n/(ll)s.size()*(ll)s.size();
    complete+=countAstring(s.substr(index % s.size(),n % s.size()));
    return complete;
}

int main()
{
    ll n;
    string cadena;
    cin>>cadena;
    cin>>n;
    cout<<countA(cadena,n)<<endl;
    return 0;
}