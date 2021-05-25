#include <bits/stdc++.h>
//Inclusión de las librerías 
using namespace std;

int costo(int matchs,int row,int pos, int cmatch, int cspace)
{
    int spaces=row+pos-2*matchs;

    return matchs*cmatch+spaces*cspace;
}

void printMat(const vector<vector<int>> &M)
{
    int rows=M.size();
    int cols=M[0].size();
    for(int i=0;i<rows;i++) 
    {
        for(int j=0;j<cols;j++)
        {
            cout<<M[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int MaximoCosto(string A, string B)
{
    int lower_bound=-100000; 
    /*Es el mínimo costo que tenemos que superar en cada caso que vayamos recorriendo la matriz*/
    assert(A.size()<=B.size()); //La cadena más pequeña es de 
    //Los renglones y la más grande es de las columnas
    vector<vector<int>> MT(A.size()+1,vector<int>(B.size()+1));
    int costomatch=2;
    int costoespacio=-1;
    int rows,cols;
    rows=A.size()+1;
    cols=B.size()+1;
    //Las cadenas te las pide en reversa
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    for(int i=0;i<rows;i++) fill(MT[i].begin(),MT[i].end(),0);
    //Viene el ciclo de llenado de la matriz, claamente esto es de orden cuadrático pero pues no hay opción
    for(int i=1;i<rows;i++)
    {
        for(int j=1;j<cols;j++)
        {
            if(A[i-1]==B[j-1]) //Esto implica que hay match
            {
                MT[i][j]=1+MT[i-1][j-1];
            }
            else
            {
                //Si no tnemos match
                MT[i][j]=std::max(MT[i][j-1],MT[i-1][j]);
                /*
                Esto si nos da un rango de memoria válida por las columans y renglones agregados como padding
                */
            }
            int cost=costo(MT[i][j],i,j,costomatch,costoespacio);
            lower_bound=(cost > lower_bound) ? cost : lower_bound; //Vamos actualizando el costo en cada uno de los renglones
        }
    }
    printMat(MT);
    return lower_bound;
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    if(s1.size()>s2.size())
    {
        swap(s1,s2);
    }
    int p=MaximoCosto(s1,s2);
    cout<<"Ganancia Máxima: "<<p<<endl;
    return 0;
}