#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb(a) push_back(a)

struct edge
{
    //Creación de la estructura arista que tiene el vértice de salida y el vértice de meta
    ll u,v;
    edge(ll u, ll v)
    {
        this->u=u;
        this->v=v;
    }
    edge(){}
    ~edge(){}
    //En caso de aplicar constructor vacío poder crear la arista despues
    void crear(ll u, ll v)
    {
        //En caso de inicializar una cosa vacía
        this->u=u;
        this->v=v;
    }
};
struct query
{
    //Consulta, tiene el left, right y el bloque al que pertenece dicha consulta
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
        if(block<consulta.block) return true;
        else if(block==consulta.block)
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
            //cout<<"Making union"<<endl;
            //Asignamos el padre que tenga mayor rango, si hay empate lo desempatamos al final
            ll A=findSet(a);
            ll B=findSet(b);
            if(rank[A]<rank[B]) swap(A,B);
            parent[B]=A;
            if (rank[A]==rank[B]) rank[A]++; 
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
    void detatch(ll index, ll index2)
    {
        /*La función detatch lo que hace es desconectar 
        las uniones del conjunto, después del detatch debemos de hacer union
        en la arista faltante*/ 
        if(index>=0 && index <size())
        {
            parent[index]=index; //Los desconectamos haciendo que el padre de cada uno de los elementos de las aristas sean ellos mismos
            parent[index2]=index2;
        }
    }
};


void proccessBatches(vector<query> querys, vector<edge> aristas,ll N,ll M)
{
    /*Procesamos los bloques de preguntas y para cada una de ellas usamos un 
    UFDS para hacer las actualizaciones, cada que cambiamos de bloque hacemos un reset del UFDS*/
    ll cont=0; //Esto para contestar preguntas
    UFDS ufds(N); //Un UDFS de todos los elementos como disjuntos
    //Las soluciones son del tamaño de las preguntas
    vector<ll> solutions(querys.size());
    for (ll j=0;j<sqrt(aristas.size());j++)
    {
        //En el caso de procesar los "Batch", hay que hacer reset de la estructura UFDS
        /*Procesar cada uno de los "Batch" que contienen preguntas correspondientes 
        a las aristas y a los rangos l,r*/
        ufds.reset();
        /*TO DO: Optimizar esta parte del código con el agoritmo de MO de calcular 
        respuestas anteriores */
        ll right=querys[cont].r;
        ll left=querys[cont].l;
        ll comp_conexa=ufds.size();
        //cout<<"Entering batch "<<j<<endl;
        while(querys[cont].block==j)
        {
             //En este right controlamos hasta donde se actualizó el UFDS para evitar dobles actualizaciones
            if((int)(querys[cont].l)/(int)sqrt(M)==(int)(querys[cont].r)/(int)sqrt(M))
            {
                //Lo anterior significa que las preguntas están en el mismo bloque
                if(left>querys[cont].l)
                {
                    //Encontrar una forma de deshacer operaciones de union en el ufds
                    for(ll i=querys[cont].l;i<=left;i++)
                    {
                        ufds.detatch(aristas[i].u,aristas[i].v);
                    }
                    left=querys[cont].l;
                }
                if(left==querys[cont].l)
                {
                    left=querys[cont].l;
                    right=querys[cont].r;
                } //Do nothing function
                if(left<querys[cont].l)
                {
                    set<ll> detatched;
                    for(ll i=left;i<=querys[cont].l;i++)
                    {
                        ufds.detatch(aristas[i].u,aristas[i].v);
                    }
                    left=querys[cont].l;
                }
                for(ll k=querys[cont].l;k<=querys[cont].r;k++)
                {
                    right=querys[cont].r;
                    ufds.UnionSet(aristas[k].u,aristas[k].v);
                }
                solutions[querys[cont].idx]=ufds.unique();
            }
            else
            {
                if(left>querys[cont].l)
                {
                    //Encontrar una forma de deshacer operaciones de union en el ufds
                    for(ll i=querys[cont].l;i<=left;i++)
                    {
                        ufds.detatch(aristas[i].u,aristas[i].v);
                    }
                    left=querys[cont].l;
                }
                if(left==querys[cont].l)
                {
                    left=querys[cont].l;
                    right=querys[cont].r;
                } //Do nothing function
                if(left<querys[cont].l)
                {
                    set<ll> detatched;
                    for(ll i=left;i<=querys[cont].l;i++)
                    {
                        ufds.detatch(aristas[i].u,aristas[i].v);
                    }
                    left=querys[cont].l;
                }
                for(ll k=querys[cont].l;k<=querys[cont].r;k++)
                {
                    right=querys[cont].r;
                    ufds.UnionSet(aristas[k].u,aristas[k].v);
                }
                solutions[querys[cont].idx]=ufds.unique();
            }
            cont++;
        }
    }
    for(ll i=0;i<solutions.size();i++) cout<<solutions[i]<<endl;
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
    //for(vector<query>::iterator it=querys.begin();it!=querys.end();++it) cout<<(*it).block<<" "<<(*it).l<<(*it).r<<endl;
    proccessBatches(querys,edges,N,M);
    return 0;
}