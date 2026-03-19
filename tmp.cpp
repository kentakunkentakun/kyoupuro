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
using u64 = unsigned long long;
using vii = vector<int>;
using vvii = vector<vii>;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
// const ll MOD = 1e9+7LL;
const ll MOD = 998244353LL;
const ll INF = 1LL << 60;
const double INF_D = numeric_limits<double>::infinity();
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
bool isIn(ll nx, ll ny, ll h, ll w)
{
  if (nx >= 0 && nx < h && ny >= 0 && ny < w)
  {
    return true;
  }
  return false;
}
struct S
{
  ll it, v;
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
  return {-1, INF, true};
}
int main()
{
  ll n, l, k;
  cin >> n >> l >> k;
  vll a(n), c(n);

  rep(i, n)
  {
    cin >> a[i] >> c[i];
  }
  rep(i, n)
  {
    if (i != 0)
    {
      if (a[i] - a[i - 1] > k)
      {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  if (l - a[n - 1] > k || a[0] > k)
  {
    cout << -1 << endl;
    return 0;
  }
  a.pb(l);
  c.pb(0);
  vector<S> ini(n + 1);
  rep(i, n + 1)
  {
    ini[i] = {i, c[i], false};
  }
  segtree<S, op, e> seg(ini);

  vector<pll> d(0);
  d.pb({-1, 0});
  PQR(pll)
  que;
  ll now = 0;
  ll it = -1;
  while (now != l)
  {
    ll iter = upper_bound(all(a), now + k) - a.begin();
    auto nx = seg.prod(it + 1, iter);
    que.push({nx.v, d.size() - 1});
    d.pb({nx.it, a[nx.it]});
    now = a[nx.it];

    it = nx.it;
  }
  vll h(d.size(), INF);
  h[0] = k;
  while (que.size())
  {
    auto [cost, it] = que.top();
    it++;
    que.pop();
    auto [_, u] = d[it];
    if (u == l)
    {
      h[it] = 0;
    }
    else
    {
      if (h[it + 1] == INF)
      {
        h[it] = k;
      }
      else
      {
        h[it] = d[it + 1].S - d[it].S;
      }
    }
  }

  ll ans = 0;
  ll tmp = k;
  now = 0;
  rep(i, h.size())
  {
    if (h[i] > tmp)
    {
      ans += c[d[i].F] * (h[i] - tmp);
      tmp = h[i];
    }
    ans += max(0LL, h[i] - tmp) * c[d[i].F];
    if (i != h.size() - 1)
    {
      tmp -= d[i + 1].S - d[i].S;
    }
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
__builtin_popcountll(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
