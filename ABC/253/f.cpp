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
ll op(ll a, ll b)
{
  return a + b;
}
ll e()
{
  return 0;
}
struct Act
{
  ll v;
};
ll mapping(Act f, ll a)
{
  return a + f.v;
}
Act composition(Act a, Act b)
{
  return {a.v + b.v};
}
Act id()
{
  return {0};
}
int main()
{
  ll n, m, q;
  cin >> n >> m >> q;
  vector<pll> p(m);
  vll ini(m);
  lazy_segtree<ll, op, e, Act, mapping, composition, id> seg(ini);
  vector<tuple<ll, ll, ll, ll>> query(q);
  vector<vector<tuple<ll, ll, ll>>> u(n, vector<tuple<ll, ll, ll>>(0));
  ll iter = 0;
  rep(i, q)
  {
    ll t;
    cin >> t;
    if (t == 1)
    {
      ll l, r, x;
      cin >> l >> r >> x;
      query[i] = {t, l, r, x};
    }
    else if (t == 2)
    {
      ll j, x;
      cin >> j >> x;
      query[i] = {t, j, x, -1};
    }
    else
    {
      ll x, y;
      cin >> x >> y;
      query[i] = {t, x, y, iter};
      iter++;
    }
  }
  vll ans(iter);

  rep(i, m)
  {
    // 初期値,それまでの累積
    p[i] = {0, 0};
  }
  repR(i, q)
  {
    auto [t, _, __, ___] = query[i];
    if (t == 1)
    {
      auto [_, l, r, x] = query[i];
      l--;
      r--;
      seg.apply(l, r + 1, {x});
    }
    else if (t == 2)
    {
      auto [_, j, x, __] = query[i];
      j--;
      for (auto [rui, y, iter] : u[j])
      {
        ans[iter] = seg.prod(y, y + 1) - rui + x;
      }
      u[j] = {};
    }
    else
    {
      auto [_, x, y, it] = query[i];
      x--;
      y--;
      // 累積,yの値,ansのiter
      u[x].pb({seg.prod(y, y + 1), y, it});
    }
  }
  rep(i, n)
  {
    for (auto [rui, y, iter] : u[i])
    {
      ans[iter] = seg.prod(y, y + 1) - rui;
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
