#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll fibonacci(ll n)
{
    if(n==0) return 0;
    else if(n==1) return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
    ll numero;
    scanf("%lld",&numero);
    printf("Fibonacci %lld: %lld\n",numero,fibonacci(numero));
    return 0;
}