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
int main()
{
  ll n;
  cin >> n;
  vvll t(n, vll(0));
  rep(i, n - 1)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    t[a].pb(b);
    t[b].pb(a);
  }
  ll q;
  cin >> q;
  vector<vector<pll>> query(n, vector<pll>(0));
  rep(i, q)
  {
    ll u, k;
    cin >> u >> k;
    u--;
    query[u].pb({k, i});
  }
  vll dist(n, 0);

  auto dfs = [&](auto dfs, ll now, ll par) -> void
  {
    for (auto nx : t[now])
    {
      if (par == nx)
        continue;
      dist[nx] = dist[now] + 1;
      dfs(dfs, nx, now);
    }
  };
  dfs(dfs, 0, -1);
  ll s = -1;
  ll ma = 0;
  rep(i, n)
  {
    if (chmax(ma, dist[i]))
    {
      s = i;
    }
  }
  rep(i, n) dist[i] = 0;
  dfs(dfs, s, -1);
  ll e = -1;
  ma = 0;
  rep(i, n)
  {
    if (chmax(ma, dist[i]))
    {
      e = i;
    }
  }
  vll right(0);
  auto dfs2 = [&](auto dfs2, ll now, ll par) -> bool
  {
    if (now == e)
    {
      right.pb(now);
      return true;
    }
    for (auto nx : t[now])
    {
      if (nx == par)
        continue;
      if (dfs2(dfs2, nx, now))
      {
        right.pb(now);
        return true;
      }
    }
    return false;
  };
  dfs2(dfs2, s, -1);
  vll ch(n, -1);

  rep(i, right.size())
  {
    ch[right[i]] = 1;
  }
  vll left(0);
  vll ans(q, -1);
  auto dfs3 = [&](auto dfs3, ll now, ll par) -> void
  {
    if (ch[now] == 1)
      right.pop_back();
    for (auto [k, it] : query[now])
    {
      if (left.size() >= k)
      {
        ans[it] = left[left.size() - k];
      }
      if (right.size() >= k)
      {
        ans[it] = right[right.size() - k];
      }
    }
    left.pb(now);
    right.pb(now);
    for (auto nx : t[now])
    {
      if (nx == par)
        continue;
      if (ch[nx] == 1)
      {
        right.pop_back();
        dfs3(dfs3, nx, now);
        right.push_back(now);
      }
      else
      {
        dfs3(dfs3, nx, now);
      }
    }
    left.pop_back();
    right.pop_back();
    if (ch[now] == 1)
    {
      right.push_back(now);
    }
  };
  dfs3(dfs3, s, -1);
  rep(i, q)
  {
    if (ans[i] != -1)
      ans[i]++;
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
