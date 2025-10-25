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
const ll MOD = 998244353LL;
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
bool isBinaryPalindrome(long long n, ll k)
{
  if (k <= 0 || n < 0)
    return false;
  unsigned long long x = (unsigned long long)n;

  // k 桁に収まらないなら不適合（回文ではない扱い）
  if (k < 64 && (x >> k) != 0ULL)
    return false;

  int lo = 0, hi = k - 1;
  while (lo < hi)
  {
    if (((x >> lo) & 1ULL) != ((x >> hi) & 1ULL))
      return false;
    ++lo;
    --hi;
  }
  return true;
}
int main()
{
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vvll dp(n + 1, vll(1 << k, 0));
  vll ch(1 << k, 0);
  rep(i, 1 << k)
  {
    ch[i] = isBinaryPalindrome(i, k);
  }
  dp[0][0] = 1;
  rep(i, n)
  {
    rep(j, 1 << k)
    {
      if (s[i] == 'A' || s[i] == '?')
      {
        ll nx = j * 2;
        if (nx >= (1 << k))
        {
          nx -= (1 << k);
        }
        if (i < k - 1 || !ch[nx])
        {
          dp[i + 1][nx] += dp[i][j];
          dp[i + 1][nx] %= MOD;
        }
      }
      if (s[i] == 'B' || s[i] == '?')
      {
        ll nx = j * 2 + 1;
        if (nx >= (1 << k))
        {
          nx -= (1 << k);
        }
        if (i < k - 1 || !ch[nx])
        {
          dp[i + 1][nx] += dp[i][j];
          dp[i + 1][nx] %= MOD;
        }
      }
    }
  }
  ll ans = 0;
  rep(i, 1 << k)
  {
    if (!ch[i])
    {
      ans += dp[n][i];
      ans %= MOD;
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
