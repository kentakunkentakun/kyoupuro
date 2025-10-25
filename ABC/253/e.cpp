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
  ll n, m, k;
  cin >> n >> m >> k;
  vll dp(m + 5);
  rep(i, m + 1)
  {
    if (i != 0)
    {
      dp[i] = 1;
    }
  }
  rep(i, n - 1)
  {
    vll old(m + 5, 0);
    swap(old, dp);
    rep(j, m + 1)
    {
      if (j > k)
      {
        dp[1] += old[j];
        dp[1] %= MOD;
        dp[j - k + 1] -= old[j];
        dp[j - k + 1] %= MOD;
      }
      if (j + k <= m)
      {
        dp[j + k] += old[j];
        dp[j + k] %= MOD;
        dp[m + 1] -= old[j];
        dp[m + 1] %= MOD;
      }
      if (k == 0)
      {
        dp[j] -= old[j];
        dp[j - k + 1] += old[j];
        dp[j] %= MOD;
        dp[j - k + 1] %= MOD;
      }
    }
    rep(j, m + 1)
    {
      dp[j + 1] += dp[j];
      dp[j + 1] %= MOD;
    }
  }
  ll ans = 0;
  rep(i, m + 1)
  {
    if (i == 0)
      continue;
    ans += dp[i];
    ans %= MOD;
  }
  cout << (ans + MOD) % MOD << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/
