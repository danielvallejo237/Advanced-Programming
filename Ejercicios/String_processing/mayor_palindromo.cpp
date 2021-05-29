#include <bits/stdc++.h>

using namespace std;

/*
Calcular los palíndromos más grandes de la subsecuencia s de tamaño n
*/

void printMat(const vector<vector<int>> &MT)
{
    for(int i=0;i<MT.size();i++)
    {
        for(int j=0;j<MT[0].size();j++) cout<<MT[i][j]<<"\t";
        cout<<endl;
    }
}

void BuildMat(string s)
{
    //En este caso nuestra matriz es una matriz cuadrada de dimensión nxn
    //Insertamos caracteres fantasma
    s="@"+s+"@";
    int rows=s.size();
    int cols=s.size();
    int maximo=-10000;
    vector<vector<int>> MT(rows,vector<int> (cols,0));
    //Después de esta inicialización queda una matriz diagonal 
    for(int i=0;i<rows;i++) MT[i][i]=1;
    for(int i=0;i<rows-1;i++)
    {
        if(s[i]==s[i+1])MT[i][i+1]=2;
        else 
        {
            MT[i][i+1]=1;
        }
    }
    for(int i=1;i<rows-1;i++)
    {
        for(int j=1;j<cols-1;j++)
        {
            if(s[i]==s[j]) MT[i][j]=2+MT[i+1][j-1];
            else 
            {
                MT[i][j]=std::max(MT[i+1][j],MT[i][j-1]);
            }
            if(MT[i][j]>maximo)
            {
                maximo=MT[i][j];
            }
        }
        
    }
    printMat(MT);
    reverse(s.begin(),s.end());
    s.pop_back();
    reverse(s.begin(),s.end());
    s.pop_back();
    cout<<"Longitud del mayor palíndromo en la cadena "+s+": "<<maximo<<endl;
}

int main()
{
    string s="dalad";
    BuildMat(s);
    return 0;
}

