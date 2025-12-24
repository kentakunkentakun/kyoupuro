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
  else if (b.empty)
  {
    return a;
  }
  return {a.v + b.v, false};
}
S e()
{
  return {0, true};
}

struct Act
{
  bool empty, ini;
  ll v;
};
S mapping(Act f, S a)
{
  if (f.ini)
  {
    return a;
  }
  if (f.empty)
  {
    return e();
  }
  return {f.v, false};
}
Act composition(Act a, Act b)
{
  if (a.ini)
  {
    return b;
  }
  else if (b.ini)
  {
    return a;
  }
  if (a.empty)
  {
    return a;
  }
  else if (b.empty)
  {
    return a;
  }
  else
  {
    return {a.empty, false, a.v + b.v};
  }
}
Act id()
{
  return {true, true, 0};
}
int main()
{
  ll q;
  cin >> q;
  vector<tuple<ll, ll, ll>> query(q);
  vector<pll> a(1);
  a[0] = {0, -1};
  rep(i, q)
  {
    ll t;
    cin >> t;
    if (t == 1)
    {
      ll x;
      cin >> x;
      query[i] = {t, x, -1};
      auto [_, nx] = a[x];
      a[x].S = a.size();
      a.pb({i + 1, nx});
    }
    else
    {
      ll x, y;
      cin >> x >> y;
      query[i] = {t, x, y};
      a.pb({-1, -1});
    }
  }
  ll iter = 0;
  ll cnt = 0;
  map<ll, ll> m;
  while (iter != -1)
  {
    m[a[iter].F] = cnt;
    iter = a[iter].S;
    cnt++;
  }
  vector<S> ini(a.size(), {0, true});
  lazy_segtree<S, op, e, Act, mapping, composition, id> seg(ini);
  vll ans(0);
  rep(i, q)
  {
    auto [u, x, y] = query[i];
    if (u == 2)
    {
      ll l = min(m[x], m[y]) + 1;
      ll r = max(m[x], m[y]);
      ans.pb(seg.prod(l, r).v);
      seg.apply(l, r, {true, false, 0});
    }
    else
    {
      seg.set(m[i + 1], {i + 1, false});
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

__builtin_popcount(i)*/
