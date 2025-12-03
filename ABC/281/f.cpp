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
long long modpow(long long a, long long n, long long mod)
{
  a %= mod;
  long long res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}
int main()
{
  ll n;
  cin >> n;
  vll a(n);
  rep(i, n) cin >> a[i];
  sort(all(a));
  vvll t(n, vll(31));
  rep(i, n)
  {
    ll k = a[i];
    rep(j, 31)
    {
      t[i][j] = k % 2;
      k /= 2;
    }
  }
  auto dfs = [&](auto dfs, ll k, ll l, ll r) -> ll
  {
    if (k < 0)
    {
      return 0;
    }
    ll sw = -1;
    for (int i = l + 1; i < r; i++)
    {
      if (t[i][k] != t[i - 1][k])
      {
        sw = i;
        break;
      }
    }

    if (sw == -1)
    {
      return dfs(dfs, k - 1, l, r);
    }
    ll res = modpow(2, k, INF);
    return min(dfs(dfs, k - 1, l, sw) + res, dfs(dfs, k - 1, sw, r) + res);
  };
  cout << dfs(dfs, 30, 0, n) << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
