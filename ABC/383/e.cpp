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

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};
struct edge
{
  ll u, v, cost;
};
bool comp(edge u, edge v)
{
  return u.cost < v.cost;
}
int main()
{
  ll n, m, k;
  cin >> n >> m >> k;
  UnionFind<ll> uf(n);
  vector<edge> e(m);
  vector<vector<ll>> s(n, vector<ll>(2));
  rep(i, m)
  {
    ll u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    e[i] = {u, v, w};
  }
  rep(i, k)
  {
    ll a;
    cin >> a;
    a--;
    s[a][0]++;
  }
  rep(i, k)
  {
    ll b;
    cin >> b;
    b--;
    s[b][1]++;
  }
  sort(all(e), comp);

  ll ans = 0;
  rep(i, m)
  {
    auto [u, v, c] = e[i];
    ll u_root = uf.root(u);
    ll v_root = uf.root(v);
    if (!uf.same(u_root, v_root))
    {
      ll cnt = max(min(s[u_root][0], s[v_root][1]), min(s[v_root][0], s[u_root][1]));
      ans += cnt * c;
      uf.unite(u_root, v_root);
      ll root = uf.root(u_root);
      ll another = root == u_root ? v_root : u_root;
      s[root][0] = s[root][0] + s[another][0] - cnt;
      s[root][1] = s[root][1] + s[another][1] - cnt;
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
