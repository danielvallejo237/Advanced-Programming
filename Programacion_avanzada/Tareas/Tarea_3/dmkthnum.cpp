#include <bits/stdc++.h>

using namespace std;

#define maximo 50005

vector<pair<int,int>> arrp(maximo);
int arr[maximo];
vector<int> arbol[4*maximo];


void build(int n, int begin, int end)
{
  if(begin==end)
  {
    //if(arbol[n].size()>=1) arbol[n].pop_back();
    arbol[n].push_back(arrp[begin].second);
    return;
  }
  int l=2*n;
  int r=l+1;
  int mid=(begin+end)/2;
  build(l,begin,mid);
  build(r,mid+1,end);
  merge(arbol[l].begin(),arbol[l].end(),arbol[r].begin(),arbol[r].end(),back_inserter(arbol[n]));
  /*back_inserter inserta al final del arreglo el valor que se encuentra en
  el arreglo de arbol de n*/
}

int consulta(int n, int begin, int end, int i, int j, int k)
{
  for(vector<int>::iterator it=arbol[n].begin();it!=arbol[n].end();++it) cout<<*it<<" ";
  cout<<endl;
  if(begin==end) return arbol[n].back();
  int l=2*n;
  int r=l+1;
  int mid=(begin+end)/2;
  int x=upper_bound(arbol[l].begin(),arbol[l].end(),j)-lower_bound(arbol[l].begin(),arbol[l].end(),i);
  if(x>=k)
  {
    return consulta(l,begin,mid,i,j,k);
  }
  else
  {
    return consulta(r,mid+1,end,i,j,k-x);
  }
}

//en el caso de los update
void update(int value, int k, int n)
{
  //Esto no es muy eficiente ya que estamos realmente construyendo de nuevo el arreglo
  //for(int i=1;i<=n;i++) cout<<arrp[i].first<<" "<<arrp[i].second<<endl;
  arr[k]=value;
  //for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
  for(int i=1;i<=n;i++)
    {
        arrp[i].first=arr[i];
        arrp[i].second=i;
    }
  //sort(arrp.begin()+1,arrp.begin()+n+1);
  for(int i=1;i<=n;i++) cout<<"Imprimiendo parejas "<<arrp[i].first<<" "<<arrp[i].second<<endl;
  cout<<endl;
  for(int i=1;i<=4*n;i++) arbol[n].clear();
  cout<<"Entering build"<<endl;
  //build(1,1,n);
  for(vector<int>::iterator it=arbol[1].begin();it!=arbol[1].end();++it) cout<<*it<<" ";
}
int main()
{
  int n, m;
  cin>>n;
  for(int i=1;i<=n;i++)
    {
        cin>>arrp[i].first;
        arrp[i].second=i;
        arr[i]=arrp[i].first;
    }

    sort(arrp.begin()+1,arrp.begin()+n+1);
    //for(int i=1;i<=5;i++) cout<<arrp[i].first<<" "<<arrp[i].second<<") (";
    //cout<<endl;
    build(1,1,n);
    cin>>m;
    while(m--)
    {
      int peticion;
      cin>>peticion;
      if(peticion==0)
      {
        int a,b,c;
        cin>>a>>b>>c;
        a++; //El algoritmo está diseñado para comenzar en el número 1
        b++;
        c++;
        int ans=consulta(1,1,n,a,b,c);
        ans=arr[ans];
        cout<<ans<<endl;
      }
      if(peticion==1)
      {
        int valor, pos;
        cin>>pos>>valor;
        arr[pos+1]=valor;
        //for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
        for(int i=1;i<=n;i++)
        {
          arrp[i].first=arr[i];
          arrp[i].second=i;
        }
        sort(arrp.begin()+1,arrp.begin()+n+1);
        //for(vector<pair<int, int> >::iterator it=arrp.begin();it!=arrp.end();++it) cout<<" "<<(*it).first<<" "<<(*it).second;
        //cout<<endl;
        //vector<int> arbol[4*maximo];
        //for(vector<int>::iterator it=arbol[1].begin();it!=arbol[1].end();++it) cout<<*it<<" ";
        //cout<<endl;
        build(1,1,n);
      }
    }
    return 0;
}
