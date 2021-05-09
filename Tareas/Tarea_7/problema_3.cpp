
#include <bits/stdc++.h>

using namespace std;

/* Programa que determina el mayor de los factores que suman n*/
/*
@Author Daniel Vallejo Aldana 
Licenciatura en Computación */

int find_sum_divisors(int j)
{
    vector<int> divisors;
    for(int i=1;i<=j;i++)
    {
        if(j%i==0) divisors.push_back(i);
    }
    return accumulate(divisors.begin(),divisors.end(),0);
}

int find_biggest(int init)
{
    for(int k=(init-1);k>=0;k--)
    {
        if(find_sum_divisors(k)==init) return k; 
    }
    return -1;
}

int main()
{
    int n;
    while(cin>>n) cout<<"Numero correspondiente: "<<find_biggest(n)<<endl;
    return 0;
}