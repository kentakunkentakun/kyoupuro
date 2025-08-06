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
pll dp[55][55];
int main()
{
  ll n, a, b;
  cin >> n >> a >> b;
  cout << fixed << setprecision(10);

  rep(i, 55) rep(j, 55) dp[i][j] = pll(-1, 0);
  dp[0][0] = pll(0, 1);
  vector<ll> v(n);
  rep(i, n) cin >> v[i];
  rep(i, n)
  {
    rep(j, n)
    {
      if (dp[i][j].S)
      {
        if (dp[i + 1][j + 1].first < dp[i][j].first + v[i])
        {
          dp[i + 1][j + 1].first = dp[i][j].first + v[i];
          dp[i + 1][j + 1].second = dp[i][j].second;
        }
        else if (dp[i + 1][j + 1].first == dp[i][j].first + v[i])
        {
          dp[i + 1][j + 1].second += dp[i][j].second;
        }
        if (dp[i + 1][j].first < dp[i][j].first)
        {
          dp[i + 1][j].first = dp[i][j].first;
          dp[i + 1][j].second = dp[i][j].second;
        }
        else if (dp[i + 1][j].first == dp[i][j].first)
        {
          dp[i + 1][j].second += dp[i][j].second;
        }
      }
    }
  }
  double ansValue = 0;
  pll ansPair = pll(0, 1);
  ll ansCount = 0;
  for (int i = a; i <= b; i++)
  {
    if (dp[n][i].F * ansPair.S > ansPair.F * i)
    {
      ansValue = (double)dp[n][i].F / i;
      ansCount = dp[n][i].S;
      ansPair = pll(dp[n][i].F, i);
    }
    else if (dp[n][i].F * ansPair.S == ansPair.F * i)
    {
      ansCount += dp[n][i].S;
    }
  }
  cout << ansValue << endl;
  cout << ansCount << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
