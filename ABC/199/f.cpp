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
// const ll MOD = 998244353LL;
const ll MOD = 1e9 + 7;
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

typedef vector<ll> vec;
typedef vector<vec> mat;

// A*Bの計算
mat mul(mat &A, mat &B, ll inv)
{
  mat c(A.size(), vec(B[0].size()));
  for (int i = 0; i < A.size(); i++)
  {
    for (int k = 0; k < B.size(); k++)
    {
      for (int j = 0; j < B[0].size(); j++)
      {
        c[i][j] = (c[i][j] + (A[i][k] * B[k][j]) % MOD * inv % MOD) % MOD;
      }
    }
  }
  return c;
}

// A^nの計算
mat pow(mat A, ll n, ll m, ll inv)
{
  mat B(A.size(), vec(A.size()));
  for (int i = 0; i < A.size(); i++)
  {
    B[i][i] = 2 * m;
  }
  while (n > 0)
  {
    if (n & 1)
      B = mul(B, A, inv);
    A = mul(A, A, inv);
    n >>= 1;
  }
  return B;
}

int main()
{
  ll n, m, k;
  cin >> n >> m >> k;
  vec a(n);
  rep(i, n) cin >> a[i];
  mat t(n, vec(n));
  rep(i, m)
  {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    t[x][y] = 1;
    t[y][x] = 1;
  }
  ll inv = modinv(2 * m, MOD);
  rep(i, n)
  {
    ll cnt = 0;
    rep(j, n)
    {
      if (t[i][j])
      {
        cnt++;
      }
    }
    t[i][i] = cnt + (m - cnt) * 2;
  }

  mat res = pow(t, k, m, inv);
  rep(i, n)
  {
    rep(j, n)
    {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  rep(i, n)
  {
    ll ans = 0;
    rep(j, n)
    {
      ans += (res[i][j] * a[j]) % MOD * inv % MOD;
      ans %= MOD;
    }
    cout << ans << endl;
  }
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
