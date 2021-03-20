#include "HashUpdatableHeap.h"
#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
	cout<<"[info] updatableHeap Initialized..."<<endl;
	UpdatableHeap<float,char> uhp;
	cout<<"[info] Inserting elements... "<<endl;
	uhp.IoU(2.3,'a');
	uhp.IoU(4.5,'&');
	uhp.IoU(4.5,'$');
	uhp.IoU(56.7,'?');
	uhp.IoU(0.2,'(');
	uhp.IoU(2.01,'=');
	uhp.delByKey('&');
	uhp.IoU(100.45,'=');
	uhp.print();
	uhp.pop();
	uhp.print();
	return 0;
}
