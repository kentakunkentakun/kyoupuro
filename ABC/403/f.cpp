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
using vvvll = vector<vvll>;
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
  string ini = "";
  rep(i, n * 2 + 1)
  {
    ini += '$';
  }
  vector<vector<string>> dp(2001, vector<string>(2, ini));
  dp[1][0] = "1";
  dp[1][1] = "1";
  dp[11][0] = "11";
  dp[11][1] = "11";
  dp[111][0] = "111";
  dp[111][1] = "111";
  dp[1111][0] = "1111";
  dp[1111][1] = "1111";
  // 0 = 積 1 = 和
  for (int i = 2; i <= n; i++)
  {
    for (int j = 1; j < i; j++)
    {
      if (i % j == 0 && j != 1)
      {
        if (dp[i][0].size() > dp[i / j][0].size() + dp[j][0].size() + 1)
        {
          dp[i][0] = dp[i / j][0] + '*' + dp[j][0];
        }
        if (dp[i][0].size() > dp[i / j][0].size() + dp[j][1].size() + 3)
        {
          dp[i][0] = dp[i / j][0] + "*(" + dp[j][1] + ')';
        }
        if (dp[i][0].size() > dp[i / j][1].size() + dp[j][0].size() + 3)
        {
          dp[i][0] = '(' + dp[i / j][1] + ")*" + dp[j][0];
        }
        if (dp[i][0].size() > dp[i / j][1].size() + dp[j][1].size() + 5)
        {
          dp[i][0] = '(' + dp[i / j][1] + ")*(" + dp[j][1] + ')';
        }
      }
      ll l = i - j;
      ll r = j;

      if (dp[i][1].size() > dp[l][0].size() + dp[r][0].size() + 1)
      {
        dp[i][1] = dp[l][0] + '+' + dp[r][0];
      }
      if (dp[i][1].size() > dp[l][1].size() + dp[r][0].size() + 1)
      {
        dp[i][1] = dp[l][1] + '+' + dp[r][0];
      }
      if (dp[i][1].size() > dp[l][0].size() + dp[r][1].size() + 1)
      {
        dp[i][1] = dp[l][0] + '+' + dp[r][1];
      }
      if (dp[i][1].size() > dp[l][1].size() + dp[r][1].size() + 1)
      {
        dp[i][1] = dp[l][1] + '+' + dp[r][1];
      }
    }
  }
  if (dp[n][0].size() < dp[n][1].size())
  {
    cout << dp[n][0] << endl;
  }
  else
  {
    cout << dp[n][1] << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
