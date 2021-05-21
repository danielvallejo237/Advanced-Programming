#include <bits/stdc++.h>

using namespace std;

/*
    @Author Daniel Vallejo Aldana Licenciatura en Computación
    Tarea 8
*/

/*Problema de los Hotcakes, aplicamos la misma idea que en el problema 2 solo que en este caso nos va a 
interesar cuál es la entrada final de la matriz que podemos alcanzar y de ahí regresar el número de espacios
*/
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

int PilaHotCakes(string A, string B)
{
    //Por simplicidad asumamos que Alfonso hace menos Hotcakes que Berta
    //Esto se puede cambiar 
    int rows=A.size()+1;
    int cols=B.size()+1;
    assert(rows<=cols); //Checar que no sea una matriz rectangular con una cadena más grande que otra
    int p1=-1,p2=-1;
    int cant1=0;
    vector<vector<int>> MT(rows,vector<int>(cols)); //Es la matriz de Match
    //En este caso no se ocupa la reversa de la cadena
    for(int i=0;i<rows;i++) fill(MT[i].begin(),MT[i].end(),0);
    for(int i=1;i<rows;i++)
    {
        for(int j=1;j<cols;j++)
        {
            if(A[i-1]==B[j-1])
            {
                MT[i][j]=1+MT[i-1][j-1]; //De la diagonal
            }
            else
            {
                MT[i][j]=std::max(MT[i-1][j],MT[i][j-1]);
            }
            if(MT[i][j]>cant1)
            {
                p1=i;
                p2=j;
            }
        }
    }
    int spaces=p1+p2-2*MT[p1][p2];
    //printMat(MT);
    return spaces;
}

int main()
{
    string A,B;
    cin>>A>>B;
    if(A.size()>B.size())
    {
        swap(A,B);
    }
    cout<<"Hotcakes a quitar: "<<PilaHotCakes(A,B)<<endl;
    return 0;
}