#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb(a) push_back(a)

struct edge
{
    ll u,v;
    edge(ll u, ll v)
    {
        this->u=u;
        this->v=v;
    }
    edge(){}
    ~edge(){}
    void crear(ll u, ll v)
    {
        //En caso de inicializar una cosa vacía
        this->u=u;
        this->v=v;
    }
};
struct query
{
    ll l;
    ll r;
    ll block;
    ll idx;
    //Necesitamos una forma de ordenar las consultas y para eso hay que redefinir el operador <
    query(ll l,ll r,ll N,ll idx)
    {
        this->l=l;
        this->r=r;
        this->block= l/sqrt(N);
        this->idx=idx; //Para sacarlas por el mismo indice por el que entraron
    }
    query(){}
    ~query(){}
    //Definimos los constructores de las estructuras vacíos que en este caso son 
    //Constructores vacíos
    bool operator < (const query& consulta) const
    {
        /*Esta redefinición del operador < permite llamar la función sort para ordenar las 
        consultas de acuerdo a los valores de l y r*/
        if(l<consulta.l) return true;
        else if(l==consulta.l)
        {
            return (r<consulta.r);
            //Si las l son iguales entonces nos fijamos en la parte derecha para ordenar
        }
        else //Si la l es mayor en el otro caso entonces es falso que esta consulta sea menor 
        {
            return false;
        }
    } 
};

class UFDS //Esta es la estructura de datos que se va a usar para entontrar los componentes conexos
{
    private:
    vector<ll> parent,rank;
    ll N; 
    public:
    UFDS(){}
    UFDS(ll n) //n es el numero de elementos o de conjuntos disjuntos
    {
        this->N=n;
        rank.assign(N,0);
        /*
        ## NOTA MENTAL ##
        En el assing se asigna primero cuantos y después el valor que se asignara en 
        dichas posiciones, no al revés 
        */
        for (ll i=0;i<N;i++) parent.pb(i);
        //En el inicio del constructor todos los elementos son conjuntos disjuntos
    }
    ll unique()
    {
        //No se el costo computacional de esto para construir el set, pero
        //se supodrá que no es alto
        return set<ll>(this->parent.begin(),this->parent.end()).size();
    }
    ll size()
    {
        return this->N;
    }
    ll findSet(ll a)
    {
        return ((parent[a]==a) ? a: parent[a]=findSet(parent[a]));
        //Implicitamente estamos haciendo path compression para el caso de los disjoint set
    }
    bool isSameSet(ll a, ll b)
    {
        return (findSet(a)==findSet(b)); 
    }
    void UnionSet(ll a, ll b)
    {
        if(!isSameSet(a,b))
        {
            //Asignamos el padre que tenga mayor rango, si hay empate lo desempatamos al final
            ll p1=findSet(a);
            ll p2=findSet(b);
            if(rank[p2]<rank[p1])
            {
                parent[p2]=p1;
            }
            else
            {
                parent[p1]=p2;
                if (rank[p1]==rank[p2]) rank[p1]++; 
                /* Desempate de rangos, como asignamos como padre a p1 sobre p2 su rango 
                debe de ser por tanto mayor al de p2*/
            }
        }
    }
    void reset()
    {
        //Esto nos sirve al cambiar de bloque y no declarar nuevos vectores
        //Nada más con el puro reset
        rank.assign(N,0);
        for(ll i=0;i<N;i++)
        {
            parent[i]=i;
        }
    }
};


void proccessBatches(vector<query> querys, vector<edge> aristas,ll N)
{
    /*Procesamos los bloques de preguntas y para cada una de ellas usamos un 
    UFDS para hacer las actualizaciones, cada que cambiamos de bloque hacemos un reset del UFDS*/
    cont=0; //Esto para contestar preguntas
    UFDS ufds(N); //Un UDFS de todos los elementos como disjuntos
    for (ll j=0;j<sqrt(aristas.size());j++)
    {
        ufds.reset();
        
    }
}

int main()
{
    vector<query> querys;
    vector<edge> edges;
    ll N,M,Q;
    cin>>N>>M>>Q;
    for(ll j=0;j<M;j++)
    {
        ll s,e;
        cin>>s>>e;
        edges.pb(edge(s,e));
    }
    for(ll k=0;k<Q;k++)
    {
        ll l,r;
        cin>>l>>r;
        querys.pb(query(l,r,M,k));
    }
    sort(querys.begin(),querys.end());
    //Las aristas y las consultas se dividieron en los bloques correctos 
    /*
    for(vector<query>::iterator it=querys.begin();it!=querys.end();++it) cout<<(*it).l<<" "<<(*it).r<<" "<<(*it).block<<" "<<(*it).idx<<endl;
    // Prueba para que las consultas si se estén ordenando correctamente
    */

    /*
    //Pruebas de las clases UFDS y query
    ll N=4;
    consultas.pb(query(0,1,N,0));
    consultas.pb(query(0,0,N,1));
    consultas.pb(query(0,2,N,2));
    consultas.pb(query(2,3,N,3));
    consultas.pb(query(1,3,N,4));
    sort(consultas.begin(),consultas.end());
    for(vector<query>::iterator it=consultas.begin();it!=consultas.end();++it) cout<<(*it).l<<" "<<(*it).r<<" "<<(*it).block<<endl;
    UFDS union_find(10);
    cout<<"Elementos unicos "<<union_find.unique()<<endl;
    union_find.UnionSet(0,1);
    union_find.UnionSet(3,1);
    union_find.UnionSet(4,5);
    cout<<"Elementos unicos despues de union "<<union_find.unique()<<endl;
    union_find.reset();
    cout<<"Elementos unicos despues de reset "<<union_find.unique()<<endl;*/ 
    return 0;
}