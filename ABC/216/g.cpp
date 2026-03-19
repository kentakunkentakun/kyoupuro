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
  ll n0, n1;
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
  return {a.n0 + b.n0, a.n1 + b.n1, false};
}
S e()
{
  return {0, 0, true};
}
S mapping(ll f, S a)
{
  if (f > 0)
  {
    a.n1 += a.n0;
    a.n0 = 0;
  }
  return a;
}
ll composition(ll f, ll g)
{
  return min(1LL, f + g);
}
ll id()
{
  return 0;
}
ll k;
bool g(S x)
{
  return x.n0 <= k;
}

int main()
{
  ll n, m;
  cin >> n >> m;
  vector<S> ini(n);
  rep(i, n)
  {
    ini[i].empty = false;
    ini[i].n0 = 1;
  }
  lazy_segtree<S, op, e, ll, mapping, composition, id> seg(ini);
  vector<tuple<ll, ll, ll>> p(m);
  rep(i, m)
  {
    ll l, r, x;
    cin >> l >> r >> x;
    l--;
    p[i] = {r, l, x};
  }
  sort(all(p));
  rep(i, m)
  {
    auto [r, l, x] = p[i];
    S res = seg.prod(l, r);
    x -= res.n1;
    if (x <= 0)
      continue;
    k = x;
    ll left = seg.min_left<g>(r);
    seg.apply(left, r, 1);
  }
  rep(i, n)
  {
    S res = seg.get(i);
    if (res.n0)
    {
      cout << 0 << " ";
    }
    else
    {
      cout << 1 << " ";
    }
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128
__builtin_popcount(i)*/
