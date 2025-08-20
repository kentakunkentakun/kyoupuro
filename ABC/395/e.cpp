#include <bits/stdc++.h>
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
  ll n, m, x;
  cin >> n >> m >> x;
  vvll t(n, vll(0));
  vvll t2(n, vll(0));
  vvll dist(n, vll(2, INF));
  rep(i, m)
  {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    t[u].pb(v);
    t2[v].pb(u);
  }
  dist[0][0] = 0;
  priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> que;
  que.push({dist[0][0], 0, 0});
  while (que.size())
  {
    auto now = que.top();
    que.pop();
    ll point = get<1>(now);
    ll dis = get<0>(now);
    ll is_x = get<2>(now);
    if (dis != dist[point][is_x])
      continue;
    for (auto p : t[point])
    {
      if (is_x)
      {
        if (chmin(dist[p][0], dist[point][1] + 1 + x))
        {
          que.push({dist[p][0], p, 0});
        }
      }
      else
      {
        if (chmin(dist[p][0], dist[point][0] + 1))
        {
          que.push({dist[p][0], p, 0});
        }
      }
    }
    for (auto p : t2[point])
    {
      if (is_x)
      {
        if (chmin(dist[p][1], dist[point][1] + 1))
        {
          que.push({dist[p][1], p, 1});
        }
      }
      else
      {
        if (chmin(dist[p][1], dist[point][0] + x + 1))
        {
          que.push({dist[p][1], p, 1});
        }
      }
    }
  }
  cout << min(dist[n - 1][0], dist[n - 1][1]) << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
