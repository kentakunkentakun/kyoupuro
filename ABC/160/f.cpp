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
const int MAX = 2000000;
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

// 二項係数 nCk
long long COM(int n, int k)
{
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
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
  ll n;
  cin >> n;
  COMinit();
  vvll t(n, vll(0));
  rep(i, n - 1)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    t[a].pb(b);
    t[b].pb(a);
  }
  vector<pll> d(n);
  {
    auto dfs = [&](auto dfs, ll now, ll par) -> pll
    {
      if (par != -1 && t[now].size() == 1)
      {
        d[now].F = 1, d[now].S = 1;
        return {1, 1};
      }
      ll res = 1;
      ll cnt = 0;
      for (auto nx : t[now])
      {
        if (nx == par)
          continue;
        auto p = dfs(dfs, nx, now);
        res *= (p.F * COM(cnt + p.S, p.S)) % MOD;
        res %= MOD;
        cnt += p.S;
      }
      cnt++;
      return d[now] = {res, cnt};
    };
    dfs(dfs, 0, -1);
  }
  vll ans(n);
  {
    auto dfs = [&](auto dfs, ll now, ll par, pll p) -> void
    {
      if (par == -1)
      {
        ans[now] = d[now].F;
      }
      else
      {
        ll res = p.F;
        ll cnt = p.S;
        for (auto nx : t[now])
        {
          if (nx == par)
            continue;
          res *= d[nx].F;
          res %= MOD;
          res *= COM(cnt + d[nx].S, d[nx].S);
          res %= MOD;
          cnt += d[nx].S;
        }
        ans[now] = res;
      }
      pll nxp = p;
      for (auto nx : t[now])
      {
        if (nx != par)
        {
          nxp.F *= d[nx].F;
          nxp.F %= MOD;
          nxp.F *= COM(d[nx].S + nxp.S, d[nx].S);
          nxp.F %= MOD;
          nxp.S += d[nx].S;
        }
      }
      for (auto nx : t[now])
      {
        if (nx == par)
          continue;
        nxp.F *= modinv(COM(nxp.S, d[nx].S), MOD);
        nxp.F %= MOD;
        nxp.F *= modinv(d[nx].F, MOD);
        nxp.F %= MOD;
        nxp.S -= d[nx].S;
        nxp.S++;
        dfs(dfs, nx, now, nxp);
        nxp.S--;
        nxp.S += d[nx].S;
        nxp.F *= d[nx].F;
        nxp.F %= MOD;
        nxp.F *= COM(nxp.S, d[nx].S);
        nxp.F %= MOD;
      }
      return;
    };
    pll tmp = {1, 0};
    dfs(dfs, 0, -1, tmp);
  }
  rep(i, n)
  {
    cout << ans[i] << endl;
  }
}
