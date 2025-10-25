#include <bits/stdc++.h>
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
constexpr void printArray(const vector<T> &vec, char split = ' ')
{
  rep(i, vec.size())
  {
    cout << vec[i];
    cout << (i == (int)vec.size() - 1 ? '\n' : split);
  }
}
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
template <typename T>
struct SegmentTree
{
  typedef function<T(T, T)> F;
  int n; // 要素数
  F f;   // 2項演算
  T e;   // 単位元
  vector<T> dat;
  SegmentTree(int n_, F f, T e) : f(f), e(e)
  {
    init(n_);
    build();
  }
  SegmentTree(int n_, F f, T e, vector<T> &v) : f(f), e(e)
  {
    init(n_);
    build(n_, v);
  }
  void init(int n_)
  {
    n = 1;
    while (n < n_)
      n <<= 1;
    dat.clear();
    dat.resize(n << 1, e);
  }
  void build(int n_, const vector<T> &v)
  {
    for (int i = 0; i < n_; ++i)
      dat[n + i] = v[i];
    build();
  }
  void build()
  {
    for (int i = n - 1; i >= 1; --i)
    {
      dat[i] = f(dat[i << 1], dat[i << 1 | 1]);
    }
  }
  void update(int k, const T &x)
  {
    dat[k += n] = x;
    while (k >>= 1)
    {
      dat[k] = f(dat[k << 1], dat[k << 1 | 1]);
    }
  }
  T query(int a, int b)
  {
    T l = e, r = e;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1)
    {
      if (a & 1)
        l = f(l, dat[a++]);
      if (b & 1)
        r = f(dat[--b], r);
    }
    return f(l, r);
  }
};
int main()
{
  ll n;
  cin >> n;
  vvll t(n, vll(0));
  vector<pll> path(n - 1);
  rep(i, n - 1)
  {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    t[u].pb(v);
    t[v].pb(u);
    path[i] = pll(u, v);
  }
  // iをre_t[i]に変換しました
  vll re_t(n, -1);
  vector<pll> range(n);
  auto dfs = [&](auto dfs, int i, int from, pll num) -> pll
  {
    if (t[i].size() == 1 && i != 0)
    {
      re_t[i] = num.S;
      range[i] = pll(num.S, num.S + 1);
      return range[i];
    }
    pll cnt = num;
    ll mi = INF;
    for (auto p : t[i])
    {
      if (p != from)
      {
        cnt = dfs(dfs, p, i, cnt);
        chmin(mi, cnt.F);
      }
    }
    re_t[i] = cnt.S;
    range[i] = pll(mi, cnt.S + 1);
    return range[i];
  };
  dfs(dfs, 0, -1, {0, 0});

  vll ini(n, 1);
  SegmentTree<ll> seg(n, [](ll a, ll b)
                      { return a + b; }, 0, ini);
  ll q;
  cin >> q;
  ll sum = n;
  rep(i, q)
  {
    ll query;
    cin >> query;
    if (query == 1)
    {
      ll x, w;
      cin >> x >> w;
      x--;
      ll p = range[x].S - 1;
      ll now = seg.query(p, p + 1);
      seg.update(p, now + w);
      sum += w;
    }
    else
    {
      ll y;
      cin >> y;
      y--;
      pll p = path[y];
      ll par;
      if (range[p.F].S < range[p.S].S)
        par = p.F;
      else
        par = p.S;
      ll res = seg.query(range[par].F, range[par].S);
      cout << abs(sum - 2 * res) << endl;
    }
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
