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
using vii = vector<int>;
using vvii = vector<vii>;
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

// a^n mod を計算する

long long modpow(long long a, long long n, long long mod)
{
  a %= mod;
  long long res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

struct edge
{
  ll to, iter;
};
int main()
{
  ll n, m, k;
  cin >> n >> m >> k;
  vll a(m);
  rep(i, m)
  {
    cin >> a[i];
    a[i]--;
  }
  vector<vector<edge>> t(n, vector<edge>(0));
  rep(i, n - 1)
  {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    t[u].pb({v, i});
    t[v].pb({u, i});
  }
  vll d(n - 1, 0);
  vll tmp(0);
  vb used(n, false);
  auto dfs = [&](auto dfs, ll now, ll par, ll g) -> void
  {
    used[now] = true;
    if (now == g)
    {
      rep(i, tmp.size())
      {
        d[tmp[i]]++;
      }
      return;
    }
    for (auto [to, iter] : t[now])
    {
      if (used[to] || to == par)
        continue;
      tmp.pb(iter);
      dfs(dfs, to, now, g);
      tmp.pop_back();
    }
  };
  rep(i, m - 1)
  {
    tmp = {};
    rep(i, n)
    {
      used[i] = false;
    }
    dfs(dfs, a[i], -1, a[i + 1]);
  }

  vll u(0);
  ll sum = 0;
  ll zero = 0;
  rep(i, d.size())
  {
    if (d[i] != 0)
    {
      u.pb(d[i]);
      sum += d[i];
    }
    else
    {
      zero++;
    }
  }
  vll dp(200005, 0);
  dp[100000] = 1;
  rep(i, u.size())
  {
    vll tmp(200005, 0);
    swap(tmp, dp);
    rep(j, 200005)
    {
      if (tmp[j] != 0)
      {
        if (j - u[i] >= 0)
        {
          dp[j - u[i]] += tmp[j];
          dp[j - u[i]] %= MOD;
        }
        if (j + u[i] <= 200005)
        {
          dp[j + u[i]] += tmp[j];
          dp[j + u[i]] %= MOD;
        }
      }
    }
  }
  cout << (dp[100000 + k] * modpow(2, zero, MOD)) % MOD << endl;
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
