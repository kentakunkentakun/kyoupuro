#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
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
const ll MOD = 1e9 + 7LL;
// const ll MOD = 998244353LL;
const ll INF = 1LL << 60;
const double INF_D = numeric_limits<double>::infinity();
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
bool isSquare(long long n)
{
  long long r = sqrtl((long double)n);
  while ((__int128)(r + 1) * (r + 1) <= n)
    r++;
  while ((__int128)r * r > n)
    r--;
  return (__int128)r * r == n;
}
int main()
{
  ll n, k;
  cin >> n >> k;
  ll m = sqrt(n) + 1;
  if (isSquare(n))
    m--;
  vvll dp(k + 1, vll(m + 1));
  vll d(m + 1);
  vll b(m + 1);
  d[1] = 1;
  rep(i, m)
  {
    d[i + 1] += d[i];
  }
  dp[0][1] = 1;

  rep(i, k)
  {
    vll tmp(m + 1, 0);
    vll tmpb(m + 1, 0);
    swap(tmp, d);
    swap(tmpb, b);
    repR(j, m + 1)
    {
      if (j == 0)
        continue;
      tmpb[j - 1] += tmpb[j];
      tmpb[j - 1] %= MOD;
    }
    for (int j = 1; j <= m; j++)
    {
      dp[i + 1][j] += tmp[min(m, n / j)];
      dp[i + 1][j] %= MOD;
      dp[i + 1][j] += tmpb[j];
      dp[i + 1][j] %= MOD;
      // cout << i + 1 << " " << j << " " << dp[i + 1][j] << " " << min(m, n / j) << endl;
    }
    rep(j, m)
    {
      d[j + 1] += d[j] + dp[i + 1][j + 1];
      d[j + 1] %= MOD;
    }
    rep(j, m)
    {
      if (j == 0)
        continue;
      b[j] = (((n / j) - max(m, (n / (j + 1)))) * tmp[j]) % MOD;
      chmax(b[j], 0LL);
      // cout << j << " j b[j] " << b[j] << endl;
    }
  }

  ll ans = 0;
  rep(i, m + 1)
  {
    ans += dp[k][i];
    ans %= MOD;
  }
  rep(i, m)
  {
    ans += b[i];
    ans %= MOD;
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
__builtin_popcountll(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
