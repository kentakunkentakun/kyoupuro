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
int main()
{
  ll t;
  cin >> t;
  vll ans(0);
  rep(T, t)
  {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vvll dp(n + 1, vll(3, INF));
    // 0 = これまで0
    // 1 = いま1
    // 0 = これ以降0
    dp[0][0] = 0;
    rep(i, n)
    {
      if (s[i] == '1')
      {
        chmin(dp[i + 1][0], dp[i][0] + 1);
        chmin(dp[i + 1][1], dp[i][0]);
        chmin(dp[i + 1][1], dp[i][1]);
        chmin(dp[i + 1][2], dp[i][1] + 1);
        chmin(dp[i + 1][2], dp[i][2] + 1);
      }
      else
      {
        chmin(dp[i + 1][0], dp[i][0]);
        chmin(dp[i + 1][1], dp[i + 1][0] + 1);
        chmin(dp[i + 1][1], dp[i][1] + 1);
        chmin(dp[i + 1][2], dp[i][1]);
        chmin(dp[i + 1][2], dp[i][2]);
      }
    }
    ans.pb(min(dp[n][0], min(dp[n][1], dp[n][2])));
  }
  rep(i, t)
  {
    cout << ans[i] << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
