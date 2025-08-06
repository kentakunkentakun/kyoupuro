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
ll dp[100005][2];
ll dfs(ll i, ll c, vector<vector<int>> &d, ll f = -1)
{
  if (dp[i][c] != -1)
    return dp[i][c];
  ll res = 1;
  ll cnt = 0;
  for (auto p : d[i])
  {
    if (p != f)
    {
      cnt++;
      if (c)
      {
        res *= dfs(p, 0, d, i);
        res %= MOD;
      }
      else
      {
        res *= dfs(p, 0, d, i) + dfs(p, 1, d, i);
        res %= MOD;
      }
    }
  }
  if (res < 0)
    res += MOD;
  return dp[i][c] = res;
}
int main()
{
  ll n;
  cin >> n;
  vector<vector<int>> d(n, vector<int>(0));
  rep(i, n - 1)
  {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    d[x].pb(y);
    d[y].pb(x);
  }
  rep(i, 100005) rep(j, 2) dp[i][j] = -1;
  cout << (dfs(0, 0, d) + dfs(0, 1, d)) % MOD << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
