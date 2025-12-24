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
ll op(ll a, ll b)
{
  return max(a, b);
}
ll e()
{
  return 0;
}
struct Act
{
  ll plus;
};
ll mapping(Act a, ll b)
{
  return b + a.plus;
}
Act composition(Act a, Act b)
{
  return {a.plus + b.plus};
}

Act id()
{
  return {0};
}

const ll MAX_X = 2 * 100000 + 5;
int main()
{
  ll n, d, w;
  cin >> n >> d >> w;
  vvll t(MAX_X, vll(0));
  rep(i, n)
  {
    ll time, x;
    cin >> time >> x;
    t[time].pb(x);
  }
  rep(i, n)
  {
    if (t[i].size())
    {
      sort(all(t[i]));
    }
  }

  vll ini(MAX_X, 0);
  lazy_segtree<ll, op, e, Act, mapping, composition, id> seg(ini);
  rep(i, d)
  {
    rep(j, t[i].size())
    {
      seg.apply(t[i][j], min(MAX_X - 1, t[i][j] + w), {1});
    }
  }
  ll ans = seg.all_prod();
  for (int i = d; i < MAX_X; i++)
  {
    rep(j, t[i].size())
    {
      seg.apply(t[i][j], min(MAX_X - 1, t[i][j] + w), {1});
    }
    rep(j, t[i - d].size())
    {
      seg.apply(t[i - d][j], min(MAX_X - 1, t[i - d][j] + w), {-1});
    }
    chmax(ans, seg.all_prod());
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
