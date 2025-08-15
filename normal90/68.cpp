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
  ll n, q;
  cin >> n >> q;
  UnionFind<ll> uf(n);
  SegmentTree<ll> seg(n + 1, [](long long a, long long b)
                      { return a + b; }, 0LL);
  SegmentTree<ll> seg0(n + 1, [](long long a, long long b)
                       { return a + b; }, 0LL);
  SegmentTree<ll> seg1(n + 1, [](long long a, long long b)
                       { return a + b; }, 0LL);
  vector<string> ans(0);
  rep(i, q)
  {
    ll t, x, y, v;
    cin >> t >> x >> y >> v;
    x--;
    y--;
    if (t == 0)
    {
      uf.unite(x, y);
      seg.update(y, v);
      // cout << "update " << y << " " << v << endl;
      if (y % 2)
      {
        seg1.update(y / 2, 2 * v);
      }
      else
      {
        seg0.update(y / 2, 2 * v);
      }
    }
    else
    {
      if (x == y)
      {
        ans.pb(to_string(v));
        continue;
      }
      if ((y - x) % 2)
      {
        if (!uf.same(x, y))
        {
          // cout << "Ambiguous" << endl;
          ans.pb("Ambiguous");
          continue;
        }
        ll mi = min(x, y);
        ll ma = max(x, y);
        ll tmp_sum = seg.query(mi + 1, ma + 1);
        // cout << "getsum " << y << " " << y + 1 << " " << tmp_sum << endl;
        if (ma - mi == 1)
        {
          // cout << tmp_sum - v << endl;
          ans.pb(to_string(tmp_sum - v));
          continue;
        }
        if (x > y)
        {
          swap(x, y);
        }
        if (x % 2)
        {
          ll tt = seg1.query(x / 2 + 1, y / 2);
          // cout << tmp_sum - tt - v << endl;
          ans.pb(to_string(tmp_sum - tt - v));
          continue;
        }
        else
        {
          ll tt = seg0.query(x / 2 + 1, y / 2 + 1);
          // cout << tmp_sum - tt - v << endl;
          ans.pb(to_string(tmp_sum - tt - v));
          continue;
        }
      }
      else
      {
        if (!uf.same(x, y))
        {
          // cout << "Ambiguous" << endl;
          ans.pb("Ambiguous");
          continue;
        }
        ll mi = min(x, y);
        ll ma = max(x, y);
        ll tmp_sum = seg.query(mi + 1, ma + 1);
        if (ma - mi == 2)
        {
          if (x < y)
          {
            ans.pb(to_string(tmp_sum - (seg.query(mi + 1, mi + 2) - v) * 2 - v));
          }
          else
          {
            ans.pb(to_string(tmp_sum - (seg.query(ma, ma + 1) - v) * 2 - v));
          }
          // cout << tmp_sum - (seg.getsum(x + 1, x + 2) - v) * 2 - v << endl;
          continue;
        }
        if (x < y)
        {
          if (x % 2)
          {
            ll tt = seg0.query((x + 3) / 2, y / 2 + 1);
            // cout << tmp_sum - (seg.getsum(x + 1, x + 2) - v) * 2 - tt - v << endl;
            ans.pb(to_string(tmp_sum - (seg.query(x + 1, x + 2) - v) * 2 - tt - v));
          }
          else
          {
            ll tt = seg1.query((x + 3) / 2, y / 2);
            // cout << tmp_sum - (seg.getsum(x + 1, x + 2) - v) * 2 - tt - v << endl;
            ans.pb(to_string(tmp_sum - (seg.query(x + 1, x + 2) - v) * 2 - tt - v));
          }
        }
        else
        {
          if (y % 2)
          {
            ll tt = seg0.query((y + 2) / 2, x / 2);
            ans.pb(to_string(tmp_sum - (seg.query(x, x + 1) - v) * 2 - tt - v));
          }
          else
          {
            ll tt = seg1.query((y + 2) / 2, x / 2);
            ans.pb(to_string(tmp_sum - (seg.query(x, x + 1) - v) * 2 - tt - v));
          }
        }
      }
    }
  }
  rep(i, ans.size())
  {
    cout << ans[i] << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
