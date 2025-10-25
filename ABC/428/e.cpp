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
// 木の直径（辺数）と直径の両端点を返す
// 戻り値: {diameter_len, u, v}
// g は 0-index、無向木（連結・N>=1）を仮定
tuple<int, int, int> tree_diameter(const vector<vector<int>> &g)
{
  int n = (int)g.size();
  auto bfs_far = [&](int s) -> pair<int, int>
  {
    vector<int> dist(n, -1);
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    int far = s;
    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      if (dist[u] > dist[far])
        far = u;
      for (int v : g[u])
        if (dist[v] == -1)
        {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
    }
    return {far, dist[far]};
  };

  // n==1 の特別扱い
  if (n == 1)
    return {0, 0, 0};

  // 任意頂点(0)から一番遠い a、a から一番遠い b
  auto [a, _da] = bfs_far(0);
  auto [b, diam] = bfs_far(a);
  return {diam, a, b};
}

int main()
{
  ll n;
  cin >> n;
  vvll t(n, vll(0));
  rep(i, n - 1)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    t[a].pb(b);
    t[b].pb(a);
  }
  vector<map<ll, pll>> dp(n);
  auto dfs = [&](auto dfs, ll now, ll par) -> pll
  {
    pll ma = {0, now};
    for (auto p : t[now])
    {
      if (p == par)
        continue;
      pll res = dfs(dfs, p, now);
      res.F++;
      dp[now][p] = res;
      if (ma.F < res.F)
      {
        ma = res;
      }
      else if (ma.F == res.F && ma.S < res.S)
      {
        ma = res;
      }
    }
    return ma;
  };
  dfs(dfs, 0, -1);
  vll ans(n);
  auto reroot = [&](auto reroot, ll now, ll par, pll ma) -> void
  {
    // {rinsetu,kyori,tyoten}

    tuple<ll, ll, ll> f = {par, ma.F, ma.S};
    tuple<ll, ll, ll> s = {-1, -1, -1};
    for (auto nx : t[now])
    {
      if (par == nx)
        continue;
      if (get<1>(f) < dp[now][nx].F || (get<1>(f) == dp[now][nx].F && get<2>(f) < dp[now][nx].S))
      {
        s = f;
        f = {nx, dp[now][nx].F, dp[now][nx].S};
      }
      else if (get<1>(s) < dp[now][nx].F || (get<1>(s) == dp[now][nx].F && get<2>(s) < dp[now][nx].S))
      {
        s = {nx, dp[now][nx].F, dp[now][nx].S};
      }
    }
    ans[now] = get<2>(f);
    for (auto nx : t[now])
    {
      if (par == nx)
        continue;
      if (get<0>(f) == nx)
      {
        pll a = {get<1>(s) + 1, get<2>(s)};
        reroot(reroot, nx, now, a);
      }
      else
      {
        pll a = {get<1>(f) + 1, get<2>(f)};
        reroot(reroot, nx, now, a);
      }
    }
  };
  reroot(reroot, 0, -1, {0, 0});
  rep(i, n)
  {
    cout << ans[i] + 1 << endl;
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
