#include"HashUpdatableHeap.h"
#include<ctime>
using namespace std;

int main()
{
  srand(time(0));
	UpdatableHeap<int,int> database;
	int testcases;
	cin>>testcases;
	for (int i=0;i<testcases;i++)
	{
    string OP;
	  int value,data;
    int op=rand()%4;
    cout<<"Opcion: "<<op<<endl;
    if(op==0) OP=string("P");
    if(op==1) OP=string("IU");
    if(op==2) OP=string("DL");
    if(op==3) OP=string("D");

		if(OP==string("P"))
		{
			if (database.empty()) cout<<-1<<endl;
			else
			{
				cout<<database.top().second<<" "<<database.top().first<<endl;
			}
		}
		if (OP==string("IU"))
		{
			value=rand()%101;
      data=rand()%21;
			database.IoU(value,data);
		}
		if (OP==string("DL"))
		{
			database.pop();
		}
		if (OP==string("D"))
		{
			data=rand()%21;
			database.delByKey(data);
		}
	}
	return 0;
}
