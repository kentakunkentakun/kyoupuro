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
// const ll MOD = 998244353LL;
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
// 二項係数 nCr
const int MAX = 700000;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++)
  {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long COM(int n, int k)
{
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// 順列 nPk
long long PERM(int n, int k)
{
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  // nPk = n! / (n-k)!
  return fac[n] * finv[n - k] % MOD;
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
  COMinit();
  ll n, m;
  cin >> n >> m;
  vll dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 1;
  for (int i = 3; i <= n; i++)
  {
    dp[i] = (i * dp[i - 1]) % MOD * modinv((i - 1), MOD);
    dp[i] %= MOD;
    cout << i << " " << dp[i] << endl;
  }
  vll k(m + 1, 0);
  k[0] = 1;
  k[1] = 1;
  rep(i, m + 1)
  {
    if (i < 2)
      continue;
    k[i] = i * k[i - 1];
    k[i] %= MOD;
  }
  ll ans = k[m];
  cout << "ans " << ans << endl;
  ll res = 0;
  for (int i = 0; i <= min(m - n, n); i++)
  {
    res += (((dp[n - i] * COM(m - n, i)) % MOD * COM(n, i)) % MOD * k[i]) % MOD;
    res %= MOD;
    cout << res << " " << i << " " << COM(m - n, i) << " " << COM(n, i) << " " << (((dp[n - i] * COM(m - n, i)) % MOD * COM(n, i)) % MOD * k[i]) % MOD << " " << dp[n - i] * COM(m - n, i) * COM(n, i) * k[i] << endl;
  }
  ans *= res;
  ans %= MOD;
  cout << ans << endl;
  ll tmp = 0;
  vll t(n, 0);
  rep(i, n)
  {
    t[i] = i + 1;
  }
  do
  {
    vll t2(n);
    rep(i, n)
    {
      t2[i] = i + 1;
    }
    do
    {
      bool ok = true;
      rep(i, n)
      {
        if (t[i] == t2[i])
          ok = false;
      }
      if (ok)
        tmp++;
    } while (next_permutation(all(t2)));

  } while (next_permutation(all(t)));
  cout << tmp << endl;
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
