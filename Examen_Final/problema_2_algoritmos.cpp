#include <bits/stdc++.h>

//Daniel Vallejo Aldana Licenciatura en computacíón
//Ejercicio 5 de la pregunta 2

//Solo se pudo implementar el algoritmo para determinar la función z de una cadena, no se me ocurrió como
//Encontrar una cadena patrón en una cadena más grande.
using namespace std;

vector<int> Z_func(string s)
{
    int n = s.size();
    vector<int> z(n,0);
    int k,l;
    k=0;
    l=0; //Inicializamos los valores como lo pide en el algoritmo
	for (int i = 1;i < n; i++)
     {
         //Primer caso en el que i>l
         if(i>l)
         {
              while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                {
                    z[i]++;
                    //Vamos buscando un match de i desde el inicio de la cadena.
                }
         }
		else 
        {
            //Como dice el algoritmo empezamos desde zmin
            z[i] = std::min(z[i-k], l-i+1);
            if (i + z[i] - 1 > l)
            {
                k = i; //Actualizamos los valores de k y l en caso de que necesiten ser actualizados
                l = i + z[i] - 1;
            }
        }
	}
	return z;
}

int main()
{
	string s="bababa"; //Prueba con la cadena patrón
    vector<int> salida=Z_func(s);
    cout<<"Prueba para el caso de "+s<<endl;
    for(vector<int>::iterator it=salida.begin();it!=salida.end();++it) cout<<*it<<" ";
    cout<<endl;
	return 0;
}

