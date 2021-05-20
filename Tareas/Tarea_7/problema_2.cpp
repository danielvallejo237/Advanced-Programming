//Daniel Vallejo Aldana

#include <bits/stdc++.h>

using namespace std;
#define MAXINT 10000000

bitset<MAXINT+1> isPrime; //Indicador si un número es primo o no

/*IDEA: La idea es construir la matriz de nxn con el espiral de Ulam y
después de eso hacer una matriz binaria en donde 1 representa que el número es
primo y 0 representa que dicho número no es primo, al final sacar la proporción de la
suma de la diagonal entre la suma total (las dos son en O(N^2)) y aumentar N hasta que 
obtengamos que la proporción es menor al 10% o 0.1
*/

namespace ulam{

float prop=0.1;

void getPrimes()
{
    isPrime.reset();
    isPrime.flip();
    isPrime[0]=isPrime[1]=0;
    for (int i=2;i*i<=MAXINT;i++)
    {
        if(isPrime[i])
        {
            for(int j=i*i;j<=MAXINT;j+=i) isPrime[j]=0;
        }
    }
}

vector< vector<int> > Build(int N)
{
    vector<vector<int>> M(2*N+1,vector<int>(2*N+1));
    int r,c,current,counter;
    M[N][N]=1;
    r=N;
    c=N+1;
    counter=2;
    current=2;
    for(int j=0;j<N;j++,counter+=2)
    {
        for(int i=0;i<counter;i++) M[r--][c]=current++;
        r++;
        c--;
        for(int i=0;i<counter;i++) M[r][c--]=current++;
        c++;
        r++;
        for(int i=0;i<counter;i++) M[r++][c]=current++;
        r--;
        c++;
        for(int i=0;i<counter;i++) M[r][c++]=current++;
    }
    return M;
}

void print(const vector<vector <int>> &M)
{
    for(int i=0;i<M.size();i++)
    {
        for(int j=0;j<M[0].size();j++) cout<<M[i][j]<<"\t";
        cout<<"\n";
    }
}

vector<vector<int> > PrimeMatrix(const vector<vector<int>> &M)
{
    vector<vector<int>> BM(M.size(),vector<int>(M[0].size()));
    for(int i=0;i<M.size();i++)
    {
        for(int j=0;j<M[0].size();j++)
        {
            if(isPrime[M[i][j]]) BM[i][j]=1;
            else BM[i][j]=0;
        }
    }
    return BM;
}

int FullSum(const vector<vector<int>> B)
{
    //Recibe la matriz binaria de entrada y calcula la suma
    int suma=0;
    for(int i=0;i<B.size();i++) for (int j=0;j<B[0].size();j++) suma+=B[i][j];
    return suma;
}

int DiagSum(const vector<vector<int>> B)
{
    int diagonal=0;
    for(int i=0;i<B.size();i++)
    {
        for(int j=0;j<B[0].size();j++)
        {
            if(i==j || j+i==B.size()-1) diagonal+=B[i][j];
        }
    }
    return diagonal;
}

float getProportion(int N)
{
    vector<vector<int>> M=Build(N);
    vector<vector<int>> B=PrimeMatrix(M);
    return (float)DiagSum(B)/(float)FullSum(B);
}

};

int main()
{
    ulam::getPrimes();
    float prop=1;
    int cnt=1;
    while(prop>ulam::prop)
    {
        prop=ulam::getProportion(cnt);
        cnt++;
    }
    cout<<"N deseada: "<<cnt-1<<endl;
    //cout<<ulam::getProportion(21)<<endl;
    return 0;
}