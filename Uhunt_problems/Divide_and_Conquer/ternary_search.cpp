#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ld long double

ld cuadrado(ld x)
{
    return x*x; // La función x^{2} es unimodal en los intervalos [a,b] donde a<0 y b>0
}
ld ternary_search_min(ld(*function)(ld x),ld left, ld right, ld epsilon)
{
    while (1)
    {
        if(abs(right-left)<epsilon)
        {
            return right+left/2;
        }
        else
        {
            ld leftTercio=left+(right-left)/3;
            ld rightTercio=right-(right-left)/3;
            if (function(leftTercio)>function(rightTercio)) left=leftTercio;
            else right=rightTercio;
        }
    }
}
ld ternary_search_max(ld(*function)(ld x),ld left, ld right, ld epsilon)
{
    while (1)
    {
        if(abs(right-left)<epsilon)
        {
            return right+left/2;
        }
        else
        {
            ld leftTercio=left+(right-left)/3;
            ld rightTercio=right-(right-left)/3;
            if (function(leftTercio)<function(rightTercio)) left=leftTercio;
            else right=rightTercio;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ld a,b;
    scanf("%llf%llf",&a,&b);
    ld medio=ternary_search_min(cuadrado,a,b,0.0001);
    printf("Minimo: %llf\n",medio);
    return 0;
}
