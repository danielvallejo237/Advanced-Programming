#include <bits/stdc++.h>
#include <stack>
using namespace std;

class StackMin
{
	private:
	stack<pair<int,int>> st;
	public:
	StackMin()
	{
		st.push(make_pair(INT_MAX,INT_MAX));
	}
	void push(int v)
	{
		st.push(make_pair(v,min(v,st.top().second)));
		//Accedemos al segundo elemento de la pareja
	}
	int minElement()
	{
		// Ahí guardamos el mínimo
		return st.top().second;
	}
	void pop()
	{
		st.pop();
	}
	int size()
	{
		return st.size()-1;
	}
	bool empty()
	{
		//Función problemática arreglada
		return size()==0;
	}
	int top()
	{
		return st.top().first;
	}
		
};

class QueueMin
{
	// Implementación de una cola con dos pilas
	private:
	StackMin sIn, sOut; // Pila de entrada y pila de salida
	void transfer()
	{
		if (sOut.empty())
		{
			while(!sIn.empty())
			{
				sOut.push(sIn.top());
				sIn.pop();
			}
		}
	}
	public:
	int MinElement()
	{
		return min(sIn.minElement(),sOut.minElement());
	}
	
	int front()
	{
		transfer();
		return sOut.top();
	}
	int size()
	{
		return sIn.size()+sOut.size();
	}
	bool empty()
	{
		return size()==0;
	}
	void push(int v)
	{
		sIn.push(v);
	}
	void pop()
	{
		transfer();
		sOut.pop();
	}	
};
