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
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n), b(n), c(n);
  rep(i, n)
  {
    cin >> a[i] >> b[i] >> c[i];
  }
  int m = (n + 1) / 2;
  map<pii, int> fi;
  map<pii, int> se;
  ll ans = INF;
  fi[mp(0, 0)] = 0;
  se[mp(0, 0)] = 0;
  if (n / 2 != 0)
  {
    for (int bit = 0; bit < (1 << n / 2); bit++)
    {
      pii p = mp(0, 0);
      int cost = 0;
      rep(i, n / 2)
      {
        if (bit & (1 << i))
        {
          p.F += a[i];
          p.S += b[i];
          cost += c[i];
        }
      }
      if (fi.count(p))
      {
        chmin(fi[p], cost);
      }
      else
      {
        fi[p] = cost;
      }
    }
  }
  for (int bit = 0; bit < (1 << m); bit++)
  {
    pii p = mp(0, 0);
    int cost = 0;
    rep(i, m)
    {
      if (bit & (1 << i))
      {
        p.F += a[n / 2 + i];
        p.S += b[n / 2 + i];
        cost += c[n / 2 + i];
      }
    }
    if (se.count(p))
      chmin(se[p], cost);
    else
    {
      se[p] = cost;
    }
  }

  for (auto p : se)
  {
    int mx = x;
    int my = y;
    while (mx <= n * 10 && my <= n * 10)
    {
      pii key = mp(mx - p.F.F, my - p.F.S);
      if (fi.count(key))
      {
        chmin(ans, p.S + (ll)fi[key]);
      }
      mx += x;
      my += y;
    }
  }
  if (ans == INF)
  {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
