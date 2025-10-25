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
  ll n, k;
  cin >> n >> k;
  vll x(n), y(n);
  rep(i, n)
  {
    cin >> x[i] >> y[i];
  }
  vvll d(n, vll(n, INF));
  rep(i, n)
  {
    rep(j, n)
    {
      d[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
    }
  }
  vll cost(1 << n, 0);
  for (int bit = 1; bit < (1 << n); bit++)
  {
    rep(i, n)
    {
      for (int j = 0; j < i; j++)
      {
        if (bit & (1 << i) && bit & (1 << j))
        {
          chmax(cost[bit], d[i][j]);
        }
      }
    }
  }
  vvll dp(k + 1, vll(1 << n, INF));
  dp[0][0] = 0LL;
  for (int i = 1; i <= k; i++)
  {
    for (int bit = 1; bit < (1 << n); bit++)
    {
      for (int b = bit; b != 0; b = (b - 1) & bit)
      {
        chmin(dp[i][bit], max(dp[i - 1][bit - b], cost[b]));
      }
    }
  }
  cout << dp[k][(1 << n) - 1] << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
