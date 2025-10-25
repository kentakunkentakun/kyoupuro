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
const ll MOD = 998244353LL;
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
  ll n, m, e;
  cin >> n >> m >> e;
  vector<pll> t(e);
  rep(i, e)
  {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    t[i] = {u, v};
  }
  ll q;
  cin >> q;
  vll x(q);
  set<ll> s;
  rep(i, q)
  {
    cin >> x[i];
    x[i]--;
    s.insert(x[i]);
  }
  map<ll, ll> r;
  rep(i, n)
  {
    r[i] = 1;
  }
  UnionFind<ll> uf(n + m);
  ll cnt = n;
  rep(i, e)
  {
    if (!s.count(i))
    {
      auto [u, v] = t[i];
      if (uf.same(u, v))
        continue;
      ll u_root = uf.root(u);
      ll v_root = uf.root(v);

      if (r.count(u_root) && r.count(v_root))
      {
        ll u_cnt = r[u_root];
        ll v_cnt = r[v_root];
        r.erase(u_root);
        r.erase(v_root);
        uf.unite(u, v);
        ll root = uf.root(u);
        r[root] = u_cnt + v_cnt;
      }
      else if (r.count(u_root))
      {
        ll u_cnt = r[u_root];
        r.erase(u_root);
        cnt -= u_cnt;
        uf.unite(u, v);
      }
      else if (r.count(v_root))
      {
        ll v_cnt = r[v_root];
        r.erase(v_root);
        cnt -= v_cnt;
        uf.unite(u, v);
      }
    }
  }
  vll ans(0);
  for (int i = q - 1; i >= 0; i--)
  {
    ans.pb(n - cnt);

    auto [u, v] = t[x[i]];
    if (uf.same(u, v))
      continue;
    ll u_root = uf.root(u);
    ll v_root = uf.root(v);

    if (r.count(u_root) && r.count(v_root))
    {
      ll u_cnt = r[u_root];
      ll v_cnt = r[v_root];
      r.erase(u_root);
      r.erase(v_root);
      uf.unite(u, v);
      ll root = uf.root(u);
      r[root] = u_cnt + v_cnt;
    }
    else if (r.count(u_root))
    {
      ll u_cnt = r[u_root];
      r.erase(u_root);
      cnt -= u_cnt;
      uf.unite(u, v);
    }
    else if (r.count(v_root))
    {
      ll v_cnt = r[v_root];
      r.erase(v_root);
      cnt -= v_cnt;
      uf.unite(u, v);
    }
  }
  reverse(all(ans));
  rep(i, q)
  {
    cout << ans[i] << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/
