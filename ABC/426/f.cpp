#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
#include <atcoder/fenwicktree>
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
  ll v, iter;
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
  if (a.v < b.v)
  {
    return a;
  }
  else
  {
    return b;
  }
}
S e()
{
  return {
      INF, 0, true};
}
struct Act
{
  ll m;
};
S mapping(Act f, S a)
{
  if (a.empty)
  {
    return a;
  }
  return {a.v - f.m, a.iter, a.empty};
}
Act composition(Act f, Act g)
{
  return {f.m + g.m};
}
Act id()
{
  return {0};
}
ll v;
bool g(S a)
{
  if (a.empty)
  {
    return true;
  }
  if (a.v >= v)
  {
    return true;
  }
  return false;
}
int main()
{
  ll n;
  cin >> n;
  vector<S> ini(n);
  rep(i, n)
  {
    ll a;
    cin >> a;
    ini[i] = {a, i, false};
  }
  lazy_segtree<S, op, e, Act, mapping, composition, id> seg(ini);
  fenwick_tree<ll> fw(n);
  ll q;
  cin >> q;
  rep(i, q)
  {
    ll l, r;
    cin >> l >> r >> v;
    l--;
    r--;
    ll res = 0;
    ll r_iter = l;
    while (r_iter <= r)
    {
      r_iter = seg.max_right<g>(l);
      if (r_iter <= r)
      {
        res += seg.get(r_iter).v;
        seg.set(r_iter, {0, r_iter, true});
        fw.add(r_iter, 1);
      }
    }
    seg.apply(l, r + 1, {v});
    ll cnt = fw.sum(l, r + 1);
    res += (r + 1 - l - cnt) * v;
    cout << res << endl;
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
