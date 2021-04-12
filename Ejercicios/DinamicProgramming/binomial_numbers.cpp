#include <bits/stdc++.h>

using namespace std;
#define MAX_NUM 100

int mat[MAX_NUM][MAX_NUM];
int Binomial(int N, int k)
{
    if(N==k || k==0) return 1;
    if(mat[N][k]>0) return mat[N][k]; //Ya fue resuelto ese subproblema
    mat[N][k]=Binomial(N-1,k-1)+Binomial(N-1,k);
    return mat[N][k];
}
int main()
{
    int n,k;
    fill(&mat[0][0],&mat[MAX_NUM][MAX_NUM-1],0);
    scanf("%d%d",&n,&k);
    printf("Binomio de %d %d: %d\n",n,k,Binomial(n,k));
    return 0;
}