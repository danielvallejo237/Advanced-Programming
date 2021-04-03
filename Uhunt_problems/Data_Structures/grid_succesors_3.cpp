#include <bits/stdc++.h>

using namespace std;


int g[3][3]; //Es el tamaño estandar del grid

void computeSum()
{
    int h[3][3];
    h[0][0]=(g[0][1]+g[1][0])%2;
    h[0][1]=(g[0][0]+g[0][2]+g[1][1])%2;
    h[0][2]=(g[0][1]+g[1][2])%2;

    h[1][0]=(g[0][0]+g[1][1]+g[2][0])%2;
    h[1][1]=(g[0][1]+g[1][0]+g[1][2]+g[2][1])%2;
    h[1][2]=(g[0][2]+g[2][2]+g[1][1]) %2;

    h[2][0] = (g[2][1] + g[1][0]) % 2;
	h[2][1] = (g[2][0] + g[1][1] + g[2][2]) % 2;
	h[2][2] = (g[2][1] + g[1][2]) % 2;

    for (int i=0;i<3;i++)
    for (int j=0;j<3;j++) g[i][j]=h[i][j];
    
}

bool isFinite()
{
    for(int i=0;i<3;i++)
    for (int j=0;j<3;j++) if (g[i][j]>0) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            scanf("%1d",&g[i][j]);
        }
        int ans=-1;
        while(!isFinite())
        {
            computeSum();
            ans++;
        }
        printf("%d\n",ans);
    }
}

