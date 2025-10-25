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
// 二項係数 nCr
const int MAX = 70;
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
int main()
{
  COMinit();
  ll h, w, k;
  cin >> h >> w >> k;
  vvll dp(h + 1, vll(w + 1, 0));
  dp[0][0] = 1;
  rep(i, h)
  {
    rep(j, w)
    {
      ll left = 0;
      ll right = 0;
      if (j + 1 < w)
      {
        ll l = 0;

        rep(k, j)
        {
          l += COM(j - 1 - (k - 1), k);
        }
        chmax(l, 1LL);
        ll r = 0;
        rep(k, w - 1 - (j + 1))
        {
          r += COM(w - 2 - (j + 1) - (k - 1), k);
        }
        chmax(r, 1LL);

        dp[i + 1][j + 1] += (dp[i][j] * r) % MOD * l;
        dp[i + 1][j + 1] %= MOD;
      }
      if (j - 1 >= 0)
      {
        ll l = 0;
        rep(k, j)
        {
          l += COM(j - 2 - (k - 1), k);
        }
        chmax(l, 1LL);
        ll r = 0;
        rep(k, w - (j + 1))
        {
          r += COM(w - 1 - (j + 1) - (k - 1), k);
        }
        chmax(r, 1LL);
        dp[i + 1][j - 1] += (dp[i][j] * r) % MOD * l;
        dp[i + 1][j - 1] %= MOD;
      }
      rep(k, w - 1 - j)
      {
        right += COM(w - 2 - j - (k - 1), k);
        right %= MOD;
      }
      rep(k, j)
      {
        left += COM(j - 1 - (k - 1), k);
        left %= MOD;
      }
      chmax(left, 1LL);
      chmax(right, 1LL);
      dp[i + 1][j] += (dp[i][j] * right) % MOD * left;
      dp[i + 1][j] %= MOD;
    }
  }
  cout << dp[h][k - 1] << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
