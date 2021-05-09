#include <bits/stdc++.h>

using namespace std;

double EPS=1e-9;

double prob(double p, double sujeto,int players)
{
    return p*pow((1-p),sujeto-1)/(1.0-pow((1-p), players)); 
}

int main()
{
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        double p;
        int players;
        int sujeto;
        cin>>players>>p>>sujeto;
        if(p<EPS)
        {
            printf ("0.0000\n");
            continue;
        }
        double proba=prob(p,sujeto,players);
        printf("%.4lf\n", proba);
    }
    return 0;
}