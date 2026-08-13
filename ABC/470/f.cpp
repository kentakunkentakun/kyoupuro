#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
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

template <class T>
using PQ = priority_queue<T>;

template <class T>
using PQR = priority_queue<T, vector<T>, greater<T>>;

// const ll MOD = 1e9+7LL;
const ll MOD = 998244353LL;
const ll INF = 1LL << 62;
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

// a^{-1} mod を計算する

long long modinv(long long a, long long mod)
{
  return modpow(a, mod - 2, mod);
}
int main()
{
  ll n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  dsu uf(n);
  vvll k(n, vll(26));

  rep(i, n)
  {
    k[i][s[i] - 'a']++;
  }
  rep(i, m)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    a = uf.leader(a);
    b = uf.leader(b);
    if (!uf.same(a, b))
    {
      uf.merge(a, b);
      ll lead = uf.leader(a);
      ll re = a;
      if (lead == a)
      {
        re = b;
      }
      rep(j, 26)
      {
        k[lead][j] += k[re][j];
      }
    }
  }
  vll d(n + 1, 1);
  for (ll i = 1; i <= n; i++)
  {
    d[i] *= i * d[i - 1];
    d[i] %= MOD;
  }
  set<ll> se;
  ll ans = 1;
  vll tmp(0);
  bool ss = false;
  rep(i, n)
  {
    ll leader = uf.leader(i);
    rep(j, 26)
    {
      if (k[leader][j] > 1)
      {
        ss = true;
        break;
      }
    }
  }
  rep(i, n)
  {
    ll now = uf.leader(i);
    if (!se.count(now))
    {
      ll res = d[uf.size(now)];
      {
        rep(j, 26)
        {
          if (k[now][j] > 1)
          {
            res *= modinv(d[k[now][j]], MOD);
            res %= MOD;
          }
        }
        if (ss)
        {
          ans *= res;
          ans %= MOD;
        }
        else
          tmp.pb(res * modinv(2, MOD) % MOD);
      }
      se.insert(now);
    }
  }
  if (ss)
  {
    cout << ans << endl;
    return 0;
  }
  ll dpn = tmp.size();
  if (dpn)
  {
    vvll dp(dpn + 1, vll(2));
    dp[1][0] = tmp[0];
    dp[1][1] = tmp[0];
    rep(i, dpn)
    {
      if (i == 0)
        continue;
      dp[i + 1][0] += dp[i][0] * tmp[i] % MOD;
      dp[i + 1][0] %= MOD;
      dp[i + 1][0] += dp[i][1] * tmp[i] % MOD;
      dp[i + 1][0] %= MOD;
      dp[i + 1][1] += dp[i][0] * tmp[i] % MOD;
      dp[i + 1][1] += dp[i][1] * tmp[i] % MOD;
      dp[i + 1][1] %= MOD;
    }
    ans *= dp[dpn][0];
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
