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
int main()
{
  ll n;
  cin >> n;
  vll a(n);
  rep(i, n) cin >> a[i];
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  vvll dp(n, vll(n, INF));
  vvll t(n, vll(0));
  rep(i, n) dp[i][i] = 0;
  rep(i, n)
  {
    rep(j, n)
    {
      if (s[i][j] == 'Y')
      {
        dp[i][j] = 1;
        t[i].pb(j);
      }
    }
  }
  rep(k, n)
  {
    rep(i, n)
    {
      rep(j, n)
      {
        chmin(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  vvll value(n, vll(n, 0));
  rep(i, n)
  {
    value[i][i] = a[i];
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> que;
    que.push({0, -1 * a[i], i});
    while (que.size())
    {
      auto [dist, V, now] = que.top();
      que.pop();
      V *= -1;
      if (value[i][now] > V)
        continue;
      for (auto nx : t[now])
      {
        if (dist + 1 == dp[i][nx])
        {
          if (chmax(value[i][nx], value[i][now] + a[nx]))
          {
            que.push({dist + 1, -1 * value[i][nx], nx});
          }
        }
      }
    }
  }
  ll q;
  cin >> q;
  vector<pll> ans(q);

  rep(i, q)
  {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    if (dp[u][v] != INF)
    {
      ans[i] = {dp[u][v], value[u][v]};
    }
    else
    {
      ans[i] = {-1, -1};
    }
  }
  rep(i, q)
  {
    if (ans[i].F == -1)
    {
      cout << "Impossible" << endl;
    }
    else
    {
      cout << ans[i].F << " " << ans[i].S << endl;
    }
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128
__builtin_popcount(i)*/
