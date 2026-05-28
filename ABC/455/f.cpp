#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
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

// 二項係数計算
long long COM(int n, int k)
{
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
//////////////////////////////////////

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
  ll sum, cost, cnt, zero, l, r;
  bool empty;
};
S op(S a, S b)
{
  if (a.empty)
  {
    return b;
  }
  else if (b.empty)
  {
    return a;
  }
  return {
      (a.sum + b.sum) % MOD, (a.cost + b.cost + (a.sum * b.sum) % MOD) % MOD, a.cnt + b.cnt, a.zero + b.zero, a.l, b.r, false};
}
S e()
{
  return {-1, -1, 0, 1, -1, -1, true};
}
S mapping(ll f, S a)
{
  if (a.empty)
  {
    return a;
  }
  if (f == 0)
    return a;
  return {
      (((a.cnt + a.zero) * f) % MOD + a.sum) % MOD, (a.cost + (((f * f) % MOD) * (a.cnt) * (a.cnt - 1) / 2) % MOD + ((a.cnt - 1) * a.sum) % MOD * f % MOD + (a.zero * (a.zero - 1) / 2 * ((f * f) % MOD)) % MOD + (((a.sum + a.cnt * f) * a.zero)) % MOD * f % MOD) % MOD, a.cnt + a.zero, 0, a.l, a.r, a.empty};
}
ll composition(ll f, ll g)
{
  return (f + g) % MOD;
}
ll id()
{
  return 0;
}
int main()
{
  ll n, q;
  cin >> n >> q;
  COMinit();
  vector<S> ini(n);
  rep(i, n)
  {
    ini[i] = {0, 0, 0, 1, i, i + 1, false};
  }
  lazy_segtree<S, op, e, ll, mapping, composition, id> seg(ini);
  rep(i, q)
  {
    ll l, r, a;
    cin >> l >> r >> a;
    l--;
    seg.apply(l, r, a);
    auto res = seg.prod(l, r);

    cout << res.cost << endl;
  }
}
