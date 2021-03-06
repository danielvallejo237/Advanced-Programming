// Creacíon de la clase Heap para después actualizarlo

#include <bits/stdc++.h>
#include <vector>

using namespace std;

template<class Tpr>

class Heap
{
	private:
	vector<Tpr> heapvec;
	typename vector<Tpr>::iterator it;
	void MaxHeapify(int k)
	{
		if (k >=0 && k<=heapvec.size())
		{
			//k representa la posición del elemento
			while(k>0 && heapvec.at((int)k/2) < heapvec.at(k))
			{
				swap(heapvec.at(k),heapvec.at((int)k/2));
				k=(int)k/2;
			}
		}
	}
	public:
	Tpr top()
	{
		return heapvec.at(0);
	}
	void print()
	{
		for(it=heapvec.begin();it!=heapvec.end();++it) cout<<*it<<" ";
		cout<<endl;
	}
	void insert(Tpr item)
	{
		heapvec.push_back(item);
		MaxHeapify(heapvec.size()-1);
	}
	void removeTop()
	{
		if (heapvec.size()!=0)
		{
			heapvec.erase(heapvec.begin());
			heapvec.shrink_to_fit();
			MaxHeapify(heapvec.size()-1);
		}
	}
	void removeByIndex(int index)
	{
		if (index < heapvec.size())
		{
			heapvec.erase(heapvec.begin()+index);
			heapvec.shrink_to_fit();
			MaxHeapify(heapvec.size()-1);
		}
	}
};
