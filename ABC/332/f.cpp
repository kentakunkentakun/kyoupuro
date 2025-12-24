#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;
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
const ll MOD = 998244353LL;
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
struct S
{
  ll v;
  bool empty;
};
S op(S a, S b)
{
  if (a.empty)
  {
    return b;
  }
  return a;
}
S e()
{
  return {
      0, true};
}
struct Act
{
  ll div, plus;
};
S mapping(Act f, S a)
{
  return {((a.v * f.div) % MOD + f.plus) % MOD, a.empty};
}
Act composition(Act g, Act f)
{
  return {
      (f.div * g.div) % MOD, ((f.plus * g.div) % MOD + g.plus) % MOD};
}
Act id()
{
  return {
      1, 0};
}
int main()
{
  ll n, m;
  cin >> n >> m;
  vector<S> ini(n);
  rep(i, n)
  {
    ll a;
    cin >> a;
    ini[i] = {a, false};
  }
  lazy_segtree<S, op, e, Act, mapping, composition, id> seg(ini);
  rep(i, m)
  {
    ll l, r, x;
    cin >> l >> r >> x;
    l--;
    r--;
    ll div = (r - l) * modinv((r - l + 1), MOD);
    ll plus = x * modinv((r - l + 1), MOD);
    div %= MOD;
    plus %= MOD;
    seg.apply(l, r + 1, {div, plus});
  }
  rep(i, n)
  {
    cout << seg.get(i).v << " ";
  }
  cout << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128
__builtin_popcount(i)*/
