#include <bits/stdc++.h>
#include <atcoder/segtree>
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
ll op(ll a, ll b)
{
  return a + b;
}
ll e()
{
  return 0;
}
int main()
{
  ll n;
  cin >> n;
  vll c(n), x(n);
  rep(i, n) cin >> c[i];
  rep(i, n) cin >> x[i];
  vector<pll> p(n);
  vector<vector<pll>> t(n, vector<pll>(0));
  vll ini(n);
  vvll iter(n, vll(0));
  rep(i, n)
  {
    c[i]--;
    x[i]--;
    t[c[i]].pb({x[i], i});
    iter[c[i]].pb(i);
  }
  ll cnt = 0;
  rep(i, n)
  {
    set<ll> s;
    rep(j, t[i].size())
    {
      s.insert(t[i][j].first);
    }
    map<ll, ll> iter;
    ll it = 0;
    for (auto v : s)
    {
      iter[v] = it;
      it++;
    }
    segtree<ll, op, e> seg(it);
    rep(j, t[i].size())
    {
      cnt += seg.prod(iter[t[i][j].F] + 1, it);
      ll now = seg.get(iter[t[i][j].F]);
      seg.set(iter[t[i][j].F], now + 1);
    }
  }
  ll ans = 0;
  segtree<ll, op, e> seg(n);
  rep(i, n)
  {
    ans += seg.prod(x[i] + 1, n);
    ll now = seg.get(x[i]);
    seg.set(x[i], now + 1);
  }
  cout << ans - cnt << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
