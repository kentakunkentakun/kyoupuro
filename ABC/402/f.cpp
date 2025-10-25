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

// a^{-1} mod を計算する

long long modinv(long long a, long long mod)
{
  return modpow(a, mod - 2, mod);
}
int main()
{
  ll n, m;
  cin >> n >> m;
  vvll a(n, vll(n));
  rep(i, n) rep(j, n) cin >> a[i][j];
  if (n == 1)
  {
    cout << a[0][0] % m << endl;
    return 0;
  }
  vector<vvll> dp(n, vvll(n, vll(0)));
  rep(i, n)
  {
    rep(j, n)
    {
      ll k = n - 1 - i + n - 1 - j;
      a[i][j] = a[i][j] * modpow(10, k, m) % m;
    }
  }
  dp[0][0].pb(a[0][0]);
  rep(z, n - 1)
  {
    vector<vvll> old(n, vvll(n, vll(0)));
    swap(old, dp);
    rep(i, n)
    {
      rep(j, n)
      {
        if (i + j < n)
          for (auto v : old[i][j])
          {
            if (i + 1 < n)
            {
              dp[i + 1][j].pb((v + a[i + 1][j]) % m);
            }
            if (j + 1 < n)
            {
              dp[i][j + 1].pb((v + a[i][j + 1]) % m);
            }
          }
      }
    }
  }
  vector<vvll> dpb(n, vvll(n, vll(0)));
  dpb[n - 1][n - 1].pb(a[n - 1][n - 1]);

  rep(z, n - 2)
  {
    vector<vvll> old(n, vvll(n, vll(0)));
    swap(old, dpb);
    repR(i, n)
    {
      repR(j, n)
      {
        if (i + j >= n)
        {
          for (auto v : old[i][j])
          {
            if (i - 1 < n)
            {
              dpb[i - 1][j].pb((v + a[i - 1][j]) % m);
            }
            if (j - 1 < n)
            {
              dpb[i][j - 1].pb((v + a[i][j - 1]) % m);
            }
          }
        }
      }
    }
  }
  for (int x = 1; x < n; x++)
  {
    ll y = n - x;
    sort(all(dpb[x][y]));
    dpb[x][y].erase(unique(dpb[x][y].begin(), dpb[x][y].end()), dpb[x][y].end());
  }
  ll ans = -INF;
  rep(z, n)
  {
    ll x = z;
    ll y = n - 1 - x;

    for (auto v : dp[x][y])
    {
      if (x + 1 < n)
      {
        ll si = dpb[x + 1][y].size();
        ll nx = m - v - 1;
        auto iter = upper_bound(all(dpb[x + 1][y]), nx) - dpb[x + 1][y].begin() - 1 + si;
        iter %= si;
        chmax(ans, (dpb[x + 1][y][iter] + v) % m);
        // iter = upper_bound(all(dpb[x + 1][y]), nx) - dpb[x + 1][y].begin() + si;
        // iter %= si;
        // chmax(ans, (dpb[x + 1][y][iter] + v) % m);
      }
      if (y + 1 < n)
      {
        ll si = dpb[x][y + 1].size();
        ll nx = m - v - 1;
        auto iter = upper_bound(all(dpb[x][y + 1]), nx) - dpb[x][y + 1].begin() - 1 + si;
        iter %= si;
        chmax(ans, (dpb[x][y + 1][iter] + v) % m);
        // iter = upper_bound(all(dpb[x][y + 1]), nx) - dpb[x][y + 1].begin() + si;
        // iter %= si;
        // chmax(ans, (dpb[x][y + 1][iter] + v) % m);
      }
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
