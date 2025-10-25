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
int main()
{
  ll t;
  cin >> t;
  vll ans(0);
  rep(T, t)
  {
    ll n, m;
    cin >> n >> m;
    vll c(n);
    rep(i, n) cin >> c[i];
    vvll t(n, vll(0));
    rep(i, m)
    {
      ll u, v;
      cin >> u >> v;
      u--;
      v--;
      t[u].pb(v);
      t[v].pb(u);
    }
    vvll dp(n, vll(n, INF));
    dp[0][n - 1] = 0;
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> que;
    que.push({0, 0, n - 1});
    while (que.size())
    {
      auto [cnt, taka, aoki] = que.top();
      que.pop();
      if (dp[taka][aoki] < cnt)
        continue;
      for (auto k : t[taka])
      {
        for (auto a : t[aoki])
        {
          if (c[k] != c[a] && dp[k][a] > cnt + 1)
          {
            que.push({cnt + 1, k, a});
            dp[k][a] = cnt + 1;
          }
        }
      }
    }
    if (dp[n - 1][0] == INF)
    {
      ans.pb(-1);
    }
    else
      ans.pb(dp[n - 1][0]);
  }
  rep(i, t)
  {
    cout << ans[i] << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
