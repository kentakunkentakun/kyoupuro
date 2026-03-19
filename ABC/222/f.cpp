#include <bits/stdc++.h>

using namespace std;
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
const ll MOD = 998244353LL;
const ll INF = 1LL << 60;
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
struct edge
{
  ll to, cost;
};
int main()
{
  ll n;
  cin >> n;
  vector<vector<edge>> t(n, vector<edge>(0));
  rep(i, n - 1)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    t[a].pb({b, c});
    t[b].pb({a, c});
  }
  vll d(n);
  rep(i, n) cin >> d[i];
  vll k(n, 0);
  auto dfs = [&](auto dfs, ll now, ll par = -1) -> ll
  {
    ll res = 0;
    for (auto [nx, cost] : t[now])
    {
      if (nx == par)
        continue;
      chmax(res, dfs(dfs, nx, now) + cost);
    }
    return k[now] = max(res, d[now]);
  };
  dfs(dfs, 0, -1);
  vll ans(n, 0);
  auto dfs2 = [&](auto dfs2, ll now, ll cost, ll par = -1) -> void
  {
    pll f = {0, 0}, s = {0, 0};
    if (cost > d[now])
    {
      f.F = cost;
      f.S = par;
      s.F = d[now];
      s.S = now;
    }
    else
    {
      f.F = d[now];
      f.S = now;
      s.F = cost;
      s.S = par;
    }
    for (auto [nx, cost] : t[now])
    {
      if (nx == par)
        continue;
      ll c = cost + k[nx];
      if (f.F < c)
      {
        s.F = f.F;
        s.S = f.S;
        f.F = c;
        f.S = nx;
      }
      else if (s.F < c)
      {
        s.F = c;
        s.S = nx;
      }
    }
    if (f.S == now)
    {
      ans[now] = s.F;
    }
    else
    {
      ans[now] = f.F;
    }
    for (auto [nx, cost] : t[now])
    {
      if (nx == par)
        continue;
      if (nx != f.S)
      {
        dfs2(dfs2, nx, f.F + cost, now);
      }
      else
      {
        dfs2(dfs2, nx, s.F + cost, now);
      }
    }
  };
  dfs2(dfs2, 0, 0);
  rep(i, n)
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
__builtin_popcount(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
