/* Para detectar un ciclo vamos a utilizar el algoritmo de Floyd de la liebre y la 
tortuga sobre un arreglo las funciones a implementar es determinar si existe 
un ciclo en la lista y determinar la cabeza del ciclo que es el ciclo repetido */


#include <bits/stdc++.h>

using namespace std;

int headOfLoop(vector<int> arr)
{
    int tortuga=arr.front();
    int liebre=arr.front();
    while(true)
    {
        tortuga=arr[tortuga];
        liebre=arr[arr[liebre]]; // Damos dos pasos con la liebre
        if(tortuga==liebre) break; //Hemos detectado un ciclo dentro del arreglo
    }
    tortuga=arr.front();
    while(true)
    {
        tortuga=arr[tortuga];
        liebre=arr[liebre];
        if(tortuga==liebre) break;
    }
    liebre=arr[tortuga];
    while(true)
    {
        if(liebre==tortuga) break;
        liebre=arr[liebre];
    }
    return liebre;
}


int main()
{
    int n;
    vector<int> arreglo= {1,2,4,5,3,2,6};
    cout<<"Elemento duplicado: "<<headOfLoop(arreglo)<<endl;
    return 0;
}