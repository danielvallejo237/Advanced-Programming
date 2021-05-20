#include<bits/stdc++.h>

using namespace std;

int min(int x, int y, int z)
{
    return min(x,min(y,z));
}

int LevDist(string s1, string s2, int m, int n)
{
    if(m==0) return n;
    if(n==0) return m;
    //Quiere decir que pongamos todos los
    if(s1[m-1]==s2[n-1])
    {
        return LevDist(s1,s2,m-1,n-1);
    }
    //Insertar, remover y reemplazar son los tres movimientos posibles
    return 1+ min(LevDist(s1,s2,m,n-1),LevDist(s1,s2,m-1,n),LevDist(s1,s2,m-1,n-1)); 
}

int main()
{
    string line;
	getline(cin, line);
  string s1,s2;
  int testcases=atoi(line.c_str());;
  while(testcases--)
  {
      getline(cin,s1);
      getline(cin,s2);
      cout<<LevDist(s1,s2,s1.size(),s2.size())<<endl;
  }
  return 0;
}