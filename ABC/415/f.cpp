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

//////////////////////////////////////////////

// Monoid, 1点更新(書き換え)区間取得
// 要素数, 2項演算, 単位元 (, 初期データ)
// todo:1点取得も関数化する？
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
struct monoid
{
  ll len, right_len, left_len;
  char right, left;
  bool all, empty;
};
monoid op(monoid a, monoid b)
{
  if (a.empty)
  {
    return b;
  }
  else if (b.empty)
  {
    return a;
  }
  monoid res;
  if (a.right == b.left)
  {
    res.len = max(a.len, max(b.len, a.right_len + b.left_len));
    if (a.all)
    {
      res.left = a.left;
      res.left_len = a.len + b.left_len;
    }
    else
    {
      res.left = a.left;
      res.left_len = a.left_len;
    }
    if (b.all)
    {
      res.right = b.right;
      res.right_len = b.len + a.right_len;
    }
    else
    {
      res.right = b.right;
      res.right_len = b.right_len;
    }
    if (a.all && b.all)
    {
      res.all = true;
    }
    else
    {
      res.all = false;
    }
  }
  else
  {
    res.len = max(a.len, b.len);
    res.left = a.left;
    res.left_len = a.left_len;
    res.right = b.right;
    res.right_len = b.right_len;
    res.all = false;
  }
  res.empty = false;
  return res;
}
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};
int main()
{
  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  vector<monoid> ini(n);
  rep(i, n)
  {
    monoid init;
    init.all = true;
    init.empty = false;
    init.left = s[i];
    init.right = s[i];
    init.left_len = 1;
    init.right_len = 1;
    init.len = 1;
    ini[i] = init;
  }
  monoid init;
  init.len = 0;
  init.all = true;
  init.empty = true;
  init.right = '-';
  init.right_len = 0;
  init.left = '-';
  init.left_len = 0;
  SegmentTree<monoid> seg(n, op, init, ini);
  rep(i, q)
  {
    ll t;
    cin >> t;
    if (t == 1)
    {
      ll x;
      char c;
      cin >> x >> c;
      monoid up;
      up.len = 1;
      up.all = true;
      up.empty = false;
      up.right = c;
      up.right_len = 1;
      up.left = c;
      up.left_len = 1;
      x--;
      seg.update(x, up);
    }
    else
    {
      ll l, r;
      cin >> l >> r;
      l--;
      monoid res = seg.query(l, r);
      cout << res.len << endl;
    }
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
