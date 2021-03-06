#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


template<class Tpr,class Tkey> class UpdatableHeap
{
	private:
	vector<pair<Tpr,Tkey>> mheap;
	map<Tkey,long long int> positions;
	void fixUp(long long int k)
	{
		while(k>0 && mheap.at((long long int)floor((k-1)/2)) < mheap.at(k))
		{
			positions[mheap.at((long long int)floor((k-1)/2)).second]=k;
			positions[mheap.at(k).second]=(long long int)floor((k-1)/2);
			swap(mheap.at(k),mheap.at((long long int)floor((k-1)/2)));
			k=(long long int)floor((k-1)/2);
		}
	}
	void fixDown(long long int k,long long int N)
	{
		while(2*k+2<=N)
		{
			long long int j=2*k+1;
			if(j<N && mheap.at(j) <mheap.at(j+1)) j++;
			if(!(mheap.at(k)<mheap.at(j))) break;
			positions[mheap.at(k).second]=j;
			positions[mheap.at(j).second]=k;
			swap(mheap.at(k),mheap.at(j));
			k=j;
		}
		if(2*k+1==N)
		{
			long long int j=2*k+1;
			if(mheap.at(k)<mheap.at(j)){
			positions[mheap.at(k).second]=j;
			positions[mheap.at(j).second]=k;
			swap(mheap.at(k),mheap.at(j));}
		}
	}
	void MaxHeapify(long long int k,long long int N)
	{
		fixUp(k);
		fixDown(k,N);
	}
	void insert(Tpr item,Tkey key)
	{
		mheap.push_back(make_pair(item,key));
		positions[key]=mheap.size()-1;
		fixUp(mheap.size()-1);
	}

	long long int getPos(Tkey key)
	{
		if (positions.count(key)>0)
		{
			return(positions.find(key)->second);
		}
		else return -1;
	}

	public:
	void print()
	{
		for(long long int i=0;i<mheap.size();i++)
		{
			cout<<"( "<<mheap[i].first<<" "<<mheap[i].second<<") ";
		}
		cout<<endl;
	}

	void delByKey(Tkey key)
	{

		long long int p=getPos(key);
		if(p!=-1 && p!=mheap.size()-1)
		{
			positions[mheap.at(p).second]=mheap.size()-1;
			positions[mheap.at(mheap.size()-1).second]=p;
			swap(mheap.at(p),mheap.at(mheap.size()-1));
			positions.erase(mheap.at(mheap.size()-1).second);
			mheap.pop_back();
			MaxHeapify(p,mheap.size()-1);
		}
		else if (p!=-1 && p==mheap.size()-1)
		{
			positions.erase(mheap.at(mheap.size()-1).second);
			mheap.pop_back();
		}
	}
	bool isInserted(Tkey key)
	{
		return (getPos(key)==-1);
	}
	void pop()
	{
			if(!empty()) delByKey(mheap.front().second);
	}
	void IoU(Tpr item,Tkey key)
	{
		if(getPos(key)==-1)
		{
			insert(item,key);
		}
		else
		{
			delByKey(key);
			insert(item,key);
		}
	}
	bool empty()
	{
		return(mheap.size()==0);
	}
	long long int size()
	{
		return (mheap.size());
	}
	pair<Tpr,Tkey> top()
	{
		return (mheap.front());
	}
};
