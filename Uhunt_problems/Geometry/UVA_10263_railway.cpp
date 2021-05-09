#include <bits/stdc++.h>

using namespace std;

class point
{
    public:
    float x,y; //Coordenadas del punto
    point(){}
    point(float x, float y)
    {
        this->x=x;
        this->y=y;
    }
    point operator-(const point& p)
    {
        this->x=this->x-p.x;
        this->y=this->y-p.y;
        return *this;
    }
    point operator=(const point &p)
    {
        this->x=p.x;
        this->y=p.y;
        return *this;
    }
    point operator +(const point& p)
    {
        this->x=this->x+p.x;
        this->y=this->y+p.y;
        return *this;
    }
    void print()
    {
        cout<<this->x<<endl<<this->y<<endl;
    }
    float distance(const point&p)
    {
        point aux=*this-p;
        return sqrt(pow(aux.x,2)+pow(aux.y,2));
    }
};

pair<point,point> ArgMinDist(vector<point> pnts, point pnt)
{
    float mindist=100000000000.0;
    pair<point,point> line_segments;
    for(int i=0;i<pnts.size()-1;i++)
    {
        float dist=sqrt(pow((pnt.x-pnts[i].x),2)+pow((pnt.y-pnts[i].y),2))+sqrt(pow((pnt.x-pnts[i+1].x),2)+pow((pnt.y-pnts[i+1].y),2));
        //cout<<dist<<endl;
        if(dist<mindist)
        {
            line_segments.first=pnts[i];
            line_segments.second=pnts[i+1];
            mindist=dist;
        }
    }
    return line_segments;
}

point FindCoords(pair<point,point> linseg, point pt)
{
    point aux=linseg.second-linseg.first;
    point closest;
    float dx=aux.x;
    float dy=aux.y;
    if((dx==0) && (dy==0))
    {
        closest=linseg.first;
        return closest;
    }
    float t =((pt.x -linseg.first.x) *dx+(pt.y-linseg.first.y)*dy)/(dx*dx+dy*dy);
    if(t<0)
    {
        closest=linseg.first;
    }
    else if (t>1)
    {
        closest=linseg.second;
    }
    else 
    {
        closest.x=linseg.first.x+t*dx;
        closest.y=linseg.first.y+t*dy;
    }
    return closest;
}

int main()
{
    cout<<fixed;
    cout<<setprecision(4);
    float c1,c2;
    while(cin>>c1>>c2)
    {
    point pt(c1,c2);
    int n;
    cin>>n;
    if(n>0)
    {
        vector<point> puntos;
        for (int i=0;i<=n;i++)
        {
            cin>>c1>>c2;
            point punto(c1,c2);
            puntos.push_back(punto);
        }
        pair<point,point> cord=ArgMinDist(puntos,pt);
        point railstation=FindCoords(cord,pt);
        railstation.print();
    }
    
    }
    return 0;
}