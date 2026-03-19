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
  return max(a, b);
}
ll e()
{
  return 0;
}
ll mapping(ll f, ll a)
{
  return a + f;
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
  vll a(n);
  rep(i, n) cin >> a[i];
  lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(n + 1);
  set<ll> s;
  ll ans = 0;
  map<ll, ll> m;
  vll l(n + 1), r(n + 1);
  rep(i, n)
  {
    a[i]--;
    s.insert(a[i]);
    l[i + 1] = s.size();
  }
  s = {};
  repR(i, n)
  {
    s.insert(a[i]);
    r[i] = s.size();
  }
  vll t(n, -1);
  rep(i, n)
  {
    if (t[a[i]] == -1)
    {
      seg.apply(1, i + 1, 1);
    }
    else
    {
      seg.apply(t[a[i]], i + 1, 1);
    }
    ll res = seg.all_prod();
    seg.set(i + 1, l[i + 1]);
    chmax(ans, res + r[i + 1]);
    t[a[i]] = i + 1;
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
