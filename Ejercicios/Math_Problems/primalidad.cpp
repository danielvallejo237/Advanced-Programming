#include<bits/stdc++.h>

using namespace std;

/*Test de primalidad de las formas eficientes */
#define li unsigned long int

bool isPrime(li num)
{
    if(num==1 || num==2) return true;
    if(num==0) return false;
    for (li i=2;i<=sqrt(num);++i)
    {
        if (num % i ==0)
        {
            return false;
        }
    }
    return true;
}


int main()
{
    ios_base::sync_with_stdio(false);
    li n;
    cin>>n;
    map<int,string> mp;
    mp[0]="No";
    mp[1]="Si";
    cout<<"Es primo?: "<<mp[isPrime(n)]<<endl;
    return 0;
}