#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> pii;

const int maxn = 200010;

struct query
{
int l, r, bk, id;

bool operator< (const query &rhs)
{
  if (bk == rhs.bk) return r < rhs.r;
  return bk < rhs.bk;
}
};

query qr[maxn];
ii v[maxn];

int pai[maxn];
int w[maxn];
vector<pii> aux;

int res[maxn];

int find(int x, bool flag)
{
if (x == pai[x]) return x;
if (flag) aux.push_back({x, {pai[x], w[x]}});
return pai[x] = find(pai[x], flag);
}

bool join(int x, int y, bool flag)
{
x = find(x, flag), y = find(y, flag);

if (x == y) return false;

if (w[x] > w[y]) {

  if (flag) aux.push_back({y, {pai[y], w[y]}});

  pai[y] = x;

} else if (w[y] > w[x]) {

  if (flag) aux.push_back({x, {pai[x], w[x]}});

  pai[x] = y;

} else {

  if (flag) {

    aux.push_back({x, {pai[x], w[x]}});
    aux.push_back({y, {pai[y], w[y]}});
  }

  pai[y] = x;
  w[x]++;
}
return true;
}

int main()
{
int t=1;

while (t--) {

  int n, m, q;
  cin >> n >> m >> q;

  int sqt = sqrt(n);

  for (int i = 1; i <= n; i++) pai[i] = i, w[i] = 0;
  for (int i = 1; i <= m; i++)
  {
    cin >> v[i].ff >> v[i].ss;
    v[i].ss++;
    v[i].ff++;
  }

  for (int i = 0; i < q; i++) {

    cin >> qr[i].l >> qr[i].r;
    qr[i].r++;
    qr[i].l++;
    qr[i].bk = qr[i].l/sqt;
    qr[i].id = i;
  }

  sort(qr, qr+q);

  int ans = n, lans = n;
  int lbk = -1, cl = 1, cr = 0;

  for (int i = 0; i < q; i++) {

    int l = qr[i].l, r = qr[i].r, bk = qr[i].bk, id = qr[i].id;

    if (bk != lbk) {

      cl = (bk+1)*sqt;
      cr = cl-1;
      lans = n;
      ans = n;
      for (int i = 1; i <= n; i++) pai[i] = i, w[i] = i;
      lbk = bk;
    }

    if (r/sqt == bk) {

      cl = l, cr = l-1;

      while (cr < r) {

        ++cr;
        if (join(v[cr].ff, v[cr].ss, 1)) ans--;
      }
      res[id] = ans;
      cl = (bk+1)*sqt;
      cr = cl-1;

    }
    else {

      while (cr < r) {

        ++cr;
        if (join(v[cr].ff, v[cr].ss, 0)) ans--;
      }
      lans = ans;
      while (cl > l) {

        --cl;
        if (join(v[cl].ff, v[cl].ss, 1)) ans--;
      }

      res[id] = ans;
      cl = (bk+1)*sqt;
    }

    for (int i = aux.size()-1; i >= 0; i--) {

      int at = aux[i].ff;
      int p = aux[i].ss.ff;
      int wi = aux[i].ss.ss;
      pai[at] = p;
      w[at] = wi;
    }
    aux.clear();
    ans = lans;
  }
  for (int i = 0; i < q; i++) cout << res[i] << "\n";
}


return 0;
}
