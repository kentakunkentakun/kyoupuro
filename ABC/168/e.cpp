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
// gcd lcm
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
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
  map<tuple<ll, ll, ll>, ll> m;

  ll ans = 0;
  rep(i, n)
  {
    ll a, b;
    cin >> a >> b;
    ll minus = 0;
    if (a == 0 && b == 0)
    {
      ans++;
      continue;
    }
    else if (a == 0)
    {
      m[{0, -1, -1}]++;
      continue;
    }
    else if (b == 0)
    {
      m[{-1, 0, -1}]++;
      continue;
    }
    else if (a < 0 && b < 0)
    {
      a *= -1;
      b *= -1;
    }
    else if (a < 0)
    {
      minus = 1;
      a *= -1;
    }
    else if (b < 0)
    {
      minus = 1;
      b *= -1;
    }
    ll g = gcd(a, b);
    a /= g;
    b /= g;
    m[{a, b, minus}]++;
  }
  vector<pll> t(0);
  set<tuple<ll, ll, ll>> s;
  for (auto [M, cnt] : m)
  {
    auto [a, b, minus] = M;
    pll p = {cnt, -1};

    if (a == 0)
    {
      if (s.count({-1, 0, -1}))
        continue;
      if (m.count({-1, 0, -1}))
        p.S = m[{-1, 0, -1}];
      s.insert({0, -1, -1});
      t.pb(p);
      continue;
    }
    if (b == 0)
    {
      if (s.count({0, -1, -1}))
      {
        continue;
      }
      if (m.count({0, -1, -1}))
        p.S = m[{0, -1, -1}];
      s.insert({-1, 0, -1});
      t.pb(p);
      continue;
    }
    if (s.count({b, a, 1 - minus}))
      continue;
    if (m.count({b, a, 1 - minus}))
    {
      p.S = m[{b, a, 1 - minus}];
    }
    s.insert({a, b, minus});
    t.pb(p);
  }
  ll nt = t.size();
  vll dp(nt + 1, 0);
  dp[0] = 1;
  rep(i, nt)
  {
    auto [x, y] = t[i];
    dp[i + 1] += dp[i] * modpow(2, x, MOD);
    dp[i + 1] %= MOD;
    if (y != -1)
    {
      dp[i + 1] += dp[i] * modpow(2, y, MOD);
      dp[i + 1] %= MOD;
      dp[i + 1] -= dp[i];
      dp[i + 1] %= MOD;
      dp[i + 1] += MOD;
      dp[i + 1] %= MOD;
    }
  }
  cout << (ans + dp[nt] - 1 + MOD) % MOD << endl;
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
