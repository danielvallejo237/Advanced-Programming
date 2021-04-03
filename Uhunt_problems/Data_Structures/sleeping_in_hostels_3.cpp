// Problema sleeping in Hostels

#include<bits/stdc++.h>
#include<vector> //Vectores de la STL
#include<string>
using namespace std;

int main()
{
  string str;
  while(cin>>str)
  {
    long long int dis=0,temp=0,pos=0,left=0,right=0;
    for(long long int i=0; i<str.length();i++)
    {
      if (str[i]=='X')
      {
        pos=i;
        break;
      }
      else left ++;
    }
    for (long long int i=str.length()-1;i>=0;i--)
    {
      if (str[i]=='X') break;
      else right++;
    }
    long long int ans=max(left,right)-1;
    for (long long int i=pos;i<str.length();i++)
    {
      if (str[i]=='X')
      {
        dis=max(dis,temp);
        temp=0;
      }
      else temp++;
    }
    dis=max(dis,temp);
    temp=(dis+1)/2;
    temp--;
    if(temp>ans) ans=temp;
    cout<<ans<<endl; //Imprimimos la respuesta del problema
  }

}
