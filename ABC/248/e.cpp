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
using vvvll = vector<vvll>;
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
bool isIn(ll nx, ll ny, ll h, ll w)
{
  if (nx >= 0 && nx < h && ny >= 0 && ny < w)
  {
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
// gcd lcm
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int main()
{
  ll n, k;
  cin >> n >> k;

  vll x(n), y(n);

  rep(i, n)
  {
    cin >> x[i] >> y[i];
  }
  if (k == 1)
  {
    cout << "Infinity" << endl;
    return 0;
  }
  // 正負,bunshi,bunbo i
  map<tuple<ll, ll, ll>, vector<pll>> m;
  rep(i, n)
  {
    for (int j = i + 1; j < n; j++)
    {
      ll seihu = 1;
      ll bunshi = y[i] - y[j];
      ll bunbo = x[i] - x[j];
      if (bunshi < 0 && bunbo < 0)
      {
        bunshi *= -1;
        bunbo *= -1;
      }
      else if (bunshi < 0)
      {
        bunshi *= -1;
        seihu = 0;
      }
      else if (bunbo < 0)
      {
        bunbo *= -1;
        seihu = 0;
      }
      ll gc = gcd(bunshi, bunbo);

      bunshi /= gc;
      bunbo /= gc;
      if (bunshi == 0)
      {
        bunbo = 1;
        seihu = 1;
      }
      if (bunbo == 0)
      {
        bunshi = 1;
        seihu = 1;
      }
      m[{seihu, bunshi, bunbo}].pb({i, j});
    }
  }
  ll ans = 0;
  for (auto &p : m)
  {
    auto v = p.S;
    UnionFind<ll> uf(n);
    for (auto [i, j] : v)
    {
      uf.unite(i, j);
    }
    set<ll> s;
    rep(i, n)
    {
      ll root = uf.root(i);
      if (uf.size(root) >= k && !s.count(root))
      {
        ans++;
        s.insert(root);
      }
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
