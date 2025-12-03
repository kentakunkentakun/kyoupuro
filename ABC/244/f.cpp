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
int main()
{
  ll n, m;
  cin >> n >> m;
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

  vll ans(1 << n, INF);
  ans[0] = 0;

  vvll dp(n, vll(1 << n, INF));
  queue<tuple<ll, ll, ll>> que;

  rep(i, n)
  {
    dp[i][1 << i] = 1;
    que.push({i, 1 << i, 1});
  }

  while (que.size())
  {
    auto [now, k, dist] = que.front();
    que.pop();
    if (dist > dp[now][k])
      continue;
    for (auto nx : t[now])
    {
      ll kx;
      if ((k >> nx) & 1)
      {
        kx = k - (1 << nx);
      }
      else
      {
        kx = k + (1 << nx);
      }

      if (chmin(dp[nx][kx], dist + 1))
      {
        que.push({nx, kx, dp[nx][kx]});
      }
    }
  }
  rep(j, n)
  {
    for (int bit = 0; bit < (1 << n); bit++)
    {
      chmin(ans[bit], dp[j][bit]);
    }
  }

  ll res = 0;
  rep(i, 1 << n)
  {
    res += ans[i];
  }
  cout << res << endl;
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
