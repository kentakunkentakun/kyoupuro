#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
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
struct S
{
  ll v, cnt;
};
S op(S a, S b)
{
  return {(a.v + b.v) % MOD, a.cnt + b.cnt};
}
S e()
{
  return {0, 0};
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
const int MAX = 50;
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

// 順列 nPk
long long PERM(int n, int k)
{
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * finv[n - k] % MOD;
}
template <typename T = ll>
struct CC
{
  bool initialized;
  vector<T> xs;
  CC() : initialized(false) {}
  void add(T x) { xs.push_back(x); }
  void init()
  {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    initialized = true;
  }

  // lower_bound
  ll lb(T x)
  {
    if (!initialized)
      init();
    return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
  }

  // x 以下の最大の要素のindex
  ll operator()(T x)
  {
    if (!initialized)
      init();
    return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
  }

  // 圧縮後index i に対応する元の値を取得
  T operator[](ll i)
  {
    if (!initialized)
      init();
    return xs[i];
  }

  // x を登録済みかどうか
  bool contains(T x)
  {
    if (!initialized)
      init();
    int i = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    return i < (int)xs.size() && xs[i] == x;
  }

  ll size()
  {
    if (!initialized)
      init();
    return xs.size();
  }
};

int main()
{
  COMinit();
  ll n, x;
  cin >> n >> x;
  vll a(n);
  rep(i, n) cin >> a[i];
  if (n == 1)
  {
    cout << a[0] % MOD << endl;
    return 0;
  }
  ll m = n - 1;
  ll ans = 0;
  vll inv(45);
  ll k = 1;
  inv[0] = 1;
  rep(i, n)
  {
    if (i == 0)
      continue;
    k *= i;
    k %= MOD;
    inv[i] = k * modinv(PERM(n - 1, i), MOD);
    inv[i] %= MOD;
  }

  ll INV = modinv(n, MOD);
  rep(i, n)
  {
    vll t(0);
    rep(j, n)
    {
      if (j != i)
      {
        t.pb(a[j]);
      }
    }
    ll L = max(0LL, x - a[i]), R = x;
    if (m == 0)
      continue;
    vector<pll> l(0), r(0);
    for (int bit = 0; bit < (1 << (m / 2)); bit++)
    {
      ll cnt = 0;
      ll sum = 0;
      rep(j, m / 2)
      {
        if (bit >> j & 1)
        {
          sum += t[j];
          cnt++;
        }
      }
      l.pb({sum, cnt});
    }
    for (int bit = 0; bit < (1 << ((m + 1) / 2)); bit++)
    {
      ll cnt = 0;
      ll sum = 0;
      rep(j, (m + 1) / 2)
      {
        if (bit >> j & 1)
        {
          sum += t[m / 2 + j];
          cnt++;
        }
      }
      r.pb({sum, cnt});
    }
    sort(all(r));
    vvll A((m + 1) / 2 + 1, vll(0));
    rep(j, r.size())
    {
      auto [sum, cnt] = r[j];
      A[cnt].pb(sum);
    }
    // for (auto [l_sum, l_cnt] : l)
    // {
    //   if (R - l_sum <= 0)
    //     continue;
    //   rep(j, (m + 1) / 2 + 1)
    //   {
    //     CC<ll> cc;
    //     for (int z = 0; z < A[j].size(); z++)
    //     {
    //       cc.add(A[j][z]);
    //     }
    //     cc.init();
    //     vector<S> ini(cc.size());

    //     for (int z = 0; z < A[j].size(); z++)
    //     {
    //       ll id = cc.lb(A[j][z]);
    //       ini[id].cnt++;
    //       ini[id].v += A[j][z] % MOD;
    //       ini[id].v %= MOD;
    //     }
    //     segtree<S, op, e> seg(ini);

    //     ll lit = cc.lb(L - l_sum);
    //     ll rit = cc.lb(R - l_sum);
    //     S res = seg.prod(lit, rit);
    //     ll add = (res.v + (res.cnt % MOD) * ((l_sum + a[i]) % MOD)) % MOD;
    //     ll k = l_cnt + j;
    //     add = add * inv[k] % MOD;
    //     add = add * INV % MOD;
    //     ans += add;
    //     ans %= MOD;
    //   }
    // }
    // A[j] は右半分から cnt = j 個選んだときの sum 配列
    // 各 A[j] に対して、sum の累積和を作る
    vvll pref((m + 1) / 2 + 1);

    rep(j, (m + 1) / 2 + 1)
    {
      sort(all(A[j]));

      pref[j].assign(A[j].size() + 1, 0);

      rep(z, A[j].size())
      {
        pref[j][z + 1] = (pref[j][z] + A[j][z] % MOD) % MOD;
      }
    }

    for (auto [l_sum, l_cnt] : l)
    {
      if (R - l_sum <= 0)
        continue;

      rep(j, (m + 1) / 2 + 1)
      {
        ll lit = lower_bound(all(A[j]), L - l_sum) - A[j].begin();
        ll rit = lower_bound(all(A[j]), R - l_sum) - A[j].begin();

        ll cnt = rit - lit;
        ll r_sum = (pref[j][rit] - pref[j][lit] + MOD) % MOD;

        ll add = (r_sum + (cnt % MOD) * ((l_sum + a[i]) % MOD)) % MOD;

        ll k = l_cnt + j;
        add = add * inv[k] % MOD;
        add = add * INV % MOD;

        ans += add;
        ans %= MOD;
      }
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
__builtin_popcountll(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
