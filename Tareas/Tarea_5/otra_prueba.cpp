#ifdef ssu1
#define _GLIBCXX_DEBUG
#endif
#undef NDEBUG
 
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
 
using namespace std;
 
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define debug(x) { cout << #x << "=" << x << endl; }
 
#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif
 
template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }
 
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
 
const int INF = (int)1E9 + 7;
const ld EPS = 1E-9;
const ld PI = 3.1415926535897932384626433832795;
 
const int NMAX = 350000;
 
struct event{
    int oldi, oldval, oldcnt, time_stamp;
};
 
int c[NMAX], cntc;
event st[NMAX * 20];
int szst, curtime;
 
int seed = 123;
const int step = 1009, mask = (1 << 3) - 1;
inline int mrnd(){
    seed = (seed * step) & mask;
    return seed & 1;
}
 
void init(int n){
    cntc = n;
    forn(i, n)
        c[i] = i;
    szst = 0, curtime = 0;
}
 
int root(int a){
    if(c[a] == a)
        return a;
    
    int val = root(c[a]);
    
    event cur = {a, c[a], cntc, curtime};
    st[szst++] = cur;
    
    c[a] = val;
    return val;
}
 
void restore(int old_time){
    while(szst > 0 && old_time < st[szst - 1].time_stamp){
        c[st[szst - 1].oldi] = st[szst - 1].oldval;
        cntc = st[szst - 1].oldcnt;
        szst--;
    }
    curtime = old_time;
}
 
void merge(int a, int b){
    a = root(a);
    b = root(b);
    
    if(a == b)
        return;
    
    if(mrnd())
        swap(a, b);
    
    event cur = {a, c[a], cntc, curtime};
    st[szst++] = cur;
    
    c[a] = b;
    cntc--;
}
 
struct query{
    int l, r, idx;
};
 
const int B = 700;
int n, m, q;
 
query tmp[NMAX];
vector<query> qs[NMAX];
pt e[NMAX];
int result[NMAX];
 
inline bool cmp(const query& a, const query& b){
    return a.r < b.r;
}
 
void clear_data(){
    forn(i, m + 5){
        qs[i].clear();
    }
}
 
int sumn = 0, summ = 0, sumq = 0;
 
void solve_case(){
    assert(scanf("%d%d%d", &n, &m, &q) == 3);
 
    sumn += n, summ += m, sumq += q;
    assert(sumn <= 200000 && summ <= 200000 && sumq <= 200000);
 
    forn(i, m){
        assert(scanf("%d%d", &e[i].X, &e[i].Y) == 2);
        e[i].X--, e[i].Y--;
    }
    
    forn(i, q){
        assert(scanf("%d%d", &tmp[i].l, &tmp[i].r) == 2);
        tmp[i].l--, tmp[i].r--, tmp[i].idx = i;
    }
    
    sort(tmp, tmp + q, cmp);
    forn(i, q){
        qs[tmp[i].l / B].pb(tmp[i]);
    }
 
    for(int id = 0; id < (m + B - 1) / B; id++){
        vector<query>& v = qs[id];
        
        init(n);
        
        int it = 0, border = (id + 1) * B;
        while(it < sz(v) && v[it].r < border){
            curtime = 1;
            
            fori(i, v[it].l, v[it].r){
                merge(e[i].X, e[i].Y);
            }
            result[v[it].idx] = cntc;
            
            restore(0);
            it++;
        }
        
        int jt = border;
        fore(j, it, sz(v)){
            while(jt <= v[j].r){
                merge(e[jt].X, e[jt].Y);
                jt++;
            }
            
            curtime = 1;
            
            for(int i = border - 1; i >= v[j].l; --i){
                merge(e[i].X, e[i].Y);
            }
            result[v[j].idx] = cntc;
            
            restore(0);
        }
    }
    
    forn(i, q){
        printf("%d\n", result[i]);
    }
    
    clear_data();
}
 
int main() {
    #ifdef ssu1
    assert(freopen("input.txt", "rt", stdin));
//    assert(freopen("output.txt", "wt", stdout));
    #endif
    
    int t;
    assert(scanf("%d", &t) == 1);
    forn(ti, t){
        solve_case();
    }
    
    return 0;
}