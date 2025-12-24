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
struct S
{
  ll v, a_sum, b_sum, length;
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
      (a.v + b.v) % MOD,
      (a.a_sum + b.a_sum) % MOD,
      (a.b_sum + b.b_sum) % MOD,
      a.length + b.length,
      false};
}
S e()
{
  return {
      0, 0, 0, 1, true};
}

struct Act
{
  ll a, b;
};

S mapping(Act f, S a)
{
  ll nv = a.v + (a.a_sum * f.b) % MOD + (a.b_sum * f.a) % MOD + (((f.b * a.length) % MOD * f.a) % MOD) % MOD;
  nv %= MOD;
  return {
      nv,
      (a.a_sum + a.length * f.a) % MOD,
      (a.b_sum + a.length * f.b) % MOD,
      a.length,
      false};
}
Act composition(Act a, Act b)
{
  return {
      (a.a + b.a) % MOD,
      (a.b + b.b) % MOD};
}
Act id()
{
  return {
      0, 0};
}

int main()
{
  ll n, q;
  cin >> n >> q;
  vll a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  vector<S> ini(n);
  rep(i, n)
  {
    ini[i] = {
        (a[i] * b[i]) % MOD,
        a[i],
        b[i],
        1,
        false};
  }
  lazy_segtree<S, op, e, Act, mapping, composition, id> seg(ini);
  vll ans(0);
  rep(i, q)
  {
    ll t;
    cin >> t;
    if (t == 1)
    {
      ll l, r, x;
      cin >> l >> r >> x;
      l--;
      r--;
      seg.apply(l, r + 1, {x, 0});
    }
    else if (t == 2)
    {
      ll l, r, x;
      cin >> l >> r >> x;
      l--;
      r--;
      seg.apply(l, r + 1, {0, x});
    }
    else
    {
      ll l, r;
      cin >> l >> r;
      l--;
      r--;
      ans.pb(seg.prod(l, r + 1).v);
    }
  }
  rep(i, ans.size())
  {
    cout << ans[i] << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/
