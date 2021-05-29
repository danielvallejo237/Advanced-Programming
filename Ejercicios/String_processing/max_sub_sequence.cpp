#include <bits/stdc++.h>

using namespace std;
/*Solución de encontrar la máxima subsecuencia de cadena de caracteres, para esto creo que es
mejor el algoritmo de Waterman-Smith, pero probaremos con el algoritmo de Needlemann-Wunsh*/

void printMat(const vector<vector<int> > &MT)
{
    for (int i=0;i<MT.size();i++)
    {
        for(int j=0;j<MT[0].size();j++) cout<<MT[i][j]<<"\t";
        cout<<endl;
    }
}

void constructNWMat(const string &A, const string &B,int e,int ha, int hb)
{
    //Vamos a suponer en este caso que la matriz A es de 
    //dimensión menor o igual a la matriz B
    int ridx=A.size();
    int cidx=B.size();
    vector<vector<int>> MT(A.size()+1,vector<int> (B.size()+1,0)); //Reservamos memoria de la matriz;
    //La esquina superior izquierda es siempre 0
    MT[0][0]=0;
    //Inicializar filas y columnas 
    for(int i=1;i<MT[0].size();i++) MT[0][i]=MT[0][i-1]+ha;
    for(int i=1;i<MT.size();i++) MT[i][0]=MT[i-1][0]+hb;
    for(int i=1;i<MT.size();i++)
    {
        for(int j=1;j<MT[0].size();j++)
        {
            if(A[i-1]==B[j-1])
            {
                MT[i][j]=MT[i-1][j-1]+e;
            }
            else{
                MT[i][j]=std::max(MT[i-1][j]+hb,MT[i][j-1]+ha);
            }
            //
        }
    }
    printMat(MT);
    cout<<"Longitud de la mayor subsecuencia comun: "<<MT[ridx][cidx]<<endl; 
}

int main()
{
    string B="ACAATCC";
    string A="AGCATGC";
    constructNWMat(A,B,1,0,0);
    return 0;
}