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
// const ll MOD = 1000000007LL;
const ll MOD = 998244353LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vdouble = vector<double>;
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

// a^{-1} mod を計算する

long long modinv(long long a, long long mod)
{
  return modpow(a, mod - 2, mod);
}
int main()
{
  cout << fixed << setprecision(10);

  double n;
  cin >> n;
  vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1));
  auto dfs = [&](auto dfs, ll remain, double i) -> double
  {
    if (remain == 1)
    {
      return dp[remain][i] = 1;
    }
    if (dp[remain][i] != -1)
      return dp[remain][i];

    // double inv = modinv(2, MOD);
    // double inv_re = modpow(inv, remain, MOD);
    // double inv_re_r = modinv(inv_re, MOD);

    vdouble am(remain);
    for (int j = 1; j < remain; j++)
    {
      am[j] = dfs(dfs, remain - 1, j - 1) / 2;
      // am[j] = inv * dfs(dfs, remain - 1, j - 1);
      //  am[j] %= MOD;
    }

    double k = 0;
    rep(j, remain - 1)
    {
      k += am[j + 1];
      k /= 2.0;
      // k *= inv;
      //  k %= MOD;
    }
    cout << k << endl;
    if (remain == 2)
    {
      k *= 4.0;
      k /= 3.0;
    }
    // k *= inv;
    // k *= inv_re_r;
    // k %= MOD;
    dp[remain][0] = k;
    cout << remain << " " << 0 << " " << dp[remain][0] << endl;

    rep(j, remain)
    {
      if (j == 0)
        continue;
      // dp[remain][j] = inv * dp[remain][j - 1] + am[j];
      dp[remain][j] = 0.5 * dp[remain][j - 1] + am[j];

      // dp[remain][j] %= MOD;
      cout << remain << " " << j << " " << dp[remain][j] << endl;
    }
    return dp[remain][i];
  };
  dfs(dfs, n, 0);
  rep(i, n)
  {
    cout << dp[n][i] << " ";
  }
  cout << endl;
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
