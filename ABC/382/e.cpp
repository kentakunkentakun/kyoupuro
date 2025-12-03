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
  cout << fixed << setprecision(10);

  ll n, x;
  cin >> n >> x;
  vector<double> p(n);
  rep(i, n) cin >> p[i];

  vector<vector<double>> t(n + 1, vector<double>(n + 1, 0));
  t[0][0] = 1;
  rep(i, n)
  {
    rep(j, n + 1)
    {
      if (t[i][j] == 0)
        continue;
      t[i + 1][j + 1] += t[i][j] * p[i] / 100;
      t[i + 1][j] += t[i][j] * (100 - p[i]) / 100;
    }
  }
  vector<double> prob(min(x + 1, n + 1));
  rep(i, n + 1)
  {
    if (i <= x)
      prob[i] = t[n][i];
    else
      prob[x] += t[n][i];
  }
  vector<double> dp(x + 1, -1);
  auto dfs = [&](auto dfs, int remain) -> double
  {
    if (remain == 0)
    {
      return dp[remain] = 0.0;
    }
    if (remain < 0)
    {
      return 0.0;
    }
    if (dp[remain] != -1)
      return dp[remain];
    double k = 1.0 / (1 - prob[0]);
    rep(i, prob.size())
    {
      if (i == 0)
        continue;
      k += prob[i] * (dfs(dfs, remain - i)) * 1.0 / (1 - prob[0]);
    }
    return dp[remain] = k;
  };
  cout << dfs(dfs, x) << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
