#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
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
int main()
{
  ll n;
  cin >> n;
  vvll t(n, vll(0));
  vll dist(n, -1);
  vvll distlist(n, vll(0));
  vector<ll> u(n - 1);
  vector<ll> v(n - 1);
  rep(i, n - 1)
  {
    cin >> u[i] >> v[i];
    u[i]--;
    v[i]--;
    t[u[i]].pb(v[i]);
    t[v[i]].pb(u[i]);
  }
  dist[0] = 0;
  queue<ll> que;
  que.push(0);
  while (que.size())
  {
    ll now = que.front();
    que.pop();
    for (auto p : t[now])
    {
      if (dist[p] == -1)
      {
        dist[p] = dist[now] + 1;
        que.push(p);
      }
    }
  }
  rep(i, n)
  {
    distlist[dist[i]].pb(i);
  }
  set<pll> s;
  rep(i, n)
  {
    rep(j, distlist[i].size())
    {
      ll now = distlist[i][j];
      for (int k = i + 1; k < n; k += 2)
      {
        rep(z, distlist[k].size())
        {
          ll to = distlist[k][z];
          s.insert(mp(min(now, to), max(now, to)));
        }
      }
    }
  }
  rep(i, n - 1)
  {
    s.erase(mp(min(u[i], v[i]), max(u[i], v[i])));
  }
  if (s.size() % 2)
  {
    cout << "First" << endl;
    auto p = s.begin();
    auto [x, y] = *p;
    cout << x + 1 << " " << y + 1 << endl;
    s.erase(p);
  }
  else
  {
    cout << "Second" << endl;
  }
  while (1)
  {
    ll i, j;
    cin >> i >> j;
    if (i == -1 && j == -1)
      break;
    s.erase(mp(i - 1, j - 1));
    auto p = s.begin();
    auto [x, y] = *p;
    cout << x + 1 << " " << y + 1 << endl;
    s.erase(p);
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
