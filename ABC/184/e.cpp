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
struct edge
{
  ll to, cost;
};
int main()
{
  ll h, w;
  cin >> h >> w;
  pll s, g;
  vector<vector<char>> a(h, vector<char>(w));
  vector<vector<edge>> t(h * w + 26, vector<edge>(0));
  map<char, vll> m;
  rep(i, h)
  {
    rep(j, w)
    {
      cin >> a[i][j];
      if (a[i][j] == 'S')
        s = {i, j};
      else if (a[i][j] == 'G')
        g = {i, j};
      else if (a[i][j] != '.' && a[i][j] != '#')
      {
        m[a[i][j]].pb(i * w + j);
      }
    }
  }
  rep(i, h)
  {
    rep(j, w)
    {
      if (a[i][j] == '#')
        continue;
      ll now = i * w + j;
      rep(z, 4)
      {
        ll nx = dx[z] + i;
        ll ny = dy[z] + j;
        if (nx >= 0 && nx < h && ny >= 0 && ny < w && a[nx][ny] != '#')
        {
          t[now].pb({nx * w + ny, 1});
        }
      }
    }
  }
  for (auto [p, v] : m)
  {
    rep(i, v.size())
    {
      t[h * w + (p - 'a')].pb({v[i], 1});
      t[v[i]].pb({h * w + (p - 'a'), 0});
    }
  }
  vll dist(h * w + 26, INF);
  dist[s.first * w + s.second] = 0;
  PQR(pll)
  que;
  que.push({0, s.F * w + s.S});
  while (que.size())
  {
    auto [d, now] = que.top();
    que.pop();
    if (dist[now] < d)
    {
      continue;
    }
    for (auto next : t[now])
    {
      if (dist[next.to] > d + next.cost)
      {
        dist[next.to] = d + next.cost;
        que.push({d + next.cost, next.to});
      }
    }
  }
  if (dist[g.F * w + g.S] == INF)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << dist[g.F * w + g.S] << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
