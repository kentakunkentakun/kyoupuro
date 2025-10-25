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
long long modpow(long long a, long long n, long long mod)
{
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
int main()
{
  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<pll> t(0);
  ll iter = 0;
  ll cnt = 1;
  while (iter < n)
  {
    while (iter < n && s[iter] == s[iter + 1])
    {
      iter++;
      cnt++;
    }
    t.pb(pll(s[iter] - 'A', cnt));
    cnt = 1;
    iter++;
  }
  n = t.size();
  vector<vvll> dp(n + 1, vvll((1 << 10), vll(11, 0)));
  dp[0][0][0] = 1;
  rep(i, n)
  {
    ll it = t[i].F;
    rep(j, (1 << 10))
    {
      rep(z, 11)
      {
        if (!(j >> it & 1))
        {
          dp[i + 1][1 << it | j][it + 1] += (modpow(2LL, t[i].S, MOD) - 1 + MOD) % MOD * dp[i][j][z];
          dp[i + 1][1 << it | j][it + 1] %= MOD;
        }
        if ((j >> it & 1) && z == it + 1)
        {
          dp[i + 1][1 << it | j][it + 1] += (modpow(2LL, t[i].S, MOD) - 1 + MOD) % MOD * dp[i][j][z];
          dp[i + 1][1 << it | j][it + 1] %= MOD;
        }
        dp[i + 1][j][z] += dp[i][j][z];
        dp[i + 1][j][z] %= MOD;
      }
    }
  }
  ll ans = 0;
  rep(i, 1 << 10)
  {
    rep(j, 10)
    {
      ans += dp[n][i][j + 1];
      ans %= MOD;
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
__builtin_popcount(i)*/
