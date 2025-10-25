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
  ll n;
  cin >> n;
  map<ll, ll> y_sum;
  map<ll, ll> x_sum;
  map<pll, ll> z;
  map<ll, vll> xs;
  rep(i, n)
  {
    ll r, c, x;
    cin >> r >> c >> x;
    y_sum[r] += x;
    xs[c].pb(r);
    // if (xs.count(c))
    // {
    //   xs[c].pb(r);
    // }
    // else
    // {
    //   xs[c] = {r};
    // }
    x_sum[c] += x;
    z[pll(r, c)] = x;
  }
  multiset<ll> y_s;
  for (auto p : y_sum)
  {
    y_s.insert(p.S);
  }
  y_s.insert(0);

  ll ans = 0;
  for (auto p : xs)
  {

    ll tmpMax = 0;
    vll tmp(0);
    ll y = p.F;
    for (auto x : p.S)
    {
      tmp.pb(y_sum[x]);
      y_s.erase(y_s.find(y_sum[x]));

      chmax(tmpMax, x_sum[y] + y_sum[x] - z[pll(x, y)]);
    }

    // y_sに0を入れてるからsizeが空にならない。
    ll ma = *y_s.rbegin();
    chmax(tmpMax, ma + x_sum[y]);
    chmax(ans, tmpMax);
    for (auto x : tmp)
    {
      y_s.insert(x);
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
