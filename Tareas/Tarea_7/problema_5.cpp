#include <bits/stdc++.h>

using namespace std;

//Programación del algoritmo de euclides extendido //
/*
@Author Daniel Vallejo Aldana 
Licenciatura en Computación */

void extendedEuclid(int a, int b, int &gcd, int &x, int &y)
{
    if(b==0){x=1;y=0;gcd=a;return;}
    int xnew,ynew;
    extendedEuclid(b,a%b,gcd,xnew,ynew);
    x=ynew;
    y=xnew -(a/b)*ynew;
}

int main()
{
    int x,y,gcd;
    int a,b;
    int l,u;
    cin>>a>>b>>l>>u;
    extendedEuclid(a,b,gcd,x,y);
    if(gcd!=1) cout<<"No hay solucion"<<endl;
    else
    {
        x=(x%b+b)%b;
        //Recordemos que para a(x+km) mod m también es una solución
        int lowerbound,upperbound;
        lowerbound=ceil((l-x)/b); //K debe de cumplir una serie de desigualdades que se corroboran aquí
        upperbound=floor((u-x)/b);
        if(lowerbound>upperbound) swap(lowerbound,upperbound);
        //cout<<lowerbound<<" "<<upperbound<<endl;
        cout<<"Printing modular multiplicative inverse numbers: "<<endl;
        for(int i=lowerbound;i<=upperbound;i++) cout<<x+i*b<<" ";
        cout<<endl;
    }  
    return 0;
}