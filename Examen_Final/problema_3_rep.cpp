#include <bits/stdc++.h>

using namespace std;

//Esta implementación del LCP no es lo más eficiente del mundo pero funciona
/*
Idea en la implementación de este problema:
Lo que intentamos es calcular la secuencia más grande repetida dentro de la cadena 
para esto consideramos el número de repeticiones de cada subcadena y vemos que una cadena se repite o no si es el 
prefijo más largo que puede encontrarse dadas dos subcadenas .
Luego notemos que estas ocurrencias o frecuencias se guardan en un mpa de cadenas de caracteres y enteros para poder imporimir
la mayor subsecuencia con mayor que k repeticiones
El algoritmo aquí implementado es de orden cúbico, se puede mejorar con un suffic array pero la verdad no se me ocurrió muy bien como 
eso podía suceder.
*/

string lcp(string s, string t)
{  
    int n = std::min(s.size(),t.size());  
    for(int i = 0; i < n; i++)
    {  
        if(s[i] != t[i])
        {  
            return s.substr(0,i); //Regresamos el mayor prefijo común   
            break;
        }  
    }  
    return s;
}  
  
int main()  
{  
    map<string,int> mpstr;
    int k=3;
    string str = "baaaababababbababbab";  
    string x,lrs;
    int i,j,n = str.size();  
    string s1,s2;
    for(i = 0; i < n; i++){  
    for(j = i+1; j < n; j++)
    {  
        s1=str.substr(i,n);
        s2=str.substr(j,n); 
        //cout<<s1<<" "<<s2<<endl;
        x=lcp(s1,s2);  
        mpstr[x]+=1;
        //El algoritmo es de orden n^{3}
        if(x.size() > lrs.size() && mpstr[x]>k) //La cadena se repite más de k veces 
        {
            lrs=x;
        }  
        }  
    } 
    if(lrs.size()!=0) cout<<"La cadena del mensaje es "<<lrs<<endl;
    else cout<<"None"<<endl;
    //El algirtmo no calcula todas las subcadenas solo una de ellas
      
  return 0;  
}  