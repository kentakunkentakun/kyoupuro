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
ll calc(vvll &t, vll &d)
{
  ll n = t.size();
  vll dd(n, INF);
  dd[0] = 0;
  ll u = 0;
  ll s = 0;
  queue<ll> que;
  que.push(0);
  while (que.size())
  {
    ll now = que.front();
    que.pop();

    for (auto nx : t[now])
    {
      if (dd[nx] == INF)
      {
        dd[nx] = dd[now] + 1;
        if (chmax(u, dd[nx]))
        {
          s = nx;
        }
        que.push(nx);
      }
    }
  }

  vll dist(n, INF);
  que.push(s);
  vb used(n);
  used[s] = true;
  dist[s] = 0;
  ll e = 0;
  ll mad = 0;
  while (que.size())
  {
    ll now = que.front();
    que.pop();
    for (auto nx : t[now])
    {
      if (!used[nx])
      {
        used[nx] = true;
        dist[nx] = dist[now] + 1;
        if (chmax(mad, dist[nx]))
        {
          e = nx;
        }
        que.push(nx);
      }
    }
  }
  que.push(e);
  rep(i, n) used[i] = false;
  used[e] = true;
  vll dist2(n, 0);
  while (que.size())
  {
    ll now = que.front();
    que.pop();
    for (auto nx : t[now])
    {
      if (!used[nx])
      {
        used[nx] = true;
        dist2[nx] = dist2[now] + 1;
        que.push(nx);
      }
    }
  }
  rep(i, n)
  {
    d[i] = max(dist[i], dist2[i]);
  }
  return mad;
}

int main()
{
  ll n;
  cin >> n;
  vvll t(n, vll(0));
  rep(i, n - 1)
  {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    t[u].pb(v);
    t[v].pb(u);
  }
  ll m;
  cin >> m;
  vvll t1(m, vll(0));
  rep(i, m - 1)
  {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    t1[u].pb(v);
    t1[v].pb(u);
  }
  vll d(n);
  vll d1(m);
  ll k = calc(t, d);
  ll k1 = calc(t1, d1);
  ll mak = max(k, k1);
  vll cnt(max(n, m) + 1);
  vll dd(max(n, m) + 1);
  rep(i, n)
  {
    dd[d[i]] += d[i];
    cnt[d[i]]++;
  }
  rep(i, max(n, m))

  {
    dd[i + 1] += dd[i];
    cnt[i + 1] += cnt[i];
  }
  ll ans = 0;
  rep(i, m)
  {
    ans += cnt[max(mak - d1[i] - 1, 0LL)] * mak;
    ans += (cnt[max(n, m)] - cnt[max(mak - d1[i] - 1, 0LL)]) * (d1[i] + 1) + dd[max(n, m)] - dd[max(mak - d1[i] - 1, 0LL)];
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
