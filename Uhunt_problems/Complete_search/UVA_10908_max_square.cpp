#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>

using namespace std;

 // Son los valores de la matriz

struct location
{
    int r,c;
    location (){}
    location(int r,int c)
    {
        this->r=r;
        this->c=c;
    }

};

int side_number(int j)
{
    return 2*j+1;
}

bool evaluate_square(vector<vector<char>> mat, location centro, int num, int M, int N)
{
    char charcenter=mat[centro.r][centro.c];

    if(centro.r-num<0 || centro.r + num>=M) return false;
    if(centro.c-num<0 || centro.c + num>=N) return false;
    //Nos pasamos de los límites establecidos

    for (int j=centro.r-num;j<=centro.r+num;j++)
    {
        if(mat[j][centro.c-num]!=charcenter || mat[j][centro.c+num]!=charcenter) return false;
    }
    for (int k=centro.c-num;k<=centro.c+num;k++)
    {
        if(mat[centro.r-num][k]!=charcenter || mat[centro.r+num][k]!=charcenter) return false;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int M,N,Q;
        scanf("%d %d %d", &M, &N, &Q);
        vector<vector<char>> mat(M,vector<char>(N));
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++) cin>>mat[i][j];
        }
        vector<int> sols;
        int val=Q;
        while(Q--)
        {
            int cinit=0;
            int r,c;
            scanf("%d %d",&r,&c);
            location center(r,c);
            while(evaluate_square(mat,center,cinit,M,N))
            {
                cinit++;
            }
            sols.push_back(side_number(cinit-1));
        }
        printf("%d %d %d\n", M, N, val);
        for (vector<int>::iterator it=sols.begin();it!=sols.end();++it) cout<<*it<<endl;
        
    }
    return 0;
}