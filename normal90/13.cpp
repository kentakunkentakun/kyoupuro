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
#define repR(i, n) for (ll i = n - 1; i >= 0; i--)
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
  ll to;
  ll cost;
};

void dikstra(ll s, vector<ll> &dist, vector<vector<edge>> &p)
{
  dist[s] = 0;
  PQR(pll)
  que;
  que.push(pll(0, s));
  while (que.size())
  {
    pll now = que.top();
    que.pop();
    for (auto e : p[now.S])
    {
      if (dist[e.to] <= e.cost + dist[now.S])
        continue;
      dist[e.to] = e.cost + dist[now.S];
      que.push(pll(dist[e.to], e.to));
    }
  }
  return;
}
int main()
{
  ll n, m;
  cin >> n >> m;
  vector<vector<edge>> p(n, vector<edge>(0));
  rep(i, m)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    p[a].pb(edge{b, c});
    p[b].pb(edge{a, c});
  }

  vector<ll> dist(n, INF);
  vector<ll> rdist(n, INF);

  dikstra(0, dist, p);
  dikstra(n - 1, rdist, p);

  rep(i, n)
  {
    cout << dist[i] + rdist[i] << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
