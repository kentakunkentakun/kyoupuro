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

int main()
{
  ll n, q;
  cin >> n >> q;
  UnionFind<ll> uf(n);
  vector<ll> t(q), x(q), y(q), v(q);
  vector<string> ans(q);
  vector<ll> d(n - 1, INF);

  ll cnt_t1 = 0;
  rep(i, q)
  {
    cin >> t[i] >> x[i] >> y[i] >> v[i];
    x[i]--;
    y[i]--;

    if (t[i] == 0)
    {
      uf.unite(x[i], y[i]);
      d[x[i]] = v[i];
    }
    else
    {
      if (!uf.same(x[i], y[i]))
      {
        ans[cnt_t1] = "Ambiguous";
      }
      cnt_t1++;
    }
  }
  vector<ll> dd(n);
  dd[0] = 0;
  rep(i, n - 1)
  {
    if (d[i] != INF)
    {
      dd[i + 1] = d[i] - dd[i];
    }
    else
    {
      dd[i + 1] = 0;
    }
  }

  ll tmp_cnt = 0;
  rep(i, q)
  {
    if (t[i])
    {
      if (ans[tmp_cnt] != "Ambiguous")
      {
        if (x[i] % 2 == y[i] % 2)
        {
          ll sa = v[i] - dd[x[i]];
          ans[tmp_cnt] = to_string(dd[y[i]] + sa);
        }
        else
        {
          ll sa = v[i] - dd[x[i]];
          ans[tmp_cnt] = to_string(dd[y[i]] - sa);
        }
      }
      tmp_cnt++;
    }
  }
  rep(i, cnt_t1)
  {
    cout << ans[i] << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
