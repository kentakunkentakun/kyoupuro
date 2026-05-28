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
// 木の直径（辺数）、直径の両端点、木の中心を返す
// 戻り値: {diameter_len, u, v, centers}
// centers は 0-index、要素数は 1 または 2
tuple<ll, ll, ll, vector<ll>> tree_diameter_and_centers(const vector<vector<ll>> &g)
{
  ll n = (ll)g.size();

  auto bfs_far = [&](ll s) -> pair<ll, ll>
  {
    vector<ll> dist(n, -1);
    queue<ll> q;
    dist[s] = 0;
    q.push(s);

    ll far = s;
    while (!q.empty())
    {
      ll u = q.front();
      q.pop();

      if (dist[u] > dist[far])
        far = u;

      for (ll v : g[u])
      {
        if (dist[v] == -1)
        {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }

    return {far, dist[far]};
  };

  auto bfs_parent = [&](ll s) -> pair<vector<ll>, vector<ll>>
  {
    vector<ll> dist(n, -1), par(n, -1);
    queue<ll> q;
    dist[s] = 0;
    q.push(s);

    while (!q.empty())
    {
      ll u = q.front();
      q.pop();

      for (ll v : g[u])
      {
        if (dist[v] == -1)
        {
          dist[v] = dist[u] + 1;
          par[v] = u;
          q.push(v);
        }
      }
    }

    return {dist, par};
  };

  if (n == 1)
  {
    return {0, 0, 0, vector<ll>{0}};
  }

  auto [a, _da] = bfs_far(0);
  auto [dist, par] = bfs_parent(a);

  ll b = a;
  rep(i, n)
  {
    if (dist[i] > dist[b])
      b = i;
  }

  ll diam = dist[b];

  // a -> b の直径パスを復元
  vector<ll> path;
  ll cur = b;
  while (cur != -1)
  {
    path.push_back(cur);
    if (cur == a)
      break;
    cur = par[cur];
  }
  reverse(all(path));

  vector<ll> centers;

  if (diam % 2 == 0)
  {
    centers.push_back(path[diam / 2]);
  }
  else
  {
    centers.push_back(path[diam / 2]);
    centers.push_back(path[diam / 2 + 1]);
  }

  return {diam, a, b, centers};
}

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
  auto [len, _, __, v] = tree_diameter_and_centers(t);
  if (len % 2)
  {
    ll l = len / 2;
    ll ans = 1;
    rep(i, v.size())
    {
      queue<ll> que;
      que.push(v[i]);
      vll dist(n, -1);
      dist[v[i]] = 0;
      auto dfs = [&](auto dfs, ll now, ll par) -> ll
      {
        if (now == v[1 - i])
        {
          return 0;
        }
        if (dist[now] == l)
        {
          return 1;
        }
        ll res = 0;
        for (auto nx : t[now])
        {
          if (nx != par)
          {
            dist[nx] = dist[now] + 1;
            res += dfs(dfs, nx, now);
          }
        }
        if (now == v[1 - i])
        {
          return 0;
        }
        return res;
      };
      ans *= dfs(dfs, v[i], -1);
      ans %= MOD;
    }
    cout << ans << endl;
  }
  else
  {
    ll l = len / 2;
    vll dist(n, -1);
    dist[v[0]] = 0;
    vll tmp(0);
    auto dfs = [&](auto dfs, ll now, ll par) -> ll
    {
      if (dist[now] == l)
      {
        return 1;
      }
      ll res = 0;
      for (auto nx : t[now])
      {
        if (nx == par)
          continue;
        dist[nx] = dist[now] + 1;
        if (now == v[0])
        {
          ll cnt = dfs(dfs, nx, now);
          if (cnt != 0)
            tmp.pb(dfs(dfs, nx, now));
        }
        else if (nx != par)
        {
          res += dfs(dfs, nx, now);
        }
      }
      return res;
    };
    dfs(dfs, v[0], -1);
    ll ans = 1;
    rep(i, tmp.size())
    {
      ans *= (1 + tmp[i]);
      ans %= MOD;
    }
    rep(i, tmp.size())
    {
      ans -= tmp[i];
      ans %= MOD;
    }
    ans--;
    ans += MOD;
    ans %= MOD;
    cout << ans << endl;
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
