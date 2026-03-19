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
struct edge
{
  ll to, cost;
};
struct path
{
  ll bit, cost;
};
int main()
{
  ll n, m;
  cin >> n >> m;
  vector<vector<edge>> t(n, vector<edge>(0));
  vector<vector<ll>> d(n, vector<ll>(n, INF));

  rep(i, m)
  {
    ll u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    d[u][v] = w;
    t[u].pb({v, w});
  }
  rep(i, n) d[i][i] = 0;
  rep(k, n)
  {
    rep(i, n)
    {
      rep(j, n)
      {
        if (d[i][k] == INF || d[k][j] == INF)
          continue;

        chmin(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  vvll dp(1 << n, vll(n, INF));
  auto dfs = [&](auto dfs, ll now, ll bit) -> ll
  {
    if (dp[bit][now] != INF)
    {
      return dp[bit][now];
    }
    if (bit == (1 << n) - 1)
    {
      return dp[(1 << n) - 1][now] = 0;
    }
    ll res = INF;
    rep(i, n)
    {
      if (!(bit >> i & 1) && d[now][i] != INF)
      {
        ll cost = dfs(dfs, i, bit | (1 << i));
        if (cost != INF)
          chmin(res, cost + d[now][i]);
      }
    }
    return dp[bit][now] = res;
  };
  ll ans = INF;
  rep(i, n)
  {
    chmin(ans, dfs(dfs, i, 1 << i));
  }
  if (ans == INF)
  {
    cout << "No" << endl;
  }
  else
    cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
