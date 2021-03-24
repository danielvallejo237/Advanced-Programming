#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pb push_back
#define MAXQ 50005 //Todos los datos estan acotados por el valor de 50000
#define mp make_pair

struct edge
{
    //Creacion de la estructura arista que tiene el vertice de salida y el vertice de meta
    ll u,v;
    edge(ll u, ll v)
    {
        this->u=u;
        this->v=v;
    }
    edge(){}
    ~edge(){}
    //En caso de aplicar constructor vacio poder crear la arista despues
    void crear(ll u, ll v)
    {
        //En caso de inicializar una cosa vacia
        this->u=u;
        this->v=v;
    }
};
struct query
{
    ll l,r,block,idx;
    query(ll l, ll r, ll idx, ll N)
    {
        this->l=l;
        this->r=r;
        this->idx=idx;
        this->block=(ll)l/(ll)sqrt(N);
    }
    query(){} //Constructores que no hacen nada
    ~query(){}
    bool operator < (const query& cons)
    {
        //Ordenamos por bloque primero y despues ordenamos por el valor de
        //r
        if(block==cons.block) return r<cons.r;
        return block<cons.block;
    }
};

typedef pair<ll,pair<ll,ll> > iedg; //Arista indexada en esta guardaremos el padre del conjunto asi
//como su rango

vector<query> querys(MAXQ);
vector<edge> edges(MAXQ);
vector<ll> parent(MAXQ);
vector<ll> rango(MAXQ);
vector<iedg> aux(MAXQ);

vector<ll> solutions(MAXQ); //Aqui se guardan la soluciones finales al problema


namespace UFDS{

ll findSet(ll a, bool flag)
{
    if (parent[a]==a) return a;
    if (flag) aux.pb(mp(a,mp(parent[a],rango[a])));
    return parent[a]=findSet(parent[a],flag);
}

/*Al union set solo le hacemos una peuena modificacion ahora con un bool, y en el aux metemos las
 conjuntos, el padre al que pertenece y el rango de dicho elemento, esto con el fin de deshacer operaciones*/

bool UnionSet(ll a, ll b,bool flag)
{
    a=findSet(a,flag);
    b=findSet(b,flag);
    if(a==b) return false;
    if(rango[a]>rango[b])
    {
        if (flag) aux.pb(mp(b,mp(parent[b],rango[b])));
        parent[b]=a;
    }
    else if (rango[a]<rango[b])
    {
        if (flag) aux.pb(mp(a,mp(parent[a],rango[a])));
        parent[a]=b;
    }
    else
    {
        if(flag)
        {
            aux.pb(mp(b,mp(parent[b],rango[b])));
            aux.pb(mp(a,mp(parent[a],rango[a])));
        }
        parent[b]=a;
        rango[a]++;
    }
    return true;

}
}

void reset( ll N,vector<ll> ufds)
{
    for(ll i=1;i<=N;i++) ufds[i]=i;
}

int main()
{
    ll N,M,Q;
    cin>>N>>M>>Q;
    //Checamos que se respeten las constantes
    assert(N>0 && N<=50000 && M>0 && M<=50000 && Q>0 && Q<=50000);
    rango.assign(N+1,0);
    reset(N,parent);
    for(ll j=1;j<=M;j++)
    {
        ll s,e;
        cin>>s>>e;
        s++;
        e++;
        edges[j]=edge(s,e);
    }
    //cout<<"edges added"<<endl;
    //cout<<edges[0].u<<" "<<edges[0].v<<endl;
    for(ll k=0;k<Q;k++)
    {
        ll l,r;
        cin>>l>>r;
        l++;
        r++;
        querys[k]=query(l,r,k,N);
    }
    sort(querys.begin(),querys.begin()+Q);
    /*
        ## NOTA MENTAL ##
        En el assing se asigna primero cuantos y despues el valor que se asignara en
        dichas posiciones, no al reves
    */
    ll raiz=sqrt(N);
    //cout<<raiz<<endl;
    ll ans = N, lans = N;
    ll lbk = -1, cl = 1, cr = 0;
    /*Left block es el bloque de la izquierda, los cl y cr son los contadores hacia la derecha y hacia la izquierda*/
    for(int i=0;i<Q;i++)
    {
        ll left=querys[i].l;
        ll right=querys[i].r;
        ll bloque=querys[i].block;
        ll indice=querys[i].idx;
        if(bloque !=lbk)
        {
            cl = (bloque+1)*raiz;
            cr = cl-1;
            lans = N;
            ans = N;
            for (int i = 1; i <= N; i++) parent[i] = i, rango[i] = i;
            lbk = bloque;
        }
        if (right/raiz == bloque)
        {
            cl = left, cr = left-1;
            while (cr < right)
            {
    		    ++cr;
    			if (UFDS::UnionSet(edges[cr].u, edges[cr].v, 1)) ans--;
    		}
    		solutions[indice] = ans;
    		cl = (bloque+1)*raiz;
    		cr = cl-1;
        }
        else
        {
            while (cr < right)
            {
                ++cr;
                if (UFDS::UnionSet(edges[cr].u, edges[cr].v, 0)) ans--;
    		        }
            lans = ans;
            while (cl > left)
            {
                --cl;
                if (UFDS::UnionSet(edges[cl].u, edges[cl].v, 1)) ans--;
            }
            solutions[indice] = ans;
            cl = (bloque+1)*raiz;
    	}
        for (int i = aux.size()-1; i >= 0; i--)
        {
		    ll at = aux[i].first;
            ll p = aux[i].second.first;
            ll wi = aux[i].second.second;
            parent[at] = p;
            rango[at] = wi;
        }
		aux.clear();
		ans = lans;
    }
    for(int i=0;i<Q;i++)
    {
        cout<<solutions[i]<<endl;
    }
    return 0;
}
