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
bool is_out(ll nx, ll ny, ll h, ll w)
{
  if (nx >= 0 && nx < h && ny >= 0 && ny < w)
  {
    return true;
  }
  return false;
}
int main()
{
  ll h, w, t;
  cin >> h >> w >> t;
  vector<pll> p(0);
  pll s, g;

  vector<vector<char>> a(h, vector<char>(w));
  rep(i, h)
  {
    rep(j, w)
    {
      cin >> a[i][j];
      if (a[i][j] == 'S')
        s = pll(i, j);
      if (a[i][j] == 'G')
        g = pll(i, j);
      if (a[i][j] == 'o')
      {
        p.pb(pll(i, j));
      }
    }
  }
  p.insert(p.begin(), s);
  // p.pb(g);
  ll n = p.size();

  auto culc = [&](vvll &tmp, pll from) -> void
  {
    queue<pll> que;
    que.push(from);
    tmp[from.F][from.S] = 0;
    while (que.size())
    {
      pll now = que.front();
      que.pop();
      rep(i, 4)
      {
        ll nx = now.F + dx[i];
        ll ny = now.S + dy[i];
        if (is_out(nx, ny, h, w) && tmp[nx][ny] == INF && a[nx][ny] != '#')
        {
          tmp[nx][ny] = tmp[now.F][now.S] + 1;
          que.push(pll(nx, ny));
        }
      }
    }
  };
  vvll dist(n, vll(n, INF));
  rep(i, n - 1)
  {
    vvll tmp(h, vll(w, INF));
    culc(tmp, p[i]);

    for (ll j = i + 1; j < n; j++)
    {
      dist[i][j] = tmp[p[j].F][p[j].S];
      dist[j][i] = tmp[p[j].F][p[j].S];
    }
  }
  vvll dp(1 << n, vll(n, -1));
  auto dfs = [&](auto dfs, ll mask, ll now) -> ll
  {
    if (dp[mask][now] != -1)
      return dp[mask][now];
    if (mask == (1 << now))
      return dp[mask][now] = (now == 0 ? 0 : INF);
    ll res = INF;
    int prevMask = mask & ~(1 << now);

    rep(i, n)
    {
      if (prevMask >> i & 1)
      {
        ll cand = dfs(dfs, prevMask, i) + dist[now][i];
        chmin(res, cand);
      }
    }
    return dp[mask][now] = res;
  };
  rep(i, n)
  {
    dfs(dfs, (1 << n) - 1, i);
  }
  ll best = -1;

  // gまでの距離
  vvll toG(h, vll(w, INF));
  culc(toG, g);
  rep(mask, 1 << n)
  {
    if (!(mask & 1))
      continue;
    ll res = INF;
    rep(i, n)
    {
      if (mask & (1 << i) && (dp[mask][i] + toG[p[i].F][p[i].S]))
      {
        chmin(res, dp[mask][i] + toG[p[i].F][p[i].S]);
      }
    }
    if (res <= t)
    {
      chmax(best, (ll)__builtin_popcount(mask) - 1);
    }
  }

  cout << best << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/
