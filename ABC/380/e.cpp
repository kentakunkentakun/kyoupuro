#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (ll)(b); i++)
#define FORR(i, a, b) for (ll i = (a); i <= (ll)(b); i++)
#define repR(i, n) for (ll i = n - 1; i >= 0LL; i--)
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
  map<ll, ll> rtc;
  map<ll, ll> ctr;
  map<ll, pll> range;
  rep(i, n)
  {
    rtc[i] = i;
    ctr[i] = 1;
    range[i] = pll(i, i);
  }
  rep(i, q)
  {
    ll t;
    cin >> t;
    if (t == 1)
    {
      ll x, c;
      cin >> x >> c;
      x--;
      c--;
      ll root = uf.root(x);
      ctr[rtc[root]] -= uf.size(root);
      ctr[c] += uf.size(root);
      rtc[root] = c;

      ll le = range[root].F;
      if (le > 0)
      {
        ll l = le - 1;
        ll left_root = uf.root(l);
        if (rtc[left_root] == c)
        {
          range[left_root] = pll(range[left_root].F, range[root].S);
          range[root] = pll(range[left_root].F, range[root].S);
          uf.unite(left_root, root);
        }
      }
      root = uf.root(root);
      ll ri = range[root].S;
      if (ri < n - 1)
      {
        ll r = ri + 1;
        ll right_root = uf.root(r);
        if (rtc[right_root] == c)
        {
          range[root] = pll(range[root].F, range[right_root].S);
          range[right_root] = pll(range[root].F, range[right_root].S);
          uf.unite(right_root, root);
        }
      }
    }
    else
    {
      ll c;
      cin >> c;
      c--;
      cout << ctr[c] << endl;
    }
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
