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
ll dp[100005][3];
char cc[100005];
ll dfs(int i, int c, int from, vector<vector<ll>> &a)
{
  if (dp[i][c] != -1)
    return dp[i][c];
  if (a[i].size() == 1 && a[i][0] == from)
  {
    if (c == (int)(cc[i] - 'a'))
    {
      return dp[i][c] = 1;
    }
    else
    {
      return dp[i][c] = 0;
    }
  }
  ll res = 1;
  for (auto p : a[i])
  {
    if (p == from)
      continue;
    if (c == 0)
    {
      if (cc[i] == 'a')
      {
        res *= (dfs(p, 0, i, a) + dfs(p, 2, i, a));
      }
      else
      {
        return dp[i][c] = 0;
      }
    }
    else if (c == 1)
    {
      if (cc[i] == 'b')
      {
        res *= (dfs(p, 1, i, a) + dfs(p, 2, i, a));
      }
      else
      {
        return dp[i][c] = 0;
      }
    }
    else
    {
      res *= (dfs(p, 0, i, a) + dfs(p, 1, i, a) + dfs(p, 2, i, a) * 2LL);
    }
    res %= MOD;
  }
  ll m = 1;
  if (c == 2)
  {
    for (auto p : a[i])
    {
      if (p == from)
        continue;
      if (cc[i] == 'a')
      {
        m *= (dfs(p, 0, i, a) + dfs(p, 2, i, a));
      }
      else
      {
        m *= (dfs(p, 1, i, a) + dfs(p, 2, i, a));
      }
      m %= MOD;
    }
    res -= m;
    if (res < 0)
      res += MOD;
  }
  return dp[i][c] = res;
}
int main()
{
  ll n;
  cin >> n;
  rep(i, n) cin >> cc[i];
  vector<vector<ll>> a(n, vector<ll>(0));
  rep(i, n - 1)
  {
    ll A, B;
    cin >> A >> B;
    A--;
    B--;
    a[A].pb(B);
    a[B].pb(A);
  }
  rep(i, 100005)
  {
    rep(j, 3)
    {
      dp[i][j] = -1;
    }
  }
  cout << dfs(0, 2, -1, a) << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
