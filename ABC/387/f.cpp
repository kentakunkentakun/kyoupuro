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
using u64 = unsigned long long;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
const ll MOD = 998244353LL;
const ll INF = 1LL << 60;
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
bool isIn(ll nx, ll ny, ll h, ll w)
{
  if (nx >= 0 && nx < h && ny >= 0 && ny < w)
  {
    return true;
  }
  return false;
}
int main()
{
  ll n, m;
  cin >> n >> m;
  vll a(n);
  UnionFind<ll> uf(n);
  set<ll> is_circle;
  rep(i, n)
  {
    cin >> a[i];
    a[i]--;
  }
  vvll t(n, vll(0));
  vvll rt(n, vll(0));
  vvll come(n, vll(0));
  rep(i, n)
  {
    rt[i].pb(a[i]);
    come[a[i]].pb(i);
    uf.unite(a[i], i);
  }
  vb ch(n, false);
  ll iter = 0;
  vll cir(n, -1);
  vvll cirs(0);
  auto dfs = [&](auto dfs, ll now) -> bool
  {
    ch[now] = true;
    for (auto nx : rt[now])
    {
      if (ch[nx] == true)
      {
        cir[nx] = iter;
        cir[now] = iter;
        cirs.pb({now});
        is_circle.insert(uf.root(now));
        if (nx == now)
        {
          return false;
        }
        return true;
      }
      else
      {
        bool in = dfs(dfs, nx);
        if (in && cir[now] == -1)
        {
          cir[now] = iter;
          cirs[iter].pb(now);
          return true;
        }
        else if (in && cir[now] != -1)
        {
          cirs[iter].pb(now);
          return false;
        }
        else
        {
          return false;
        }
      }
    }
    return true;
  };
  rep(i, n)
  {
    if (!is_circle.count(uf.root(i)))
    {
      dfs(dfs, i);
      iter++;
    }
  }
  map<ll, ll> cir_iter;

  rep(i, cirs.size())
  {
    for (auto p : cirs[i])
    {
      cir_iter[p] = cirs[i][0];
    }
  }

  rep(i, n)
  {
    if (cir_iter.count(a[i]) && cir_iter.count(i))
    {
      continue;
    }
    else if (cir_iter.count(a[i]))
    {
      t[cir_iter[a[i]]].pb(i);
    }
    else if (cir_iter.count(i))
    {
      t[a[i]].pb(cir_iter[i]);
    }
    else
    {
      t[a[i]].pb(i);
    }
  }
  vvll dp(n, vll(m + 1, 0));
  auto dfs1 = [&](auto dfs, ll now, ll v) -> ll
  {
    if (dp[now][v] != 0)
    {
      return dp[now][v];
    }
    if (t[now].size() == 0)
    {
      rep(i, m)
      {
        dp[now][i + 1] = 1;
      }
      rep(i, m)
      {
        dp[now][i + 1] += dp[now][i];
      }
    }
    else
    {
      rep(i, m)
      {
        ll res = 1;
        for (auto nx : t[now])
        {
          res *= dfs(dfs, nx, i + 1);
          res %= MOD;
        }
        dp[now][i + 1] = res;
      }
      rep(i, m)
      {
        dp[now][i + 1] += dp[now][i];
        dp[now][i + 1] %= MOD;
      }
    }
    return dp[now][v];
  };
  ll ans = 1;
  rep(i, cirs.size())
  {
    ll s = cirs[i][0];
    ans *= dfs1(dfs1, s, m);
    ans %= MOD;
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
