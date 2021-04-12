#include <bits/stdc++.h>

using namespace std;

struct query
{
    int l,r,idx, block; //idx es para recuperar el orden de las preguntas
    query(){}
    query(int idx,int l, int r, int block)
    {
        this->idx=idx;
        this->l=l;
        this->r=r;
        this->block=block;
    }
    bool operator < (const query &consulta) const
    {
        if(block<consulta.block) return true;
        else if(block==consulta.block)
        {
            return r<consulta.r;
        } 
        else return false;
    }
};

int main()
{
    int elements,querys;
    cin>>elements>>querys;
    vector<int> art(elements);
    vector<int> sumas(ceil(sqrt(elements)),0);
    vector<query> consultas(querys);
    for(int i=0;i<elements;i++) cin>>art[i];
    for(int j=0;j<elements;j++) sumas[j/sqrt(elements)]+=art[j];
    for(int i=0;i<querys;i++)
    {
        int left,right;
        cin>>left>>right;
        left=max(left,0);
        right=min(right,elements-1);
        consultas[i]=query(i,left,right,left/sqrt(elements));
    }
    sort(consultas.begin(),consultas.end());



    return 0;
}