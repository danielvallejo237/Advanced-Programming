#include <bits/stdc++.h>

using namespace std;
#define ld long double
#define ll long long
//Según yo el camino del rey más largo cruza por todas las casillas y tiene (n-2) cruces en diagonal
//Los casos base son 0 y 1 donde la distancia euclideana es 0 porque llegamos l mismo punto

/*Explicación del problema:

Notemos primero que la distancia en el tour del Rey se maximiza al hacer más recorridos en diagonal
entre las casillas, por esta razón hay que encontrar el camino que contenga el mayor número de diagonales 
y que pase por todas las casillas del cuadro de ajedréz, simulando este proceso y tomando en cuenta que 
los cuadros tienen distancia unitaria.

Al simular el proceso se vió que a lo más había (n-2)^{2} diagonales por lo tanto se conjetura que el número de diagonales 
en un recorrido del rey es a lo más (n-2)^{2}

De lo anterior vemos que la distancia máxima para el recorrido del rey es

D(n)=(n^{2}-(n-2)^{2})+sqrt(2)(n-2)^{2}

*/

ld Ways(ll n)
{
    if(n==0 || n==1) return 0.0;
    else return (ld)(pow(n,2)-pow((n-2),2))+(ld)pow((n-2),2)*sqrt(2);
}


int main()
{
    ll n;
    while(cin>>n){
        if (n==-1) break;
    cout<<"Longitud más larga del camino del rey: "<<Ways(n)<<endl;
    }
    return 0;

}