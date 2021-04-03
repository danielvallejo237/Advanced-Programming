#include<bits/stdc++.h>

using namespace std;

int GetIndex(char c)
{
    return (int)c-65;
}

char getChar(int c)
{
    return (char)(c+65);
}

bool isin(int a, int b, int x)
{
    return (x>=a && x<=b);
}

int main()
{
    //cout<<"Indice "<<GetIndex('A')<<endl;
    int problems,teams,submissions;
    scanf("%d%d%d",&problems,&teams,&submissions);
    //assert(isin(5,12,problems) && isin(10,100,teams) && isin(1,1000,submissions));
    //Creamos una matriz de problemas x 3
    int P[problems][2];
    map<int,set<int> > equipos_aceptados;
    fill(&P[0][0],&P[problems][1],-1); //Hasta la parte del fill todo va bien
    while (submissions--)
    {
        string veredict;
        char prob;
        int time;
        int team;
        cin>>time>>team>>prob>>veredict;
        if(veredict.compare("No")==0) continue;
        else
        {
            if(equipos_aceptados[GetIndex(prob)].find(team)==equipos_aceptados[GetIndex(prob)].end())
            {
                P[GetIndex(prob)][0]=time;
                P[GetIndex(prob)][1]=team;
                equipos_aceptados[GetIndex(prob)].insert(team);
            }
            //cout<<time<<team<<endl;
        }
    }
    for (int i=0;i<problems;i++)
    {
        cout<<getChar(i)<<" ";
        for(int k=0;k<2;k++)
        {
            if (k==0 && P[i][k]==-1) cout<<"- ";
            else if(k==0 && P[i][k]!=-1) cout<<P[i][k]<<" ";
            if (k==1 && P[i][k]==-1)cout<<"-"<<endl;
            else if (k==1 && P[i][k]!=-1) cout<<P[i][k]<<endl;
        }
    }
    return 0;
}