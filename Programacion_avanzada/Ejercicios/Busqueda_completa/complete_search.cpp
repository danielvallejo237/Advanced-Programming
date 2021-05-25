/*Solución del problema de las cadenas balanceables
 *Dada una cadena encontrar todas las cadenas balancebles
 * Definición de String balanceable:
 * Decimos que un punto 1<=i<=n  balancea al punto 
 * si las cantidades A y B suman 0 en dicho punto
 * A= Sum (i=1,k por la izquierda) i*value
 * B= Sum (i=1,k por la derecha) i*value*/
 
 /*Buscar si una cadena es balanceable es de orden O(nlog(n)) */


#include<bits/stdc++.h>

using namespace std;

#define ll long long int

class BalancedSubstrings
{
	public:
	ll countSubstrings(string S)
	{
		ll solutions=0;
		for( ll i=0;i<S.size();i++)
		{
			ll L=0;
			ll R=0; //Momentos de fuerza
			ll idx=i;
			ll Lsize=0;
			ll Rsize=0; //Numeros de 1 en la derecha e izquierda
			solutions++; //Una cadena de 1 siempre es balanceable
			for(ll j=i+1;j<S.size();j++)
			{
				if(S[j]=='1')
				{
					R +=(j-idx); //Basicament estamos sumando el valor hacia la derecha
					Rsize++;
				}
				while((R>L) && (idx<j)) //Aqui estamos moviendo el punto de balanceo
				{
					L+=Lsize;
					if(S[idx]=='1')
					{
						Lsize++;
						L++;
					}
					R-=Rsize;
					idx++;
					if(S[idx]=='1')
					{
						Rsize--;
					}
				}
				if(L==R) solutions++; //Se balancea la cadena hasta que el torque del lado derecho sea igual al torque del lado izquierdo
			}
		}
		return solutions;
		
	}
	
};
int main()
{
	BalancedSubstrings bcss;
	cout<<"Cadenas balanceables: "<<bcss.countSubstrings("011")<<endl;
	return 0;
}
