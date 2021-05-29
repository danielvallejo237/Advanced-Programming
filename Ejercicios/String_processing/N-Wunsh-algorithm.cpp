#include <bits/stdc++.h>

using namespace std;

void printMat(const vector<vector<int> > &MT)
{
    for (int i=0;i<MT.size();i++)
    {
        for(int j=0;j<MT[0].size();j++) cout<<MT[i][j]<<"\t";
        cout<<endl;
    }
}

void constructNWMat(const string &A, const string &B,int e,int d,int ha, int hb)
{
    //Vamos a suponer en este caso que la matriz A es de 
    //dimensión menor o igual a la matriz B
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
                MT[i][j]=std::max(MT[i-1][j-1]+e,std::max(MT[i-1][j]+hb,MT[i][j-1]+ha));
                /*
                    Lo anterior es que puede que exista un match pero que realmente no valga la pena hacer esa inserción,
                    y valga la pena mejor insertar algún espacio en las cadenas A o la cadena B
                */
            }
            else{
                MT[i][j]=std::max(MT[i-1][j-1]+d,std::max(MT[i-1][j]+hb,MT[i][j-1]+ha));
                //De igual forma aquí abajo cuando no existe algún match
            }
            //
        }
    }
    printMat(MT);

}

int main()
{
    string B="ACAATCC";
    string A="AGCATGC";
    constructNWMat(A,B,2,-1,-1,-1);
    return 0;
}