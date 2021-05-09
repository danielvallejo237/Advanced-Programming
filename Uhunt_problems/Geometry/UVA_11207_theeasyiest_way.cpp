#include <bits/stdc++.h>

using namespace std;

// Recibimos el numero de casos de prueba, la altura y el ancho de las piezas
//de papel
int main()
{
    int n; //Número de piezas de papel
    while(cin>>n && n>0)
    {
        int w,h;
        double max=0.0;
        int maxindex=0;
        for (int i=0;i<n;i++)
        {
            cin>>w>>h;
            double prueba=std::max(min(w, h)/2.0,std::max(min<double>(w/4.0, h), min<double>(w, h/4.0)));
            if(prueba>max)
            {
                max=prueba;
                maxindex=i;
            }
        }
        cout<<maxindex+1<<endl;
    }
    return 0;

}