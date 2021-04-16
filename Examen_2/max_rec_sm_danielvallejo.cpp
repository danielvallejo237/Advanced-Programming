#include <bits/stdc++.h>
#include <ctime>

using namespace std;

#define MAX_INT 300 //Aquí se le cambia para el tamaño de la matriz
#define INF -10000
int MaxSum1D(const vector<int> &arr)
{
    int current_max=arr[0];
    int max_general=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        current_max=max(current_max+arr[i],arr[i]);
        max_general=max(current_max,max_general);
    }
    return max_general;
}
int MaxSum2D(const vector<vector<int>> &matriz) //Esta función recibe un vector de dos dimensiones o sea una matriz
{
    int max_suma=-10000;
    int sum; 
    vector<int> temporal(MAX_INT); //El vector auxiliar donde guardamos las sumas de las columnas
    //El vector en el ue guardaremos la suma de la columna o de las columnas 
    int l,r; //se declaran afuera porque se van a usar después 
    for (l=0;l<MAX_INT;l++)
    {
        fill(temporal.begin(),temporal.end(),0);
        //Inicializamos la suma a 0 que es la suma sobre todas las columnas
        for(r=l;r<MAX_INT;r++)
        {
            for(int i=0;i<MAX_INT;i++)
            {
                //Aquí sale el N^{3} o sea si se cumple que el algoritmo es de O(N^3)
                temporal[i]+=matriz[i][r]; //La columna se le suma a nuestro vector temporal
            }
            sum=MaxSum1D(temporal); //Aplicamos el de 1 dimensión sobre el vector de suma de columnas
            //cout<<sum<<endl;
            if(sum>max_suma)
            {
                max_suma=sum;
            }
            
        }
        
    }
    //cout<<max_suma<<endl;
    return max_suma;
}

void printMat(const vector<vector<int>>&matriz)
{
    for(int i=0;i<MAX_INT;i++){ 
    for (int j=0;j<MAX_INT;j++)cout<<matriz[i][j]<<" ";
    cout<<"\n";}
}

int main()
{
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    vector<vector<int>> mat(MAX_INT,vector<int> (MAX_INT)); //Declaramos la matriz de MAX_INT x MAX_INT
    for(int i=0;i<MAX_INT;i++) for(int j=0;j<MAX_INT;j++) mat[i][j]=rand() % 201 -100;
    // Llenado de la matriz de -100 a 100
    //vector<int> a={1,2,3,4,-1,-10}; //Pequeño caso de prueba para el caso de una dimensión
    //cout<<"Maxima suma en vector 1D: "<<MaxSum1D(a)<<"\n";
    if(MAX_INT<10) printMat(mat);
    cout<<"Maxima suma dentro de la matriz: "<<MaxSum2D(mat)<<"\n";
    return 0;
}