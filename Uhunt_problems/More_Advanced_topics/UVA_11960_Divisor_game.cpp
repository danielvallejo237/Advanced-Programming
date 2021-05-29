#include <bits/stdc++.h>
/*
La idea principal del problema es hacer un precalculo del numero con mayor divisores menores que n
y guardarlo en una tabla de dp, de esta forma accedemos al resultado en 0(1) porque es acceder 
a un elemento del vector que es en tiempo constante.
*/
using namespace std;

#define N 1000000

int dp[N+3], numdv[N+3];

void Precalculo() {
    for (int i=0; i<=N; i++) {
        numdv[i] = 1;
    }
    for (int i=2; i<=N; i++) {
        numdv[i]++;
        for (int j=i+i; j<=N; j+=i)
            numdv[j]++;
    }
    dp[1] = 1;
    for (int i=2; i<=N; i++) {
        if (numdv[i]>=numdv[dp[i-1]])
            dp[i] = i;
        else dp[i] = dp[i-1];
    }
}

int main() 
{
    Precalculo();
    int testcases, n;
    scanf("%d", &testcases);
    while (testcases--) {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
}