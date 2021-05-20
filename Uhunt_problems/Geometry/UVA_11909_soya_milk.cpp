#include <bits/stdc++.h>

using namespace std;

int main()
{
int l,w,h, theta;
cout<<fixed;
cout<<setprecision(3);
    while(cin>>l>>w>>h>>theta)
    {
        double d=theta/360.0 * 2* acos(-1);
        if(l*tan(d)<=h)
        {
            cout<<l*w*h-w*0.5*l*l*tan(d)<<" mL\n";
        }
        else
        {
            cout<<w*0.5*h*h*1/tan(d)<<" mL\n";
        }
    }
return 0;
}