//Solución del problema del Sudoku con programación dinámica

#include <bits/stdc++.h>

using namespace std;

int n,mNum;

vector<vector<int>> rejilla(9,vector<int>(9)); //La rejilla del sudoku

vector<vector<bool>> rowInfo(9,vector<bool> (10));
vector<vector<bool>> colInfo(9,vector<bool> (10));
vector<vector<bool>> squareInfo(9,vector<bool> (10));

inline int ToSquare(int x, int y)
{
    return (y/n)*n+x/n;
}

bool fill(int x, int y)
{
    //La función anterior rellena la rejilla de valores para el sudoku
    if(x==mNum)
    {
        ++y;
        if(y==mNum) return true;
        return fill(0,y);
    }
    if(rejilla[y][x]==0)
    {
        for(int i=1;i<=mNum;i++)
        {
            if(!rowInfo[y][i] && !colInfo[x][i] && !squareInfo[ToSquare(x,y)][i])
            {
                //Intentemos agregar el número
                rejilla[y][x]=i;
                rowInfo[y][i]=colInfo[x][i] = squareInfo[ToSquare(x, y)][i] = true;
                if(fill(x+1,y)) return true;
                rejilla[y][x]=0;
                rowInfo[y][i] = colInfo[x][i] = squareInfo[ToSquare(x,y)][i] = false;
            }
        }
        return false;
    }
    else
    {
        return fill(x+1,y);
    }
}

int main()
{
    string sep="";
    while(cin>>n)
    {
        cout<<sep;
        sep="\n";
        mNum=n*n;
        bool isValid=true; //Que si se puede resolver esa cosa
        for(int i=0;i<mNum;i++)
        {
            for(int j=1;j<=mNum;j++) rowInfo[i][j] = colInfo[i][j] = squareInfo[i][j] = false;
        }
        for (int y = 0; y < mNum; y++)
        {
            for (int x = 0; x < mNum; x++)
            {
                cin >> rejilla[y][x];
                if (rejilla[y][x])
                {
                    int num = rejilla[y][x];
                    isValid &= !(rowInfo[y][num] || colInfo[x][num] || squareInfo[ToSquare(x, y)][num]);
                    isValid &= (rejilla[y][x] <= mNum);
                    
                    rowInfo[y][num] = colInfo[x][num] = squareInfo[ToSquare(x, y)][num] = true;
                }
            }
        }
        if (isValid && fill(0, 0))
        {
            for (int y = 0; y < mNum; ++y)
            {
                cout << rejilla[y][0];
                for (int x = 1; x < mNum; ++x)
                {
                    cout << ' ' << rejilla[y][x];
                }
                cout << '\n';
            }
        }
        else
        {
            cout << "NO SOLUTION\n";
        }
    }
}