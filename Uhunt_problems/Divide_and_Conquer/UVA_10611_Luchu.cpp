/*@Author Daniel Vallejo Aldana

Licenciatura en computación 

Problema: Esta implementación funciona sin embargo el tiempo de ejecución es mayor al permitido
ya que la función upper_bound y lower_bound encuentran las cosas en orden lineal 
*/


#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back

void process_query(ll height, vector<ll> personas, vector<ll> reversa)
{
    
    vector<ll>::iterator it2=upper_bound(reversa.begin(),reversa.end(),-height);
    if(it2!=personas.end()) cout<<-1*(*it2)<<" ";
    else cout<<"X"<<" ";
    vector<ll>::iterator it=upper_bound(personas.begin(),personas.end(),height);
    if(it!=personas.end()) cout<<*it<<endl;
    else cout<<"X"<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //Desactivar la sincronización con el stdio
    ll ladys;
    scanf("%lld",&ladys);
    vector<ll> sujetos;
     vector<ll> reversed(ladys);
    for (ll i=0;i<ladys;i++)
    {
        ll subj;
        scanf("%lld",&subj);
        sujetos.pb(subj);
        reversed[ladys-1-i]=-subj;
    }
    ll querys;
    scanf("%lld",&querys);
    vector<ll> alturas;
    for (ll i=0;i<querys;i++)
    {
        ll altura;
        scanf("%lld",&altura);
        alturas.pb(altura);
        
    }
    for (ll i=0;i<querys;i++)
    {
        process_query(alturas[i],sujetos,reversed);
    }
    return 0;
}