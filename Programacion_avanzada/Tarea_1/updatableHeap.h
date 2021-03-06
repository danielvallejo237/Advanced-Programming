#include <bits/stdc++.h>
#include <vector>
#include <unordered_set>

using namespace std;

template<class Tpr,class Tkey> class UHeap
{
    private:
    vector<pair<Tpr,typename unordered_set<Tkey>::iterator>> mheap;
    typename vector<Tpr>::iterator it;
    unordered_set<Tkey> keys;
    void MaxHeapify(int k)
    {
        if(k>=0 && k<=mheap.size())
        {
            while(k>0 && mheap.at((int)k/2).first < mheap.at(k).first)
            {
                swap(mheap.at(k),mheap.at((int)k/2));
                k=(int)k/2;
            }

        }
    }
    void sort_top()
    {
        Tpr aux=mheap[0].first;
        int i=1;
        while (mheap[i].first==aux)
        {
            if(*(mheap[i].second)>*(mheap[0].second))
            {
                swap(mheap.at(i),mheap.at(0));
            }
            i++;
        }
    }

    void fixDown(int k, int N)
    {
        while(2*k<=N)
        {
            int j=2*k;
            if(k==N/2)
            {
                int j=2*k;
                if(!(mheap.at(k).first <mheap.at(j).first )) break;
                swap(mheap.at(k),mheap.at(j));
                k=j;
            }
            if (j<N && mheap.at(j).first <mheap.at(j+1).first) j++;
            if(!(mheap.at(k).first <mheap.at(j).first )) break;
            swap(mheap.at(k),mheap.at(j));
            k=j;
        }

    }
    public:
    void insert(Tpr item,Tkey key)
    {
        if (keys.find(key)==keys.end())
        {
            keys.insert(key);
            mheap.push_back(make_pair(item,keys.find(key)));
            MaxHeapify(mheap.size()-1);
        }
        else if (keys.find(key)!=keys.end())
        {
            for(int i=0;i<mheap.size();i++)
            {
                if(*(mheap[i].second)==key) mheap[i].first=item;
                MaxHeapify(i);
                fixDown(i,mheap.size()-1);
            }

        }
    }
    void print()
    {
        for(int i=0;i<mheap.size();i++)
        {
            cout<<" ("<<mheap[i].first<<" "<<*(mheap[i].second)<<") ";
        }
        cout<<endl;
    }
    int size()
    {
        return (mheap.size());
    }
    pair<Tpr,Tkey> top()
    {
        sort_top();
        return (make_pair(mheap[0].first,*(mheap[0].second)));
    }

    void pop()
    {
        //Borra el primer nodo y después haremos Heapify
        if (mheap.size()!=0)
        {
            keys.erase(mheap[0].second);
            mheap.erase(mheap.begin());
            mheap.shrink_to_fit();
            fixDown(0,mheap.size()-1);
        }
    }
    void erase(Tkey key)
    {
        if (keys.find(key)!=keys.end())
        {
            //Condición que nos dice si si encontramos la llave en el conjunto
            for(int i=0;i<mheap.size();i++)
            {
                if(*(mheap[i].second)==key)
                {
                    swap(mheap[i],mheap[mheap.size()-1]);
                    keys.erase(mheap[mheap.size()-1].second);
                    mheap.erase(mheap.end()-1);
                    mheap.shrink_to_fit();
                    MaxHeapify(i);
                    fixDown(i,mheap.size()-1);
                }
            }
        }
    }
    bool isInserted(Tkey key)
    {
        return (keys.find(key)!=keys.end());
    }
    bool empty()
    {
        return (size()==0);
    }

};
