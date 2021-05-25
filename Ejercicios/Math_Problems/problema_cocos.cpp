#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; // n es el número de cocos que se colectaron
    //Buscamos entonces un entero p que cumpla las siguientes condiciones
    /*
    p divide a n-1 y p está en el rango de 2 a sqrt(n-1) */
    while(cin>>n && n>=0)
    {
        int popt=-1;
        for(int i=std::max(2,(int)sqrt(n-1));i>=2;i--)
        {
            //Checamos si es un candidato a divisor
            if((n-1)/i>0 && (n-1) % i==0)
            {
                //Entonces si es un divisor
                bool possible=true; //Ahora vamos a checar sobre todo el número de personas a ver si si sale bien
                int aux=n;
                for(int l=1;l<=i;l++)
                {
                    if(aux%i != 1)
                    {
                        possible=false;
                        break;
                    }
                    else
                    {
                        aux-=((aux-1)/i +1); //La persona esconde su parte de los cocos
                    }
                }
                if(aux%i!=0) continue;
                if(possible)
                {
                    popt=i; //Esto nos da el mayor número de personas
                    break;
                } 
            }
        }
        if(popt <0)
        {
            cout<<n<<" coconuts, no solution"<<endl;
        }
        else 
        {
            cout<<n<<" coconuts, "<<popt<<" people and 1 monkey"<<endl;
        }
    }
}