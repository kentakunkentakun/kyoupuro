#include <bits/stdc++.h>
#include <atcoder/all>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORR(i, a, b) for (ll i = (a); i <= (b); i++)
#define repR(i, n) for (ll i = n; i >= 0; i--)
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
  ll from;
  ll to;
  ll cost;
};

int main()
{
  ll n, m;
  cin >> n >> m;
  vector<ll> d(n, INF);
  vector<edge> e(m);
  vector<edge> ee(m);
  vector<vector<edge>> maze(n, vector<edge>(0));
  vector<vector<edge>> maze2(n, vector<edge>(0));
  d[0] = 0;
  rep(i, m)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    e[i] = edge{a, b, -c};
    ee[i] = edge{b, a, -c};
    maze[a].pb(edge{a, b, -c});
    maze2[b].pb(edge{b, a, -c});
  }
  vector<bool> ch(n, false);
  vector<bool> ch2(n, false);
  ch[0] = true;
  queue<ll> que;
  que.push(0);
  while (que.size())
  {
    ll now = que.front();
    que.pop();

    for (auto p : maze[now])
    {
      if (!ch[p.to])
      {
        ch[p.to] = true;
        que.push(p.to);
      }
    }
  }
  ch2[n - 1] = true;
  que.push(n - 1);
  while (que.size())
  {
    ll now = que.front();
    que.pop();

    for (auto p : maze2[now])
    {
      if (!ch2[p.to])
      {
        ch2[p.to] = true;
        que.push(p.to);
      }
    }
  }

  rep(i, n)
  {
    ch[i] = ch[i] && ch2[i];
  }

  for (ll j = 0; j < n; j++)
  {
    for (ll i = 0; i < m; i++)
    {
      edge ed = e[i];
      if (ch[ed.to] && d[ed.from] != INF && d[ed.to] > d[ed.from] + ed.cost)
      {
        d[ed.to] = d[ed.from] + ed.cost;
        if (j == n - 1)
        {
          cout << "inf" << endl;
          return 0;
        }
      }
    }
  }
  cout << -1 * d[n - 1] << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
