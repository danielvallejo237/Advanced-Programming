#include <bits/stdc++.h>

using namespace std;
#define MAX_NUM 10005
int books[MAX_NUM];

int main()
{
    ios_base::sync_with_stdio(false);
    int N,M; //El numero de libros que hay en la tienda es N y el dinero del peter es M
    while(cin>>N)
    {
        for(int i=0;i<N;i++) cin>>books[i];
        cin>>M; 
        sort(books,books+N);
        int i=0;
        int j=N-1;
        int bi,bj;
        while(i<j)
        {
            if(books[i]+books[j]<M)
            {
                ++i;
            }
            if(books[i]+books[j]==M)
            {
                bi=i;
                bj=j; //Indices de los libros
                ++i;
                --j;
            }
            else
            {
                --j;
            }

        }
        cout << "Peter should buy books whose prices are " << books[bi]<< " and " << books[bj] << ".\n\n";
    }
    return 0;
}