#include <bits/stdc++.h>

using namespace std;

//Hagamos un test de primalidad de un número p utilizando el pequeño teorema de fermat
#define MAXITER 6

bool isFermatsPPrime(int n)
{
    bool isprime=true;
    if(n>3)
    {
        for(int i=0;i<MAXITER;i++)
        {
            int x= rand() % (n-3) + 2;
            if((int)pow(x,n-1) % n != 1)
            {
                isprime=false;
                break;
            } 
        }
    }
    if(n<=0) isprime=false;
    
    return isprime;
}

int main()
{
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    int p;
    cin>>p;
    if(isFermatsPPrime(p)) cout<<"El número es primo"<<endl;
    else cout<<"El número no es primo"<<endl;
    return 0;

}

/* 
La implementación anterior hecha de forma ingenua no es eficiente ya que la función de potencia modular no es demasiado efectiva*/