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
int main()
{
  ll n, m;
  cin >> n >> m;
  vector<string> s(n);
  vvll t(n, vll(0));
  vvll rt(n, vll(0));
  rep(i, n)
  {
    cin >> s[i];
    rep(j, m)
    {
      if (s[i][j] == '1')
      {
        t[i].pb(i + j + 1);
        rt[i + j + 1].pb(i);
      }
    }
  }
  vll rdist(n, INF);
  queue<ll> que;
  que.push(n - 1);
  rdist[n - 1] = 0;
  while (que.size())
  {
    ll now = que.front();
    que.pop();
    for (auto p : rt[now])
    {
      if (chmin(rdist[p], rdist[now] + 1))
      {
        que.push(p);
      }
    }
  }
  vll dist(n, INF);
  que.push(0);
  dist[0] = 0;
  while (que.size())
  {
    ll now = que.front();
    que.pop();
    for (auto p : t[now])
    {
      if (chmin(dist[p], dist[now] + 1))
      {
        que.push(p);
      }
    }
  }
  vll ans(0);
  for (ll i = 1; i < n - 1; i++)
  {
    ll res = INF;
    for (ll j = max(0LL, i - m + 1); j < i; j++)
    {
      for (ll z = j + 1; z <= min(j + m, n - 1); z++)
      {
        if (z > i)
        {
          if (s[j][z - j - 1] == '1')
          {
            chmin(res, dist[j] + rdist[z] + 1);
          }
        }
      }
    }
    if (res == INF)
    {
      ans.pb(-1);
    }
    else
    {
      ans.pb(res);
    }
  }
  rep(i, ans.size())
  {
    cout << ans[i] << " ";
  }
  cout << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
