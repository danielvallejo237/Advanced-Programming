#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;
int main()
{
    double n;

    cout << showpoint;
    cout << fixed;
    cout << setprecision(4);

    while(cin >> n && n > 0)
    {
        ll a = ceil(pow(n, 1.0/3.0));

        while(pow(a, 3) > n)
            a--;

        double d = (n - pow(a, 3))/(3*a*a);
        double e = a + d;

        cout << e << endl;
    }
    return 0;
}
