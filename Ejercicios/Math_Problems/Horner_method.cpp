#include <bits/stdc++.h>

using namespace std; 

/*
 * Implementación del Método de Horner para evaluación eficiente de polinomio 
 * */

 
 double Horner(vector<double> cf, int n,double x)
 {
	 double result=cf[0];
	 for (int i=1;i<n;i++)
	 {
		 result=result*x+cf[i];
	 }
	 return result;
 }

int main()
{
	vector<double> coef;
	coef.push_back(2.0);
	coef.push_back(3.3);
	coef.push_back(5.0);
	int n=coef.size();
	cout<<Horner(coef,n,4.0)<<endl;
	return 0;
}

