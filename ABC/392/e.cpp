#include <bits/stdc++.h>
#include <atcoder/all>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORR(i, a, b) for (ll i = (a); i <= (b); i++)
#define repR(i, n) for (ll i = n - 1; i >= 0; i--)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout << (x) << "\n"
#define PQ(x) priority_queue<x>
#define PQR(x) priority_queue<x, vector<x>, greater<x>>
#define YES(n) cout << ((n) ? "YES\n" : "NO\n")
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n")
#define mp make_pair
#define sz(x) (ll)(x).size()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};
// Union Find

template <typename T>
struct UnionFind
{
  vector<T> par;
  vector<T> rank;
  vector<T> sizes;
  UnionFind(T n) : par(n), rank(n, 0), sizes(n, 1)
  {
    for (T i = 0; i < n; i++)
    {
      par[i] = i;
    }
  }
  T root(T x)
  {
    return par[x] == x ? x : par[x] = root(par[x]);
  }

  bool unite(T x, T y)
  {
    if (x == y)
      return false;
    x = root(x);
    y = root(y);
    if (x == y)
      return false;
    if (rank[x] < rank[y])
      swap(x, y);
    if (rank[x] == rank[y])
      rank[x]++;
    par[y] = x;
    sizes[x] = sizes[x] + sizes[y];
    return true;
  }
  bool same(T x, T y)
  {
    return root(x) == root(y);
  }
  T size(T x)
  {
    return sizes[root(x)];
  }
};

int main()
{
  ll n, m;
  cin >> n >> m;
  UnionFind<ll> uf(n);
  set<ll> rot;
  vll a(m), b(m);

  map<ll, vector<pair<ll, ll>>> path;
  rep(i, m)
  {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;

    if (uf.same(a[i], b[i]))
    {
      path[uf.root(a[i])].pb(pll(i, b[i]));
    }
    else
      uf.unite(a[i], b[i]);
  }
  map<ll, vector<pair<ll, ll>>> tmp;
  for (auto p : path)
  {
    ll root = uf.root(p.F);
    for (auto pp : p.S)
    {
      tmp[root].pb(pp);
    }
  }
  path = tmp;

  vector<tuple<ll, ll, ll>> ans(0);

  rep(i, n)
  {
    rot.insert(uf.root(i));
  }
  for (auto p : path)
  {
    ll pf = uf.root(p.F);
    ll p_iter = 0;
    if (rot.size() == 1)
    {
      break;
    }
    for (auto it = rot.begin(); it != rot.end();)
    {
      if (p_iter == p.S.size())
        break;
      if (pf == *it)
      {
        it++;
        continue;
      }
      if (pf != uf.root(*it))
      {
        ans.pb({p.S[p_iter].F + 1, p.S[p_iter].S + 1, *it + 1});
        uf.unite(pf, uf.root(*it));
      }
      p_iter++;
      it = rot.erase(it);
    }
  }
  cout << ans.size() << endl;
  rep(i, ans.size())
  {
    auto [a, b, c] = ans[i];
    cout << a << " " << b << " " << c << endl;
  }
}
