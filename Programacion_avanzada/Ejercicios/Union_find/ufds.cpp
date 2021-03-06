
//Creación de la classe union find disjoint sets para encontrar si
// dos elementos se encuentran en un mismo conjunto y unir conjuntos disjuntos

#include <bits/stdc++.h>

using namespace std;

class Union_find
{
private:
  vector<int> p,rank;
  int N;
  /*p es el vector del padre inmediato y rank es el vector que contiene los rangos de cada uno
   de los elementos */
public:
  Union_find(int n)
  {
    this->N=n;
    p.assign(N,0);
    rank.assign(N,0);
    for (int i=0;i<N;i++)
    {
      p[i]=i; //El padre inmediato de cada uno de los elementos son ellos mismos al inicio
    }
    cout<<"Class Union_find initialized"<<endl;
  }
  int size()
  {
    return N;
  }
  int findSet(int i)
  {
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
  }
  bool isSameset(int i, int j)
  {
    return findSet(i)==findSet(j);
  }
  void unionSet(int i, int j)
  {
    if(!isSameset(i,j))
    {
      int rep1=findSet(i);
      int rep2=findSet(j);
      //cout<<rep1<<" "<<rep2;
      if(rank[rep1]>rank[rep2])
      {
        p[rep2]=rep1;
      }
    //Aqui hacemos una diferencia para la union
      //esta diferencia es completamente arbitraria
      else
      {
        p[rep1]=rep2;
        if (rank[rep1]==rank[rep2]) rank[rep1]++;
      }
    }
  }
  void printbyRep(int i)
  {
    cout<<"Printing set"<<endl;
    for(int s=0;s<N;s++)
    {
      if(p[s]==i) cout<<s<<" ";
    }
    cout<<endl;
  }
};

template<class item> class Customized_Union_find
{
  private:
  vector<int> rank;
  vector<pair<item,int>> p;
  map<item,int> pos;
  int N;
  public:
  Customized_Union_find(vector<item> V)
  {
    this->N=V.size();
    rank.assign(N,0); //Damos la suficiente memoria para los dos vectores;
    p.resize(N);
    for(int i=0;i<N;i++)
    {
      p[i].first=V[i];
      p[i].second=i;
      pos[V[i]]=i;
    }
    cout<<"Custom class initialized"<<endl;
  }
  int findSet(int i)
  {
    return (p[i].second == i) ? i : (p[i].second = findSet(p[i].second));
  }
  int findSetbyKey(item a)
  {
    return findSet(pos[a]);
  }
  bool isSameset(int i, int j)
  {
    return findSet(i)==findSet(j);
  }
  void unionSet(int i, int j)
  {
    if(!isSameset(i,j))
    {
      int rep1=findSet(i);
      int rep2=findSet(j);
      //cout<<rep1<<" "<<rep2;
      if(rank[rep1]>rank[rep2])
      {
        p[rep2].second=rep1;
      }
    //Aqui hacemos una diferencia para la union
      //esta diferencia es completamente arbitraria
      else
      {
        p[rep1].second=rep2;
        if (rank[rep1]==rank[rep2]) rank[rep1]++;
      }
    }
  }
  void unionbyKey(item a, item b)
  {
    unionSet(pos[a],pos[b]);
  }
  void printSet(int i)
  {
    cout<<"Printing set"<<endl;
    for(int s=0;s<N;s++)
    {
      if(p[s].second==i) cout<<p[s].first<<" ";
    }
    cout<<endl;
  }

};


int main() {
  Union_find conj(10);
  conj.unionSet(0,1);
  conj.unionSet(8,1);
  conj.unionSet(5,8);
  conj.printbyRep(1);
  cout<<conj.isSameset(5,8)<<endl;
  cout<<conj.isSameset(4,1)<<endl;
  vector<char> caracteres;
  caracteres.push_back('A');
  caracteres.push_back('b');
  caracteres.push_back('h');
  caracteres.push_back('&');
  caracteres.push_back('#');
  caracteres.push_back('!');
  caracteres.push_back('+');
  Customized_Union_find<char> conjcar(caracteres);
  conjcar.unionbyKey('A','b');
  conjcar.unionbyKey('#','b');
  conjcar.printSet(1);
  return 0;
}
