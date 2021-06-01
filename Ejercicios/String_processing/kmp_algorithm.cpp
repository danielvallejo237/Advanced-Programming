
#include <bits/stdc++.h>

using namespace std;

vector<int> resets(1000,0); //El arreglo de resets para la cadena patron
/*
For the pattern “AAABAAA”, 
lps[] is [0, 1, 2, 0, 1, 2, 3]
*/

void kmpProcessPattern(const string &pattern)
{
    //Procesamiento de la cadena patrón para calcular los prefijos que son también sufijos
    //Esto se logra teniendo dos iteradores paralelos de la longitud y de la i
    resets[0]=0;
    int len=0;
    int i=1;
    while(i<pattern.size())
    {
        //Mientras recorramos toda la cadena
        if(pattern[len]==pattern[i])
        {
            //Calculamos los prefijos más grandes que son también sufijos
            len++;
            i++;
            resets[i-1]=len;
            //cout<<len<<endl;
        }
        else
        {
            if(len==0)
            {
                resets[i]=0;
                i++;
            }
            else
            {
                len = resets[len-1];
                
            }
        }
    }
}

int kmpfindPattern(const string &text, const string &pattern)
{
    /*
    Esta funcion cuenta las courrencias de una cadena patrón en una cadena de texto
    principal usando el arreglo de resets  
    */
    //Iniciamos con el algoritmo naive 
    int i=0;int j=0;int nc=0; //Todo lo inicializamos en 0
    while(i<text.size())
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
            if(j==pattern.size())
            {
                nc++; //Aumentamos el número de cuneta
                j=resets[j-1]; //El último reset 
            }
        }
        else
        {
            if(j>0)
            {
                j=resets[j-1];
            }
            if(j==0)
            {
                i++;
            }
        }
    }
    return nc;
}


int findOcurrences(const string &text, const string &pattern)
{
    fill(resets.begin(),resets.end(),0);
    kmpProcessPattern(pattern);
    for(int i=0;i<pattern.size();i++) cout<<resets[i]<<" ";
    cout<<endl;
    int counts=kmpfindPattern(text,pattern);
    return counts;
}


int main()
{
    string s="AABAACAABAA";
    string s2="bababa";
    int cnt=findOcurrences(s,s2);
    cout<<"Ocurrencias de la cadena "+ s2 +" en la cadena "+s+ ": "<<cnt<<endl;
    return 0;
}