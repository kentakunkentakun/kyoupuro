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
struct S
{
  ll sum, cnt;
};
S op(S a, S b)
{
  return {
      a.sum + b.sum,
      a.cnt + b.cnt};
}
S e()
{
  return {
      0, 1};
}
S mapping(ll f, S a)
{
  return {
      a.sum + f * a.cnt, a.cnt};
}
ll composition(ll f, ll g)
{
  return f + g;
}
ll id()
{
  return 0;
}
int main()
{
  ll n;
  cin >> n;
  vvll t(n, vll(0));
  rep(i, n - 1)
  {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    t[max(u, v)].pb(min(u, v));
  }
  rep(i, n)
  {
    t[i].pb(-1);
    sort(rall(t[i]));
  }
  ll ans = 0;
  lazy_segtree<S, op, e, ll, mapping, composition, id> seg(n);
  for (int i = 0; i < n; i++)
  {
    ll r = i + 1;
    ll v = 1;
    rep(j, t[i].size())
    {
      seg.apply(t[i][j] + 1, r, v);
      v--;
      r = t[i][j] + 1;
    }
    ans += seg.prod(0, n).sum;
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
__builtin_popcount(i)*/
