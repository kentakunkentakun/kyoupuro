#include <bits/stdc++.h>

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
int main()
{
  ll n, x;
  cin >> n >> x;
  vector<double> s(n), c(n), p(n);
  rep(i, n)
  {
    cin >> s[i] >> c[i] >> p[i];
  }
  vector<vector<double>> dp(1 << n, vector<double>(5005, -10e9));
  ll al = 0;
  rep(i, n)
  {
    al += s[i];
  }
  auto dfs = [&](auto dfs, ll now, ll cost) -> double
  {
    if (dp[now][cost] != -10e9)
    {
      return dp[now][cost];
    }
    if (now == (1 << n) - 1)
    {
      return dp[now][cost] = al;
    }
    double tmp = 0;
    double next = -10e9;
    rep(i, n)
    {
      if (now >> i & 1)
      {
        tmp += s[i];
      }
      else
      {
        if (cost + c[i] <= x)
          chmax(next, dfs(dfs, now, cost + c[i]) * p[i] / 100.0 + dfs(dfs, now | 1 << i, cost + c[i]) * (100 - p[i]) / 100.0 + s[i]);
      }
    }
    return dp[now][cost] = max(tmp, next);
  };
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
