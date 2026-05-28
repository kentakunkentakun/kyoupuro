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
struct edge
{
  ll to, cost;
};
int main()
{
  ll n, m, k;
  cin >> n >> m >> k;
  vector<vector<edge>> t(n, vector<edge>(0));
  vb used(n, false);
  used[0] = true;
  rep(i, m)
  {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    used[x] = true;
    used[y] = true;
    t[x].pb({y, 1});
  }
  if (m == 0)
  {
    cout << 1 << endl;
    return 0;
  }
  ll x = 0;
  vll nx(n, -1);
  repR(i, n)
  {
    nx[i] = x;
    if (used[i])
    {
      x = i;
    }
  }
  ll N = 0;
  vll a(0);
  map<ll, ll> iter;
  rep(i, n)
  {
    if (used[i])
    {
      a.pb(i);
      iter[i] = a.size() - 1;
    }
  }
  N = a.size();
  vector<vector<edge>> d(N, vector<edge>(0));

  rep(i, a.size())
  {
    d[i].pb({iter[nx[a[i]]], (nx[a[i]] - a[i] + n) % n});
    for (auto [e, cost] : t[a[i]])
    {
      d[i].pb({iter[e], 1});
    }
  }
  vvll dp(k + 1, vll(N + 1));
  dp[0][0] = 1;
  ll ans = 0;

  rep(i, k)
  {
    rep(j, N)
    {
      if (dp[i][j])
      {
        for (auto [nx, c] : d[j])
        {
          if (i + c <= k)
          {
            dp[i + c][nx] += dp[i][j];
            dp[i + c][nx] %= MOD;
          }
          else
          {
            ans += dp[i][j];
            ans %= MOD;
          }
        }
      }
    }
  }
  rep(i, N)
  {
    ans += dp[k][i];
    ans %= MOD;
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128
__builtin_popcount(i)*/
